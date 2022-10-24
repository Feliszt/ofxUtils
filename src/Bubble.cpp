#include "Bubble.h"



Bubble::Bubble()
{
}

void Bubble::setup(ofVec3f _pos, ofVec3f _vel, float _driftStrength) {
	pos = _pos;
	vel = _vel;
	driftStrength = _driftStrength;
}

void Bubble::update() {
	//
	age++;

	// equations of movement
	vel += acc;
	pos += vel;
	acc *= 0;

	//drift = ofVec3f(ofRandom(-driftStrength, driftStrength), ofRandom(-driftStrength, driftStrength), ofRandom(-driftStrength, driftStrength));
	drift = ofVec2f(ofRandom(-driftStrength, driftStrength), ofRandom(-driftStrength, driftStrength));
	vel = vel.length() * 0.99 * vel.normalized() + drift;

	// check if out of screen
	float ratX = ofGetWidth() * 0.1;
	float ratY = ofGetHeight() * 0.1;
	outOfScreen = (pos.x < -ratX || pos.x > ofGetWidth() + ratX || pos.y < -ratY || pos.y > ofGetHeight() + ratY);
}


void Bubble::applyForce(ofVec3f force) {
	acc += force;
}

void Bubble::show() {
	ofDrawEllipse(pos, 10, 10);
}
