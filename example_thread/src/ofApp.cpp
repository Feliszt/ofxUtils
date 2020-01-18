#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// setup utils
	screen = ofVec2f(ofGetWidth(), ofGetHeight());
	center = screen / 2;
	pt1.setup(center.x - 50, center.y, 10);
	pt2.setup(center.x + 50, center.y, 10);

	// setup thread
	t.setup();
	float posY = 20;
	float restDist = 10;
	int num_pts = 100;
	for (int i = 0; i < num_pts; i++) {
		t.addPoint(new Point(ofVec2f(center.x, posY)));
		posY += restDist;
	}	
	
	//
	for (int i = 0; i < num_pts; i++) {
		if (i == num_pts - 1) break;
		t.attachPoints(i, i + 1, restDist);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	// update utils
	mouse.set(ofGetMouseX(), ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::draw(){
	// draw background
	ofBackground(240, 241, 238);

	// display thread
	ofSetColor(231, 32, 24);
	ofFill();
	t.pinPointTo(0, pt1.pos);
	t.pinPointTo(t.points.size()-1, pt2.pos);
	t.update();
	t.display();

	// draw draggable points
	ofSetColor(21, 24, 235);
	ofFill();
	pt1.draw();
	pt2.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		for (int i = 0; i < t.points.size(); i++) {
			ofLog() << to_string(i) << "\t" << t.points[i]->pos;
		}
	}
}
