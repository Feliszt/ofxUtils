#pragma once
#include "ofMain.h"

// forward declaration of Link
class Link;

class Point
{
public:
	Point();
	Point(ofVec2f _pos);

	// variables
	ofVec2f acc, pos, lastPos;
	float mass, damping;
	bool pinned = false;
	ofVec2f pinPos;
	
	vector<Point*> attachedPoints;  // all the points attach to this point
	vector<float> restDists; // all resting distance

	// methods
	void applyForce(ofVec2f _force);
	void update(float _timestep);
	void solve();
	void solveLink(Point * _p, float _restDist);
	void display();

	// links and constraints
	void attachTo(Point * _p, float _restDist);
	void pinTo(ofVec2f _pinPos);
};