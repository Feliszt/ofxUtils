#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxUtils.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		
		// walker
		DraggablePoint	p1, p2;
		Walker			w;

		// gui
		ofxPanel			gui;
		ofxFloatSlider		walkerAmpMax, manualMod;
		ofxIntSlider		nPoints;
};
