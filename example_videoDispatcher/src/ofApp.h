#pragma once

#include "ofMain.h"
#include "ofxUtils.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	// video dispatcher
	vector<string>		videoFilesPath;
	VideoDispatcher		videoDisp;

	// gui
	bool			showDebug = true;
};
