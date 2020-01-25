#include "Point.h"

// constructor
Point::Point()
{
	init(0, 0);
}

// constructor
Point::Point(ofVec2f _pos)
{
	init(_pos.x, _pos.y);
}

// constructor
Point::Point(float _posX, float _posY)
{
	init(_posX, _posY);
}

// init class
void Point::init(float _posX, float _posY) {
	pos = ofVec2f(_posX, _posY);
	lastPos = pos;
	acc = ofVec2f::zero();

	mass = 1.0;
	damping = 0.99;
	gravity = 980;
}

// update function
void Point::update(float _timestep) {
	// if it is a pinned point, make sure it's pinned
	if (pinned) {
		lastPos = pos;
		ofVec2f nextPos = pinPos;
		pos = nextPos;
		acc *= 0;
		return;
	}

	// apply gravity
	applyForce(ofVec2f(0, mass * gravity));

	// compute vel
	ofVec2f vel = pos - lastPos;
	vel *= damping;

	// compute next position
	ofVec2f nextPos = pos + vel + 0.5 * acc * _timestep * _timestep;

	// update var
	lastPos = pos;
	pos = nextPos;
	acc *= 0;
}

// solve for point
void Point::solve() {
	// links
	for (int i = 0; i < attachedPoints.size(); i++) {
		solveLink(attachedPoints[i], restDists[i]);
	}

	// if it is a pinned point, make sure it's pinned
	if (pinned) {
		pos = pinPos;
	}
}

void Point::solveLink(Point * _p, float _restDist) {
	// calculate distance between the 2 masses
	ofVec2f diff = this->pos - _p->pos;
	float d = sqrt(diff.x * diff.x + diff.y * diff.y);

	// find ratio to resting distance
	float difference = (_restDist - d) / d;

	// inverse the masses
	float im1 = 1 / this->mass;
	float im2 = 1 / _p->mass;
	float scalarP1 = im1 / (im1 + im2);
	float scalarP2 = scalarP1;

	// push or pull based on mass
	this->pos += diff * scalarP1 * difference * 1.0;
	_p->pos -= diff * scalarP2 * difference * 1.0;
}

// draw function
void Point::display() {
	// draw links
	for (int i = 0; i < attachedPoints.size(); i++) {
		ofDrawLine(this->pos, attachedPoints[i]->pos);
	}

	// draw point
	ofDrawEllipse(this->pos, 5, 5);
}

// apply force function
void Point::applyForce(ofVec2f _force) {
	acc += _force / mass;
}

// attach to another mass
void Point::attachTo(Point * _p, float _restDist) {
	this->attachedPoints.push_back(_p);
	this->restDists.push_back(_restDist);
}

// pin functions
void Point::pinTo(ofVec2f _pinPos) {
	pinned = true;
	pinPos = _pinPos;
}