#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	aek.setFPS(29.97);
	aek.addControlPoint();		// 0: mouse position
	aek.addControlCheckbox();	// 1: is mouse pressed
	aek.addControlSlider();		// 2: audio input volume
	
	sound.setup(this, 0, 1, 44100, 256, 4);
}

//--------------------------------------------------------------
void ofApp::update(){

	// add keyfraames
	aek.appendFrame();
	aek.addKey(0, ofVec2f(ofGetMouseX(), ofGetMouseY()));
	aek.addKey(1, ofGetMousePressed());
	aek.addKey(2, curtVol);
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackground(128);
	
	if (ofGetMousePressed()) {
		ofSetColor(255, 0, 0);
	} else {
		ofSetColor(0, 0, 255);
	}
	
	ofCircle(ofGetMouseX(), ofGetMouseY(), curtVol * 5 + 10);
	
	ofSetColor(255);
	ofDrawBitmapString("Press space key to copy to clipboard", ofPoint(10, 30));

}

//--------------------------------------------------------------
void ofApp::audioIn(float *input, int bufferSize, int nChannels) {
	curtVol = 0.0;
	
	for (int i = 0; i < bufferSize; i++) {
		curtVol += input[i]*input[i] * 100;
	}
	
	curtVol /= bufferSize;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if (key == ' ') {
		ofxClipboard::copy( aek.toString() );
		
		stringstream ss;
		ss << aek.getDuration() << " frames copied!";
		
		ofSystemAlertDialog( ss.str() );
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
