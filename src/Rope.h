#pragma once

#include "Particle.h"

class Rope
{
public:
	Rope();
	void setup(ofVec2f _pinPos, int _nbParts, float _k, float _damp);
	void update(float _k, float _damp);
	void update(ofVec2f _pos, float _k, float _damp);
	void applyForce(ofVec2f f);
	vector<ofVec2f> getPartsPos();
	void show();	
	void clear();

	ofVec2f pinPos;
	int nbParts;
	vector<Particle> parts;

	float kVar, dampVar;

	~Rope();

private:
	// spring
	float k, damp;
};

