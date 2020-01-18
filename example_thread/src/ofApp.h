#pragma once

#include "ofMain.h"
#include "ofxUtils.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		// thread
		Thread t;

		// utils
		ofVec2f screen, center, mouse;
		DraggablePoint pt1, pt2;		
};
