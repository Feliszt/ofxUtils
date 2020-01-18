#include "Drop.h"

Drop::Drop()
{
}


void Drop::setup(ofVec3f _pos, ofVec3f _vel, int _lineLength) {
	posStart = _pos;
	pos = _pos;
	vel = _vel;

	lineLength = _lineLength;
	outOfScreen = false;
}

void Drop::update() {
	//
	age++;

	// equations of movement
	vel += acc;
	pos += vel;
	acc *= 0;

	// check if out of screen
	float ratX = ofGetWidth() * 0.1;
	float ratY = ofGetHeight() * 0.1;
	outOfScreen = (pos.x < -ratX || pos.x > ofGetWidth() + ratX || pos.y < -ratY || pos.y > ofGetHeight() + ratY);
}


void Drop::applyForce(ofVec3f force) {
	acc += force;
}

void Drop::show() {
	ofDrawEllipse(pos, 10, 10);
}
