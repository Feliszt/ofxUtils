#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// gui
	gui.setup();
	gui.add(walkerAmpMax.setup("WALKERAMPMAX", 200, 100, 500));
	gui.add(manualMod.setup("MANUALMOD", 1.0, 0.0, 1.0));
	gui.add(nPoints.setup("NPOINTS", 5, 1, 10));

	// walker
	p1.setup(ofVec2f(0.1*ofGetWidth(), ofGetHeight() * 0.5), 10);
	p2.setup(ofVec2f(0.9*ofGetWidth(), ofGetHeight() * 0.5), 10);
	w = Walker(p1.pos, p2.pos, nPoints, walkerAmpMax, true);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	// bg
	ofBackground(240);

	// update points of walker
	w.setPoints(p1.pos, p2.pos);
	w.setMod(manualMod);
	//w.setNPoints(nPoints);

	// get points and draw
	ofPolyline curve = w.computePoints();
	ofSetColor(50);
	ofSetLineWidth(3);
	curve.draw();
	ofSetLineWidth(1);

	// draggable points
	ofSetColor(ofColor::blue);
	p1.draw(true);
	ofSetColor(ofColor::red);
	p2.draw(true);

	// gui
	if (showDebug) {
		gui.draw();

		// draw line
		ofSetColor(200);
		ofDrawLine(p1.pos, p2.pos);

		// draw inter points
		auto pts = w.getInterPts();
		ofSetColor(100);
		for (int i = 1; i < pts.size()-1; i++) {
			ofDrawEllipse(pts[i], 5, 5);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r') w = Walker(p1.pos, p2.pos, nPoints, walkerAmpMax, true);
	if (key == ' ') showDebug = !showDebug;
}
