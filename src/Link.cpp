#include "Link.h"
#include "Point.h"

Link::Link()
{
}

// setup link
void Link::setup(Point *_p1, Point *_p2, float _restDist) {
	p1->setup(_p1);
	p2->setup(_p2);
	restDist = _restDist;
}

// solve link constraint
void Link::solve() {
	// calculate distance between the 2 masses
	ofVec2f diff = p1->pos - p2->pos;
	float d = diff.distance(ofVec2f::zero());
	
	// find ratio to resting distance
	float difference = (restDist - d) / d;

	// inverse the masses
	float im1 = 1 / p1->mass;
	float im2 = 1 / p2->mass;
	float scalarP1 = im1 / (im1 + im2);
	float scalarP2 = scalarP1;

	// push or pull based on mass
	p1->pos += diff * scalarP1 * difference;
	p2->pos += diff * scalarP2 * difference;
}

// display link
void Link::display() {
	ofDrawLine(p1->pos, p2->pos);
}

