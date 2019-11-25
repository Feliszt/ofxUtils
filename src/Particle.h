#pragma once
#include "ofMain.h"

class Particle
{
public:
	Particle();	
	void setup(ofVec2f _posStart, float _k, float _damp);
	void update();
	void applyForce(ofVec2f f);
	void show();
	void setSpring(float _k, float _damp);
	ofVec2f getPos();
	ofVec2f getPosStart();
	float getSz();
	void setPos(ofVec2f pos);
	~Particle();

private:
	ofVec2f acc, vel, pos, posStart;
	float szPart, szAnchor;
	// spring
	float k, damp;
	ofVec2f f;
};

