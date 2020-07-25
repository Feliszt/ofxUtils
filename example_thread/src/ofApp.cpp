#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// setup window position
	ofSetWindowPosition(10, 50);

	// setup utils
	screen = ofVec2f(ofGetWidth(), ofGetHeight());
	center = screen / 2;
	pt1.setup(center.x - 50, center.y, 10);
	pt2.setup(center.x + 50, center.y, 10);

	// setup thread
	t = Thread();
	restDists = 15;
	numPoints = 10;
	t.addPoint(center.x, 20);
	for (int i = 0; i < numPoints-1 ; i++) {
		t.addPointToThread(restDists);
	}

	// setup gui
	gui.setup();
	gui.add(gravity.setup("GRAVITY", 50000, 0.0, 100000));
	gui.add(restDists.setup("RESTDISTS", restDists, 1.0, 50.0));
	gui.add(numPoints.setup("NUMPOINTS", numPoints, 1, 500));
	gui.add(fStrength.setup("FSTRENGTH", 1, 0, 100000));
	gui.add(fAngle.setup("FANGLE", 0, 0, 3 * PI));
}

//--------------------------------------------------------------
void ofApp::update(){
	// update utils
	mouse.set(ofGetMouseX(), ofGetMouseY());

	// add or remove points for thread
	int diffPoints = numPoints - numPointsPrev;
	if (diffPoints != 0) {
		int diffPointsAbs = abs(diffPoints);
		// add or remove points
		for (int i = 0; i < diffPointsAbs; i++) {
			diffPoints > 0 ? t.addPointToThread(restDists) : t.removeLastPoint();
		}
	}

	//
	numPoints = t.points.size();
	numPointsPrev = numPoints;
}

//--------------------------------------------------------------
void ofApp::draw(){
	// draw background
	ofBackground(240, 241, 238);

	// display thread
	ofSetColor(231, 32, 24);
	ofFill();

	// pin first and last point, unpin the rest
	t.pinPointTo(0, pt1.pos);
	t.pinPointTo(t.points.size()-1, pt2.pos);
	for (int i = 1; i < t.points.size() - 1; i++) {
		t.points[i]->pinned = false;
	}

	// update and draw
	for (int i = 0; i < t.points.size(); i++) {
		float fX = fStrength * cos(fAngle);
		float fY = fStrength * sin(fAngle);
		t.points[i]->applyForce(ofVec2f(fX, fY));
	}
	t.update(gravity, restDists);
	t.draw();

	// draw draggable points
	ofSetColor(21, 24, 235);
	ofFill();
	pt1.draw();
	pt2.draw();

	// draw gui
	if (showDebug) {
		// draw gui
		gui.draw();

		// show number of points in thread
		ofDrawBitmapStringHighlight(to_string(t.points.size()) + " points in thread.", 10, screen.y - 30);
	}	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ') {
		showDebug != showDebug;
	}

	// add point
	if (key == '+') {
		t.addPointToThread(restDists);
	}

	// remove point
	if (key == '-') {
		// check if there are points
		if (t.points.size() > 0) {
			t.removeLastPoint();
		}
	}
}

