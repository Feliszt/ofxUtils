#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// setup shape
	ofVec2f center = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
	int numPoints = 20;
	float rad = 200;
	for (int i = 0; i < numPoints; i++) {
		float theta = ofMap(i, 0, numPoints - 1, 0.0, 2*PI);
		float offset = ofRandom(-200, 200);
		float x = center.x + (rad + offset) * cos(theta);
		float y = center.y + (rad + offset) * sin(theta);
		shape.addVertex(x, y);
	}
	shape.close();

	//
	ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){
	// get if mouse is inside
	ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
	isInside = pointIsInPolygon(shape, mouse);
}

//--------------------------------------------------------------
void ofApp::draw(){
	// background
	ofBackground(ofColor::white);

	//
	ofSetColor(isInside ? ofColor::green : ofColor::red);
	ofNoFill();
	shape.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}