#pragma once
#include "ofMain.h"
#include "Point.h"

class Thread
{
public:
	// var
	long previousTime, currentTime;
	int fixedDeltaTime;
	float fixedDeltaTimeSeconds;
	int leftOverDeltaTime;
	int constraintAccuracy;

	// thread
	vector<Point*> points;

	// methods
	Thread();
	void setup();
	void update();
	void display();
	void addPoint(Point * _p);
	void attachPoints(int _ind1, int _ind2, float _restDist);
	void pinPointTo(int _ind, ofVec2f _pos);
};

