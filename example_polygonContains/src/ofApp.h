#pragma once

#include "ofMain.h"
#include "ofxUtils.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);	

		// shape
		ofPolyline	shape;
		bool		isInside;
};
