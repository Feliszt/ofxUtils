#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// setup draggable points
	pt1.setup(ofVec2f(200, 200), 10);
	pt2.setup(250, 400, 30);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// draw background
	ofBackground(240);

	// title
	ofSetColor(50);
	ofFill();
	ofDrawBitmapString("Draggable point example.", 20, 20);

	// draw info	
	ofDrawBitmapString("Point 1 :", 25, 50);
	ofDrawBitmapString("x = " + std::to_string((int)pt1.x), 30, 65);
	ofDrawBitmapString("y = " + std::to_string((int)pt1.y), 30, 80);
	ofDrawBitmapString("Point 2 :", 25, 110);
	ofDrawBitmapString("x = " + std::to_string((int)pt2.x), 30, 125);
	ofDrawBitmapString("y = " + std::to_string((int)pt2.y), 30, 140);

	// draw point 1
	ofSetColor(ofColor::blueSteel);
	ofFill();
	pt1.draw();

	// draw point 2
	ofSetColor(ofColor::indianRed);
	ofFill();
	pt2.draw();
}