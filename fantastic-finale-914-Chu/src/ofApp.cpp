#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    drum.load("bgm.wav");
	drum.play();
}

//--------------------------------------------------------------
void ofApp::update() {
    
	player.update();
	background.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	background.draw();
    player.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

    float dis = 2*ofGetFrameRate();
    if ((key == 'd' || key == 'D')) {
        player.goRight();
    } else if ((key == 'a' || key == 'A')) {
        player.goLeft();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}

void ofApp::exit() { 

}
    