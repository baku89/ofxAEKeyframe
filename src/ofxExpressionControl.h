//
//  ofxExpressionControl.h
//
//  Created by baku89 on 4/11/15.
//
//

#pragma once

#include "ofMain.h"

//--------------------------------------------------------------
class ofxExpressionControl {
public:
	
	string getType() {
		return type;
	}
	
	virtual string toString(unsigned int index) {
		return "test";
	}

protected:
	stringstream ss;
	string type;
};

//--------------------------------------------------------------
// slider
class ofxExpressionControlSlider : public ofxExpressionControl {
public:
	ofxExpressionControlSlider() {
		type = OFX_AEK_CTRL_SLIDER;
	}
	
	void addKey(unsigned int frame, float value) {
		if (frame >= keyframes.size()) {
			keyframes.resize(frame + 1, pair<float, bool>(0.0, false));
		}
		keyframes[frame].first = value;
		keyframes[frame].second = true;
	}
	
	virtual string toString(unsigned int index) {
		if (keyframes.size() == 0) {
			ofLog(OF_LOG_NOTICE, "[ofxAEKeyframe] no keyframe in expression control");
			return "";
		}
		
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
	
private:
	vector< pair<float, bool> > keyframes;
};

//--------------------------------------------------------------
// checkbox
class ofxExpressionControlCheckbox : public ofxExpressionControl {
public:
	ofxExpressionControlCheckbox() {
		type = OFX_AEK_CTRL_CHECKBOX;
	}
	
	void addKey(unsigned int frame, bool value) {
		if (frame >= keyframes.size()) {
			keyframes.resize(frame + 1, pair<bool, bool>(false, false));
		}
		keyframes[frame].first = value;
		keyframes[frame].second = true;
	}
	
	virtual string toString(unsigned int index) {
		if (keyframes.size() == 0) {
			ofLog(OF_LOG_NOTICE, "[ofxAEKeyframe] no keyframe in expression control");
			return "";
		}
		
		ss.str("");
		ss	<< "Effects\tCheckbox Control #" << index << "\tCheckbox #2" << endl
		<< "\tFrame" << endl;
		
		bool prev = !keyframes[0].first;
		for (int i = 0; i < keyframes.size(); i++) {
			pair<bool, bool> key = keyframes[i];
			if (key.second && key.first != prev) {
				ss << "\t" << i << "\t" << (key.first ? 1 : 0) << endl;
			}
			prev = key.first;
		}
		return ss.str();
	}
	
private:
	vector< pair<bool, bool> > keyframes;
};

//--------------------------------------------------------------
// color
class ofxExpressionControlColor : public ofxExpressionControl {
public:
	ofxExpressionControlColor() {
		type = OFX_AEK_CTRL_COLOR;
	}
	
	void addKey(unsigned int frame, ofColor value) {
		if (frame >= keyframes.size()) {
			keyframes.resize(frame + 1, pair<ofColor, bool>(ofColor(0), false));
		}
		keyframes[frame].first = value;
		keyframes[frame].second = true;
	}
	
	virtual string toString(unsigned int index) {
		if (keyframes.size() == 0) {
			ofLog(OF_LOG_NOTICE, "[ofxAEKeyframe] no keyframe in expression control");
			return "";
		}
		
		ss.str("");
		ss	<< "Effects\tColor Control #" << index << "\tColor #2" << endl
		<< "\tFrame\talpha\tred\tgreen\tblue" << endl;
		
		for (int i = 0; i < keyframes.size(); i++) {
			if (keyframes[i].second) {
				ofColor c = keyframes[i].first;
				ss  << "\t" << i << "\t" << (int)c.a
					<< "\t" << (int)c.r << "\t" << (int)c.g << "\t" << (int)c.b << endl;
			}
		}
		return ss.str();
	}
	
private:
	vector< pair<ofColor, bool> > keyframes;
};

//--------------------------------------------------------------
// point
class ofxExpressionControlPoint : public ofxExpressionControl {
public:
	ofxExpressionControlPoint() {
		type = OFX_AEK_CTRL_POINT;
	}
	
	void addKey(unsigned int frame, ofVec2f value) {
		if (frame >= keyframes.size()) {
			keyframes.resize(frame + 1, pair<ofVec2f, bool>(ofVec2f(), false));
		}
		keyframes[frame].first = value;
		keyframes[frame].second = true;
	}
	
	virtual string toString(unsigned int index) {
		if (keyframes.size() == 0) {
			ofLog(OF_LOG_NOTICE, "[ofxAEKeyframe] no keyframe in expression control");
			return "";
		}
		
		ss.str("");
		ss	<< "Effects\tPoint Control #" << index << "\tPoint #2" << endl
			<< "\tFrame\tX pixels\tY pixels" << endl;
		
		for (int i = 0; i < keyframes.size(); i++) {
			if (keyframes[i].second) {
				ofVec2f p = keyframes[i].first;
				ss  << "\t" << i << "\t" << p.x << "\t" << p.y << endl;
			}
		}
		return ss.str();
	}
	
private:
	vector< pair<ofVec2f, bool> > keyframes;
};

//--------------------------------------------------------------
// 3d point
class ofxExpressionControl3DPoint : public ofxExpressionControl {
public:
	ofxExpressionControl3DPoint() {
		type = OFX_AEK_CTRL_3DPOINT;
	}
	
	void addKey(unsigned int frame, ofVec3f value) {
		if (frame >= keyframes.size()) {
			keyframes.resize(frame + 1, pair<ofVec3f, bool>(ofVec3f(), false));
		}
		keyframes[frame].first = value;
		keyframes[frame].second = true;
	}
	
	virtual string toString(unsigned int index) {
		if (keyframes.size() == 0) {
			ofLog(OF_LOG_NOTICE, "[ofxAEKeyframe] no keyframe in expression control");
			return "";
		}
		
		ss.str("");
		ss	<< "Effects\t3D Point Control #" << index << "\t3D Point #2" << endl
		<< "\tFrame\tX pixels\tY pixels\tZ pixels" << endl;
		
		for (int i = 0; i < keyframes.size(); i++) {
			if (keyframes[i].second) {
				ofVec3f p = keyframes[i].first;
				ss  << "\t" << i << "\t" << p.x << "\t" << p.y << "\t" << p.z << endl;
			}
		}
		return ss.str();
	}
	
private:
	vector< pair<ofVec3f, bool> > keyframes;
};