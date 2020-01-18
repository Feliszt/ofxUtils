#pragma once
#include "ofMain.h"

class Bubble
{
public:
	Bubble();

	ofVec3f acc, vel, pos;
	ofVec3f drift;
	float driftStrength;

	bool outOfScreen;
	int age = 0;

	void setup(ofVec3f _pos, ofVec3f _vel, float _driftStrength);
	void update();
	void applyForce(ofVec3f force);
	void show();
};

