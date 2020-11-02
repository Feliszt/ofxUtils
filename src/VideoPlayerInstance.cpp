#include "VideoPlayerInstance.h"

// constructors
VideoPlayerInstance::VideoPlayerInstance()
{
}

VideoPlayerInstance::VideoPlayerInstance(ofVideoPlayer* _mediaPlayer, ofVec2f _winPos, int _loopTot, int _mediaId, int _mediaIdNum)
{
	// copy data
	mediaPlayer		= _mediaPlayer;
	winPos			= _winPos;
	loopTot			= _loopTot;
	mediaId			= _mediaId;
	mediaIdNum		= _mediaIdNum;

	// load media file and init loopCount
	mediaPlayer->play();
	loopCount		= 0;
	mediaDone		= false;
	prevFrame		= 0;
	// init media and window information
	winBorder		= 1;
	pBH				= 15;
	pBO				= 4;
	pBRR			= 10;
	mediaSize		= ofVec2f(mediaPlayer->getWidth(), mediaPlayer->getHeight());
	winSize			= mediaSize + ofVec2f(2 * winBorder, 2 * winBorder + pBH);
	// init fbo
	mediaFbo.allocate(winSize.x, winSize.y, GL_RGBA);
	mediaFbo.begin();
	ofClear(0);
	mediaFbo.end();
	
}

// draw method
void VideoPlayerInstance::draw() {
	// update media
	mediaPlayer->update();

	// check if loop
	if (mediaPlayer->getCurrentFrame() == 0 && prevFrame != 0) {
		loopCount++;

		// check if we looped enough
		// if so, mediaDone is set to true so that main app can kill it
		if (loopCount == loopTot) {
			mediaPlayer->stop();
			mediaDone = true;
		}
	}

	// update frame
	prevFrame = mediaPlayer->getCurrentFrame();

	// draw video in fbo
	mediaFbo.begin();

	// draw video
	ofSetColor(255);
	mediaPlayer->draw(winBorder, winBorder);

	// compute progress bar
	int progressBarX = ofMap(mediaPlayer->getCurrentFrame(), 0, mediaPlayer->getTotalNumFrames(), 0, mediaSize.x - pBO);
	ofSetColor(250);
	ofDrawRectangle(winBorder, winBorder + mediaSize.y, mediaSize.x, pBH);
	ofSetColor(210);
	ofDrawRectRounded(winBorder + pBO, winBorder + mediaSize.y + pBO, mediaSize.x - 2 * pBO, pBH - 2 * pBO, pBRR);
	//
	ofSetColor(50);
	ofDrawRectRounded(winBorder + pBO, winBorder + mediaSize.y + pBO, progressBarX, pBH - 2 * pBO, pBRR);

	// draw border
	ofSetColor(0);
	ofDrawRectangle(0, 0, winSize.x + winBorder, winBorder);
	ofDrawRectangle(winSize.x - winBorder, 0, winBorder, winSize.y);
	ofDrawRectangle(0, winSize.y - winBorder, winSize.x, winBorder);
	ofDrawRectangle(0, 0, winBorder, winSize.y);

	// end fbo drawing
	mediaFbo.end();

	// draw fbo in main window
	ofSetColor(255);
	mediaFbo.draw(winPos);
}

bool VideoPlayerInstance::isMediaDone()
{
	return mediaDone;
}

int VideoPlayerInstance::getMediaId()
{
	return mediaId;
}

int VideoPlayerInstance::getMediaIdNum()
{
	return mediaIdNum;
}


