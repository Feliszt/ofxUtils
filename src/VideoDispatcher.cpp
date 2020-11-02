#include "VideoDispatcher.h"

//--------------------------------------------------------------
// Constructor
//--------------------------------------------------------------
VideoDispatcher::VideoDispatcher()
{
	numPlayerPerVideo = 1;
}

//--------------------------------------------------------------
// Constructor
//--------------------------------------------------------------
VideoDispatcher::VideoDispatcher(int _numPlayerPerVideo)
{
	// copy data
	numPlayerPerVideo = _numPlayerPerVideo;
}

//--------------------------------------------------------------
// Adds a video to dispatcher
//--------------------------------------------------------------
void VideoDispatcher::addVideo(string _videoPath)
{
	addVideo(_videoPath, numPlayerPerVideo);
}

//--------------------------------------------------------------
// Adds a video to dispatcher
//--------------------------------------------------------------
void VideoDispatcher::addVideo(string _videoPath, int _numPlayer)
{
	// setup video instance
	videoInstance videoTemp;

	// get name, folder and extension of file	
	// folder
	auto s_temp = split(_videoPath, "/");
	string fileAndExt = s_temp[s_temp.size() - 1];		// extension
	s_temp.erase(s_temp.begin() + s_temp.size() - 1);
	string videoFolder = join(s_temp, "/") + "/";
	// name
	s_temp = split(fileAndExt, ".");
	string videoExt = s_temp[s_temp.size() - 1];
	s_temp.erase(s_temp.begin() + s_temp.size() - 1);
	string videoName = join(s_temp, ".");

	//
	videoTemp.videoPath = _videoPath;
	videoTemp.videoFolder = videoFolder;
	videoTemp.videoName = videoName;
	videoTemp.videoExt = videoExt;

	//
	maxSizeName = max(maxSizeName, int(videoName.size() * 8));

	// get info and populate video instance
	for (int i = 0; i < _numPlayer; i++) {
		// load videoplayer and add it to list
		ofVideoPlayer* videoPlayerTemp = new ofVideoPlayer();
		videoPlayerTemp->load(_videoPath);
		videoTemp.videoPlayers.push_back(videoPlayerTemp);

		// set playing state
		videoTemp.videoPlaying.push_back(false);

		// get video size if first pass
		if (i == 0) {
			videoTemp.videoWidth = videoPlayerTemp->getWidth();
			videoTemp.videoHeight = videoPlayerTemp->getHeight();
		}

		// debug
		ofLog() << "[VideoDispatcher]\tLoading instance #" << (i + 1) << " of video [" << _videoPath << "].";
	}

	// add it to videos of dispatcher
	videos.push_back(videoTemp);
}

//--------------------------------------------------------------
// Update method
//--------------------------------------------------------------
void VideoDispatcher::update()
{
	// check all playing videos for their states
	vector<int> instancesToDelete;
	for (int i = 0; i < videoPlayerInstances.size(); i++) {
		if (!videoPlayerInstances[i].isMediaDone()) {
			videoPlayerInstances[i].draw();
		}
		else {
			instancesToDelete.push_back(i);
		}
	}

	for (int i = 0; i < instancesToDelete.size(); i++) {
		// if media is done playing, we register it and remove it from list
		int id = instancesToDelete[i];
		videos[videoPlayerInstances[id].getMediaId()].videoPlaying[videoPlayerInstances[id].getMediaIdNum()] = false;
		videoPlayerInstances.erase(videoPlayerInstances.begin() + id);
	}
}

//--------------------------------------------------------------
// Plays a video
//--------------------------------------------------------------
void VideoDispatcher::play(string _videoPath, ofVec2f _videoPos, int _videoLoops)
{	
	// get index from path
	int videoInd = videoPathToInd(_videoPath);
	if (videoInd == -1) return;
	
	// pass it
	play(videoInd, _videoPos, _videoLoops);
}



//--------------------------------------------------------------
// Plays a video
//--------------------------------------------------------------
void VideoDispatcher::play(int _videoInd, ofVec2f _videoPos, int _videoLoops)
{
	// check input
	if (_videoInd < 0 || _videoInd >= videos.size()) {
		ofLog() << "[VideoDispatcher-play]\tIndex [" << _videoInd << "] out of bounds.";
		return;
	}

	// loop through all instances of video players for this video to check if one is available
	bool foundPlayer = false;
	for (int i = 0; i < videos[_videoInd].videoPlayers.size(); i++) {
		// check if each instance is playing
		// if not start it
		if (!videos[_videoInd].videoPlaying[i]) {
			foundPlayer = true;
			videos[_videoInd].videoPlaying[i] = true;
			VideoPlayerInstance videoPlayerTemp = VideoPlayerInstance(videos[_videoInd].videoPlayers[i], _videoPos, _videoLoops, _videoInd, i);
			videoPlayerInstances.push_back(videoPlayerTemp);
			break;
		}
	}

	// debug
	if (foundPlayer) {
		ofLog() << "Playing video [" << videos[_videoInd].videoName << "] of size (" << videos[_videoInd].videoWidth << ", " << videos[_videoInd].videoHeight << ") at pos (" << _videoPos.x << ", " << _videoPos.y << ").";
	}
}

//--------------------------------------------------------------
// Draw debug
//--------------------------------------------------------------
void VideoDispatcher::drawDebug(int _poxX, int _posY)
{
	int posY = _posY;
	for (int i = 0; i < videos.size(); i++) {
		int posX = _poxX;
		ofDrawBitmapStringHighlight(videos[i].videoName, posX, posY + 11);
		posX += maxSizeName + 10;
		for (int j = 0; j < videos[i].videoPlayers.size(); j++) {
			ofColor c = videos[i].videoPlaying[j] ? ofColor::green : ofColor::black;
			ofSetColor(c);
			ofDrawRectangle(posX, posY, 10, 10);
			posX += 20;
		}
		posY += 20;
	}
}

//--------------------------------------------------------------
// Getter for number of videos
//--------------------------------------------------------------
int VideoDispatcher::getNumVideos()
{
	return videos.size();
}

//--------------------------------------------------------------
// Getter for number of videos currently playing
//--------------------------------------------------------------
int VideoDispatcher::getNumVideosPlaying()
{
	return videoPlayerInstances.size();
}

//--------------------------------------------------------------
// Getter for info on specific video
//--------------------------------------------------------------
ofVec2f VideoDispatcher::getVideoSize(string _videoPath)
{
	// get index from path
	int videoInd = videoPathToInd(_videoPath);
	if (videoInd == -1) return ofVec2f();

	// pass it
	return getVideoSize(videoInd);
}

//--------------------------------------------------------------
// Getter for info on specific video
//--------------------------------------------------------------
ofVec2f VideoDispatcher::getVideoSize(int _videoInd)
{
	// fetch info in array
	return ofVec2f(videos[_videoInd].videoWidth, videos[_videoInd].videoHeight);
}



//--------------------------------------------------------------
// Getter for number of videos currently playing
//--------------------------------------------------------------
int VideoDispatcher::videoPathToInd(string _videoPath)
{
	// find video index in array from name
	for (int i = 0; i < videos.size(); i++) {
		if (strcmp(videos[i].videoName.c_str(), _videoPath.c_str()) == 0) {
			return i;
		}
	}
	ofLog() << "[VideoDispatcher]\tCan't locate [" << _videoPath << "].";
	return -1;
}
