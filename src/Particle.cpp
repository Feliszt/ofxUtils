#include "Particle.h"



Particle::Particle()
{
}

// setup
void Particle::setup(ofVec2f _posStart, float _k, float _damp) {
	posStart = _posStart;
	k = _k;
	damp = _damp;

	szPart = 5;
	szAnchor = 5;
	acc = ofVec2f(0, 0);
	vel = ofVec2f(0, 0);
	pos = posStart;
}

// update
void Particle::update() {
	// spring force
	f = k * (posStart - pos);
	acc += f - damp * vel;

	// equations of movement
	vel += acc;
	pos += vel;
	acc *= 0;
}

// applyforce
void Particle::applyForce(ofVec2f f) {
	acc += f;
}

// draw
void Particle::show() {
	// draw posStart
	ofDrawEllipse(posStart, szAnchor, szAnchor);
	ofDrawLine(pos, posStart);

	// draw pos
	ofDrawEllipse(pos, szPart, szPart);
}

void Particle::setSpring(float _k, float _damp) {
	k = _k;
	damp = _damp;
}

ofVec2f Particle::getPos() {
	return pos;
}

ofVec2f Particle::getPosStart() {
	return posStart;
}

float Particle::getSz() {
	return szPart;
}

void Particle::setPos(ofVec2f pos) {
	posStart = pos;
}

Particle::~Particle()
{
}


