#pragma once
#include "ofMain.h"

class Drop
{
public:
	Drop();

	ofVec3f posStart;
	ofVec3f acc, vel, pos;

	bool outOfScreen;
	int age = 0;

	//
	int lineLength = 0;

	void setup(ofVec3f _pos, ofVec3f _vel, int _lineLength);
	void update();
	void applyForce(ofVec3f force);
	void show();
};

