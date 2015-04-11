//
//  Timeline.h
//  example
//
//  Created by 麦 on 4/11/15.
//
//
//#pragma once

/*
#include "ofxExpressionControlSuper.h"

template <typename T>
class ofxExpressionControl : public ofxExpressionControlSuper {
	
public:
	ofxExpressionControl();
	
	void addKey(unsigned int frame, T value) {
		if (frame >= keyframes.size()) {
			keyframes.resize(frame + 1, defaultValue);
		}
		keyframes[frame] = pair<T, bool>(value, true);
	}
	
	string toString(unsigned int index) {
		return "unco";
	}
	
private:
	pair<T, bool>			defaultValue;
	vector< pair<T, bool> >	keyframes;
};

//--------------------------------------------------------------
// specialization


// slider (float)
template<> ofxExpressionControl<float>::ofxExpressionControl() {
	type = "float";
	defaultValue = pair<float, bool>(0.0, false);
}
template<> string ofxExpressionControl<float>::toString(unsigned int index) {
	
	ss.str("");
	ss	<< "Effects\tSlider Control #" << index << "\tSlider #2" << endl
	<< "\tFrame" << endl;
	
	for (int i = 0; i < keyframes.size(); i++) {
		if (keyframes[i].second) {
			ss << "\t" << i << "\t" << keyframes[i].first << endl;
		}
	}
	
	return ss.str();
}*/