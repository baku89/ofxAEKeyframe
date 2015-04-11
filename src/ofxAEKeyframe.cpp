//
//  ofxAEKeyframe.cpp
//
//  Created by 麦 on 4/10/15.
//
//

#include "ofxAEKeyframe.h"

//--------------------------------------------------------------
ofxAEKeyframe::ofxAEKeyframe() {
	fps = OFX_AEK_DEFAULT_FPS;
	cntFrame = 0;
	duration = 0;
}

//--------------------------------------------------------------
void ofxAEKeyframe::clear() {
	controls.clear();
	cntFrame = 0;
	duration = 0;
}

void ofxAEKeyframe::setFPS(float _fps) {
	fps = _fps;
}

string ofxAEKeyframe::toString() {
	ss.str("");
	
	ss  << "Adobe After Effects 8.0 Keyframe Data" << endl
		<< endl
		<< "\tUnits Per Second\t" << fps << endl
		<< "\tSource Width\t1920" << endl
		<< "\tSource Height\t1080" << endl
		<< "\tSource Pixel Aspect Ratio\t1" << endl
		<< "\tComp Pixel Aspect Ratio\t1" << endl
		<< endl;
	
	for (int i = 0; i < controls.size(); i++) {
		ss << controls[i]->toString(i+1);
	}
	
	ss  << endl
		<< "End of Keyframe Data";
	
	return ss.str();
}

bool ofxAEKeyframe::saveText(string filename) {
	string text = toString();
	
	ofBuffer buffer = ofBuffer( text );
	ofBufferToFile(filename, buffer);
}


//--------------------------------------------------------------
// frame control

unsigned int ofxAEKeyframe::appendFrame() {
	if (duration == 0) {
		cntFrame = 0;
	} else {
		cntFrame++;
	}
	duration = max(duration, cntFrame + 1);
	
	return cntFrame;
}

void ofxAEKeyframe::setCurrentFrame(unsigned int frame) {
	cntFrame = frame;
	duration = max(duration, cntFrame + 1);
}

unsigned int ofxAEKeyframe::getCurrentFrame() {
	return cntFrame;
}

unsigned int ofxAEKeyframe::getDuration() {
	return duration;
}

//--------------------------------------------------------------
// add control
unsigned int ofxAEKeyframe::addControl(ofxExpressionControl *control) {
	controls.push_back( control );
	return controls.size() - 1;
}

unsigned int ofxAEKeyframe::addControlSlider() {
	return addControl( new ofxExpressionControlSlider() );
}

unsigned int ofxAEKeyframe::addControlCheckbox() {
	return addControl( new ofxExpressionControlCheckbox() );
}

unsigned int ofxAEKeyframe::addControlColor() {
	return addControl( new ofxExpressionControlColor() );
}

unsigned int ofxAEKeyframe::addControlPoint() {
	return addControl( new ofxExpressionControlPoint() );
}

unsigned int ofxAEKeyframe::addControl3DPoint() {
	return addControl( new ofxExpressionControl3DPoint() );
}



//--------------------------------------------------------------
// add key
unsigned int ofxAEKeyframe::addKey(unsigned int index, float value) {
	if (index >= controls.size() || controls[index]->getType() != OFX_AEK_CTRL_SLIDER) {
		ofLog(OF_LOG_ERROR, "[ofxAEKeyframe] invalid index");
		return 0;
	}
	((ofxExpressionControlSlider*)controls[index])->addKey(cntFrame, value);
	return cntFrame;
}

unsigned int ofxAEKeyframe::addKey(unsigned int index, bool value) {
	if (index >= controls.size() || controls[index]->getType() != OFX_AEK_CTRL_CHECKBOX) {
		ofLog(OF_LOG_ERROR, "[ofxAEKeyframe] invalid index");
		return 0;
	}
	((ofxExpressionControlCheckbox*)controls[index])->addKey(cntFrame, value);
	return cntFrame;
}

unsigned int ofxAEKeyframe::addKey(unsigned int index, ofColor value) {
	if (index >= controls.size() || controls[index]->getType() != OFX_AEK_CTRL_COLOR) {
		ofLog(OF_LOG_ERROR, "[ofxAEKeyframe] invalid index");
		return 0;
	}
	((ofxExpressionControlColor*)controls[index])->addKey(cntFrame, value);
	return cntFrame;
}

unsigned int ofxAEKeyframe::addKey(unsigned int index, ofVec2f value) {
	if (index >= controls.size() || controls[index]->getType() != OFX_AEK_CTRL_POINT) {
		ofLog(OF_LOG_ERROR, "[ofxAEKeyframe] invalid index");
		return 0;
	}
	((ofxExpressionControlPoint*)controls[index])->addKey(cntFrame, value);
	return cntFrame;
}


unsigned int ofxAEKeyframe::addKey(unsigned int index, ofVec3f value) {
	if (index >= controls.size() || controls[index]->getType() != OFX_AEK_CTRL_3DPOINT) {
		ofLog(OF_LOG_ERROR, "[ofxAEKeyframe] invalid index");
		return 0;
	}
	((ofxExpressionControl3DPoint*)controls[index])->addKey(cntFrame, value);
	return cntFrame;
}
