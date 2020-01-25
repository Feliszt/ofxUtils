#include "Thread.h"

Thread::Thread()
{
	init(4);
}

Thread::Thread(int _fixedDeltaTime){
	init(_fixedDeltaTime);
}

void Thread::init(int _fixedDeltaTime) {
	fixedDeltaTime = _fixedDeltaTime;
	fixedDeltaTimeSeconds = (float)fixedDeltaTime / 1000.0;
	leftOverDeltaTime = 0;
	constraintAccuracy = 3;
}

void Thread::update(float _gravity, float _restDist) {
	// run update
	setGravity(_gravity);
	setRestDists(_restDist);
	update();
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


// add a point
void Thread::addPoint(ofVec2f _pos) {
	Point * temp = new Point(_pos);
	this->points.push_back(temp);
}


// add a point
void Thread::addPoint(float _posX, float _posY) {
	Point * temp = new Point(_posX, _posY);
	this->points.push_back(temp);
}

// attach point
void Thread::attachPoints(int _ind1, int _ind2, float _restDist) {
	points[_ind1]->attachTo(points[_ind2], _restDist);
}

// attach point
void Thread::pinPointTo(int _ind, ofVec2f _pos) {
	points[_ind]->pinTo(_pos);
}

// add one point to the chain
void Thread::addPointToThread(float _restDist) {
	// add point
	ofVec2f pos;
	pos.set(this->points.size() > 1 ? this->points[this->points.size() - 1]->pos : ofVec2f(0, 0));
	this->addPoint(pos);

	// if there is already at least one point in the thread
	// attach the new point to the last point
	if (this->points.size() > 1) {
		this->attachPoints(this->points.size() - 2, this->points.size() - 1, _restDist);
	}
}

// remove last point of thread
void Thread::removeLastPoint() {
	// we have to erase all the links that point to this point
	for (int i = 0; i < this->points.size(); i++) {
		for (int j = 0; j < this->points[i]->attachedPoints.size(); j++) {
			if (this->points[i]->attachedPoints[j] == this->points[this->points.size() - 1]) {
				this->points[i]->attachedPoints.erase(this->points[i]->attachedPoints.begin() + j);
			}
		}
	}

	// then we remove the point from the thread
	this->points.erase(this->points.end() - 1);
}

// set restDists
void Thread::setRestDists(float _restDists) {
	// update restDists
	for (int i = 0; i < points.size(); i++) {
		for (int j = 0; j < points[i]->restDists.size(); j++) {
			points[i]->restDists[j] = _restDists;
		}
	}
}

// set gravity
void Thread::setGravity(float _gravity) {
	for (int i = 0; i < points.size(); i++) {
		points[i]->gravity = _gravity;
	}
}