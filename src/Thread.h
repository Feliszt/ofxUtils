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
	Thread(int _fixedDeltaTime);
	void update();
	void update(float _gravity, float _restDist);
	void display();
	void addPoint(Point * _p);
	void addPoint(ofVec2f _pos);
	void addPoint(float _posX, float _posY);
	void attachPoints(int _ind1, int _ind2, float _restDist);
	void addPointToThread(float _restDist);
	void removeLastPoint();
	void pinPointTo(int _ind, ofVec2f _pos);
	void setRestDists(float _restDists);
	void setGravity(float _gravity);

private:
	void init(int _fixedDeltaTime);
};

