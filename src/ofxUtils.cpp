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

//--------------------------------------------------------------
vector<string> split(string _s, string _del) {
	vector<string> sList;
	size_t pos = 0;
	std::string token;
	while ((pos = _s.find(_del)) != std::string::npos) {
		token = _s.substr(0, pos);
		sList.push_back(token);
		_s.erase(0, pos + _del.length());
	}
	sList.push_back(_s);
	return sList;
}

//--------------------------------------------------------------
string join(const vector<string> _sList, string _del) {
	string sToReturn = "";
	for (vector<string>::const_iterator p = _sList.begin();
		p != _sList.end(); ++p) {
		sToReturn += *p;
		if (p != _sList.end() - 1)
			sToReturn += _del;
	}
	return sToReturn;
}

//--------------------------------------------------------------
string sec2Timestamp(float _timeS) {
	//
	int nTotSeconds = floor(_timeS);
	//
	int nMS = int((_timeS - nTotSeconds) * 1000.0);
	int nSS = nTotSeconds % 60;
	int nMM = (nTotSeconds / 60) % 60;
	int nHH = int(nTotSeconds / 3600);
	//
	string nSS_string = string(2 - to_string(nSS).size(), '0') + to_string(nSS);
	string nMM_string = string(2 - to_string(nMM).size(), '0') + to_string(nMM);
	string nHH_string = string(2 - to_string(nHH).size(), '0') + to_string(nHH);
	string nMS_string = to_string(nMS);
	//
	string timestamp = nHH_string + ":" + nMM_string + ":" + nSS_string + "." + nMS_string;
	return timestamp;
}