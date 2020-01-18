#include "Thread.h"

Thread::Thread()
{
}

void Thread::setup() {
	fixedDeltaTime = 2;
	fixedDeltaTimeSeconds = (float)fixedDeltaTime / 1000.0;
	leftOverDeltaTime = 0;
	constraintAccuracy = 3;
}

void Thread::update() {
	// get elapsed time
	currentTime = ofGetElapsedTimeMillis();
	long deltaTimems = currentTime - previousTime;

	// reset previous time
	previousTime = currentTime;

	int timeStepAmt = (int)((float)(deltaTimems + leftOverDeltaTime) / (float)fixedDeltaTime);
	timeStepAmt = min(timeStepAmt, 5);
	leftOverDeltaTime = (int)deltaTimems - (timeStepAmt * fixedDeltaTime);

	// update physics
	for (int iteration = 1; iteration <= timeStepAmt; iteration++) {
		// solve constraint multiple times
		for (int x = 0; x < constraintAccuracy; x++) {
			for (int i = 0; i < points.size(); i++) {
				points[i]->solve();
			}
		}
	}

	// update each points
	for (int i = 0; i < points.size(); i++) {
		points[i]->update(fixedDeltaTimeSeconds);
	}
}

void Thread::display() {
	// display each points
	for (int i = 0; i < points.size(); i++) {
		points[i]->display();
	}
}

// add a point
void Thread::addPoint(Point * _p) {
	this->points.push_back(_p);
}

// attach point
void Thread::attachPoints(int _ind1, int _ind2, float _restDist) {
	points[_ind1]->attachTo(points[_ind2], _restDist);
}

// attach point
void Thread::pinPointTo(int _ind, ofVec2f _pos) {
	points[_ind]->pinTo(_pos);
}