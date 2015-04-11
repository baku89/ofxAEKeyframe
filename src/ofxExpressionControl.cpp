//
//  ofxExpressionControl.cpp
//  example
//
//  Created by 麦 on 4/11/15.
//
//

#include "ofxExpressionControl.h"


/*template<typename T> void ofxExpressionControl<T>::ofxExpressionControl() {
	type = "unknown";
}*/

/*void appendKey(T value) {
 keyframes.push_back( value );
	}*/

/*
template<typename T>
void ofxExpressionControl<T>::addKey(unsigned int frame, T value) {
	if (frame >= keyframes.size()) {
		keyframes.resize(frame + 1, defaultValue);
	}
	keyframes[frame] = pair<T, bool>(value, true);
}

template<typename T>
string ofxExpressionControl<T>::getExpressionType() {
	return type;
}

template<typename T>
string ofxExpressionControl<T>::toString(unsigned int index) {
	return "unsupported type";
}

template<typename T>
string ofxExpressionControl<T>::getType() {
	return type;
}


//--------------------------------------------------------------
// specialization

// float
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
}

// bool
template<> ofxExpressionControl<bool>::ofxExpressionControl() {
	type = OFX_AEK_CTRL_CHECKBOX;
	defaultValue = pair<bool, bool>(false, false);
}
template<> string ofxExpressionControl<bool>::toString(unsigned int index) {
	
	ss.str("");
	ss	<< "Effects\tCheckbox Control #" << index << "\tCheckbox #2" << endl
	<< "\tFrame" << endl;
	
	for (int i = 0; i < keyframes.size(); i++) {
		if (keyframes[i].second) {
			ss << "\t" << i << "\t" << (keyframes[i].first ? 1 : 0) << endl;
		}
	}
	
	return ss.str();
}

// color
template<> ofxExpressionControl<ofColor>::ofxExpressionControl() {
	type = OFX_AEK_CTRL_COLOR;
	defaultValue = pair<ofColor, bool>(ofColor(0), false);
}
template<> string ofxExpressionControl<ofColor>::toString(unsigned int index) {
	
	ss.str("");
	ss	<< "Effects\tColor Control #" << index << "\tColor #2" << endl
	<< "\tFrame\talpha\tred\tgreen\tblue" << endl;
	
	for (int i = 0; i < keyframes.size(); i++) {
		if (keyframes[i].second) {
			ofColor c = keyframes[i].first;
			ss  << "\t" << i << "\t" << c.a << "\t"
			<< c.r << "\t" << c.g << "\t" << c.b << endl;
		}
	}
	
	return ss.str();
}

// vec2f
template<> ofxExpressionControl<ofVec2f>::ofxExpressionControl() {
	type = OFX_AEK_CTRL_POINT;
	defaultValue = pair<ofVec2f, bool>(ofVec2f(0, 0), false);
}
template<> string ofxExpressionControl<ofVec2f>::toString(unsigned int index) {
	
	ss.str("");
	ss	<< "Effects\tPoint Control #" << index << "\tPoint #2" << endl
	<< "\tFrame\tX pixels\tY pixels" << endl;
	
	for (int i = 0; i < keyframes.size(); i++) {
		if (keyframes[i].second) {
			ofVec2f vec = keyframes[i].first;
			ss  << "\t" << i << "\t" << vec.x << "\t" << vec.y << endl;
		}
	}
	
	return ss.str();
}

// vec3f
template<> ofxExpressionControl<ofVec3f>::ofxExpressionControl() {
	type = OFX_AEK_CTRL_3DPOINT;
	defaultValue = pair<ofVec3f, bool>(ofVec3f(0, 0, 0), false);
}
template<> string ofxExpressionControl<ofVec3f>::toString(unsigned int index) {
	
	ss.str("");
	ss	<< "Effects\t3D Point Control #" << index << "\3D Point #2" << endl
	<< "\tFrame\tX pixels\tY pixels" << endl;
	
	for (int i = 0; i < keyframes.size(); i++) {
		if (keyframes[i].second) {
			ofVec3f vec = keyframes[i].first;
			ss  << "\t" << i << "\t" << vec.x << "\t" << vec.y << "\t" << vec.z << endl;
		}
	}
	
	return ss.str();
}
*/