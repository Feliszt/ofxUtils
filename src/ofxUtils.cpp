#include "ofxUtils.h"

//----------------------------------------------------------  ----
ofVec2f bezier(float t_, vector<ofVec2f> cp_) {
	ofVec2f p_res = ofVec2f(0, 0);
	for (int i = 0; i < cp_.size(); i++) {
		ofVec2f p_temp = cp_[i] * bernstein(t_, i, cp_.size() - 1);
		p_res += p_temp;
	}
	return p_res;
}

//--------------------------------------------------------------
float bernstein(float t_, int ind_, int deg_) {
	return (factorial(deg_) / (factorial(ind_) * factorial(deg_ - ind_))) * pow(t_, ind_) * pow(1 - t_, deg_ - ind_);
}

//--------------------------------------------------------------
int factorial(int n_) {
	if (n_ <= 0)
		return 1;
	else
		return n_ * factorial(n_ - 1);
}

//--------------------------------------------------------------
float angleBetweenPoints(ofVec2f _p1, ofVec2f _p2) {
	return (ofVec2f(_p1.x + 1000, _p1.y) - _p1).angleRad(_p2 - _p1);
}