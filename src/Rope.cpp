#include "Rope.h"

Rope::Rope()
{
}


Rope::~Rope()
{
}

void Rope::setup(ofVec2f _pinPos, int _nbParts, float _k, float _damp) {
	pinPos = _pinPos;
	nbParts = _nbParts;
	k = _k;
	damp = _damp;

	kVar = ofRandom(0.00, 0.0);
	dampVar = ofRandom(0.00, 0.0);

	ofVec2f pos;
	for (int i = 0; i < nbParts; i++) {
		pos.set(_pinPos);
		if (i != 0) {
			pos.set(parts[i - 1].getPos());
		}
		Particle p;
		p.setup(pos, k, damp);
		parts.push_back(p);
	}
}

void Rope::update(float _k, float _damp) {
	for (int i = 0; i < parts.size(); i++) {
		if (i != 0) {
			parts[i].setPos(parts[i - 1].getPos());
		}
		parts[i].setSpring(_k * (1 + kVar), _damp * (1 + dampVar));
		parts[i].update();
	}
}

void Rope::update(ofVec2f _pos, float _k, float _damp) {
	for (int i = 0; i < parts.size(); i++) {
		parts[0].setPos(_pos);
		if (i != 0) {
			parts[i].setPos(parts[i - 1].getPos());
		}
		parts[i].setSpring(_k * (1+kVar), _damp * (1+dampVar));
		parts[i].update();
	}
}

void Rope::applyForce(ofVec2f f) {
	for (int i = 0; i < parts.size(); i++) {
		parts[i].applyForce(f);
	}
}

vector<ofVec2f> Rope::getPartsPos() {
	vector<ofVec2f> temp;
	temp.push_back(pinPos);
	for (int i = 0; i < parts.size(); i++) {
		temp.push_back(parts[i].getPos());
	}
	return temp;
}

void Rope::show() {
	for (int i = 0; i < parts.size(); i++) {
		parts[i].show();
	}
}

void Rope::clear() {
	parts.clear();
}
