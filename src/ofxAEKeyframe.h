//
//  ofxAEKeyframe.h
//
//  Created by baku89 on 4/10/15.
//
//
#pragma once

#define OFX_AEK_DEFAULT_FPS	29.97

#define OFX_AEK_CTRL_SLIDER		"slider"
#define OFX_AEK_CTRL_CHECKBOX	"checkbox"
#define OFX_AEK_CTRL_COLOR		"color"
#define OFX_AEK_CTRL_POINT		"point"
#define OFX_AEK_CTRL_3DPOINT	"3d point"

#include "ofMain.h"
#include "ofxExpressionControl.h"

class ofxAEKeyframe {
public:
	
	ofxAEKeyframe();
	
	// comp settings / actions
	void setFPS(float fps);
	
	// export
	string toString();
	bool saveText(string filename);
	
	// controls
	void clear();
	unsigned int addControlSlider();
	unsigned int addControlCheckbox();
	unsigned int addControlColor();
	unsigned int addControlPoint();
	unsigned int addControl3DPoint();
	
	// frame control
	unsigned int appendFrame();
	void setCurrentFrame(unsigned int frame);
	
	unsigned int getCurrentFrame();
	unsigned int getDuration();
	
	// add
	unsigned int addKey(unsigned int index, float value);
	unsigned int addKey(unsigned int index, bool value);
	unsigned int addKey(unsigned int index, ofColor value);
	unsigned int addKey(unsigned int index, ofVec2f value);
	unsigned int addKey(unsigned int index, ofVec3f value);

private:
	
	// methods
	unsigned int addControl( ofxExpressionControl *control );
	
	
	// variables
	unsigned int cntFrame, duration;
	float fps;
	
	vector<ofxExpressionControl*> controls;
	
	stringstream ss;
	
};