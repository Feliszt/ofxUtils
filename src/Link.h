#pragma once
#include "ofMain.h"

// forward declaration of Point
class Point;

class Link
{
public:
	// variables
	float restDist;
	Point *p1;
	Point *p2;

	// methods
	Link();
	void setup(Point *_p1, Point *_p2, float _restDist);
	void solve();
	void display();
};