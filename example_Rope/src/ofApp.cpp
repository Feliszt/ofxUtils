#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// setup gui
	gui.setup();
	gui.add(k.setup("K", 0.2, 0.0001, 1.0));
	gui.add(damp.setup("DAMP", 0.7, 0.0001, 1.0));
	gui.add(gravity.setup("GRAVITY", 2.0, 0.0, 10.0));

	// setup rope
	startPos.setup(ofGetWidth() * 0.5, ofGetHeight() * 0.25, 20);
	r.setup(startPos.pos, 10, k, damp);
}

//--------------------------------------------------------------
void ofApp::update(){
	// update rope
	r.update(startPos.pos, k, damp);
	r.applyForce(ofVec2f(0, gravity));
}

//--------------------------------------------------------------
void ofApp::draw(){
	// background
	ofBackground(245, 241, 243);

	// draw draggable point
	ofSetColor(ofColor::purple);
	ofFill();
	startPos.draw();

	// draw rope
	ofSetColor(ofColor::blue);
	r.show();

	// draw gui
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
