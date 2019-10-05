#pragma once

#include "ofMain.h"
#include "ofxUtils.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		// draggable points
		DraggablePoint pt1, pt2;
};
