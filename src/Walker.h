#pragma once
#include "ofMain.h"
#include "ofxUtils.h"

class Walker
{
public:
	// methods
	Walker();
	Walker(ofVec2f _p1, ofVec2f _p2, int _nPoints, float _walkerAmpMax, bool _moving);
	vector<float>		shuffleAmps();
	ofPolyline			computePoints();
	void				setPoints(ofVec2f _p1, ofVec2f _p2);
	void				setMod(float _manualMod);
	void				setMoving(bool _moving);
	vector<ofVec2f>		getInterPts();

private:
	// variables
	ofVec2f				p1, p2;
	float				dT;
	int					nPoints;
	vector<ofVec2f>		interPts;
	vector<float>		walkerAmps, walkerMovingFreqs;
	float				walkerAmpMax;
	float				manualMod;
	float				angleBetPoints, distBetPoints;
	bool				moving;
	float				movingT;
};

