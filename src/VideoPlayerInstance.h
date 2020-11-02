#pragma once
#include "ofMain.h"

class VideoPlayerInstance
{
public:
	//
	VideoPlayerInstance();
	VideoPlayerInstance(ofVideoPlayer* _mediaPlayer, ofVec2f _winPos, int _loopTot, int _mediaId, int _mediaIdNum);
	// other methods
	void draw();
	// getter
	bool isMediaDone();
	int	 getMediaId();
	int	 getMediaIdNum();

private:
	ofFbo			mediaFbo;
	ofVideoPlayer*	mediaPlayer;
	// media player window
	ofVec2f			winPos, mediaSize, winSize;
	int				winBorder;
	float			pBH, pBO, pBRR;
	//
	string			mediaFilename;
	int				loopTot, loopCount, prevFrame;
	int				mediaId, mediaIdNum;
	bool			mediaDone;
};

