#pragma once
#include "ofMain.h"
#include "ofxUtils.h"

class Walker
{
public:
	// methods
	Walker();
	Walker(ofVec2f _p1, ofVec2f _p2, int _nPoints, float _walkerAmpMax);
	vector<float>		shuffleAmps();
	ofPolyline			computePoints();
	void				setPoints(ofVec2f _p1, ofVec2f _p2);
	void				setMod(float _manualMod);

private:
	// variables
	ofVec2f				p1, p2;
	float				dT;
	int					nPoints;
	vector<ofVec2f>		interPs;
	vector<float>		walkerAmps;
	float				walkerAmpMax;
	float				manualMod;
	float				angleBetPoints, distBetPoints;
};

