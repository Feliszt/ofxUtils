#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	// resize main window
	ofSetWindowPosition(0, 0);
	ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight());

	// set video dispatcher
	videoDisp = VideoDispatcher();
	videoDisp.addVideo("video01.mp4", 2);
	videoDisp.addVideo("video02.mp4", 1);
	videoDisp.addVideo("video03.mp4", 10);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	//
	ofBackground(245);

	// update videos
	videoDisp.update();

	// debug
	if (showDebug) {
		// video dispatcher debug
		videoDisp.drawDebug(10, 10);

		// info
		ofDrawBitmapStringHighlight(to_string(ofGetFrameRate()) + " fps.", 10, ofGetHeight() - 30);
		ofDrawBitmapStringHighlight(to_string(videoDisp.getNumVideos()) + " videos in dispatcher.", 10, ofGetHeight() - 50);
		ofDrawBitmapStringHighlight(to_string(videoDisp.getNumVideosPlaying()) + " videos playing.", 10, ofGetHeight() - 70);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ') showDebug = !showDebug;
	if (key == 'v') {
		// get random video to play
		int videoToPlay = int(ofRandom(0, videoDisp.getNumVideos()));

		// set position
		ofVec2f videoSize = videoDisp.getVideoSize(videoToPlay);
		int videoPosX = int(ofRandom(0, ofGetWidth() - videoSize.x));
		int videoPosY = int(ofRandom(0, ofGetHeight() - videoSize.y));

		// play it
		videoDisp.play(videoToPlay, ofVec2f(videoPosX, videoPosY), 1);
	}
}