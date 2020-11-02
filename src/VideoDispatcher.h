#pragma once
#include "ofMain.h"
#include "VideoPlayerInstance.h"
#include "ofxUtils.h"

class VideoDispatcher
{
public:
	// constructors
	VideoDispatcher();
	VideoDispatcher(int _numPlayerPerVideo);
	// methods
	void addVideo(string _videoPath);
	void addVideo(string _videoPath, int _numPlayer);
	void update();
	void play(string _videoPath, ofVec2f _videoPos, int _videoLoops);
	void play(int _videoInd, ofVec2f _videoPos, int _videoLoops);
	void drawDebug(int _poxX, int _posY);
	// getters
	int getNumVideos();
	int getNumVideosPlaying();
	ofVec2f getVideoSize(string _videoPath);
	ofVec2f getVideoSize(int _videoInd);
	
private:
	//methods
	int videoPathToInd(string _videoPath);

	// video instance
	struct videoInstance {
		string					videoPath, videoName, videoFolder, videoExt;
		int						videoWidth, videoHeight;
		vector<bool>			videoPlaying;
		vector<ofVideoPlayer*>	videoPlayers;
	};
	vector<videoInstance>		videos;
	int							numPlayerPerVideo;

	// debug
	int maxSizeName = 0;

	// video players
	vector<VideoPlayerInstance>	videoPlayerInstances;

};

