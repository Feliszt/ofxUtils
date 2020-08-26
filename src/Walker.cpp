#include "Walker.h"

Walker::Walker()
{
}

Walker::Walker(ofVec2f _p1, ofVec2f _p2, int _nPoints, float _walkerAmpMax, bool _moving)
{
	//
	p1				= _p1;
	p2				= _p2;
	nPoints			= _nPoints;
	walkerAmpMax	= _walkerAmpMax;

	//
	walkerAmps = shuffleAmps();
	dT = 0.01;
	manualMod = 1.0;
	moving = _moving;
	movingT = 0.0;

	// set frequencies
	walkerMovingFreqs.clear();
	for (int i = 0; i < nPoints; i++) {
		walkerMovingFreqs.push_back(ofRandom(50, 300));
	}	
}

vector<float> Walker::shuffleAmps()
{
	vector<float> temp;
	temp.clear();
	for (int i = 0; i < nPoints; i++) {
		temp.push_back(ofRandom(-walkerAmpMax, walkerAmpMax));
	}
	return temp;
}

ofPolyline Walker::computePoints() {
	// get angle and dist
	angleBetPoints = angleBetweenPoints(p1, p2);
	distBetPoints = p1.distance(p2);

	// get mods
	float distMod = ofMap(distBetPoints, 0, ofGetWidth(), 0.0, 1.0);

	// get vector of control points
	interPts.clear();
	interPts.push_back(p1);
	for (int i = 0; i < nPoints; i++) {
		float rat = ofMap(i, -1, nPoints, 0, 1.0);
		float movingAmp = moving ? sin(movingT / walkerMovingFreqs[i]) : 1.0;
		ofVec2f p_temp = p1 * (1 - rat) + p2 * rat + walkerAmps[i] * distMod * manualMod * movingAmp * ofVec2f(cos(angleBetPoints - HALF_PI), sin(angleBetPoints - HALF_PI));
		interPts.push_back(p_temp);
	}
	interPts.push_back(p2);

	// compute points
	ofPolyline line_temp;
	line_temp.clear();
	for (float t = 0.0; t < 1.0; t += dT) {
		ofVec2f p_temp = bezier(t, interPts);
		line_temp.lineTo(p_temp.x, p_temp.y);
	}

	if (moving) movingT += 1;

	return line_temp;
}

void Walker::setPoints(ofVec2f _p1, ofVec2f _p2) {
	p1 = _p1;
	p2 = _p2;
}

void Walker::setMod(float _manualMod) {
	manualMod = _manualMod;
}

void Walker::setMoving(bool _moving) {
	moving = _moving;
}

vector<ofVec2f>	 Walker::getInterPts() {
	return interPts;
}
