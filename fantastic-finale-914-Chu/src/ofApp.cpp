#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetBackgroundColor(ofColor(0, 0, 0));
    //taipei101.load("Taipei101.jpg");
    mini.load("mini.png");
    drum.load("Bass-Drum-1.wav");
    background.Load();
}

//--------------------------------------------------------------
void ofApp::update() {
    
    const float delta = ofGetLastFrameTime();
    ActionManager::getInstance()->updateActions(delta);
}

//--------------------------------------------------------------
void ofApp::draw() {

    //taipei101.draw(0, 0, 1024,768);
    background.Draw(window_height, window_width);
    mini.draw(target.getPosition(), size, size);
    //ofDrawBitmapString(ofToString(ofGetFrameRate()) + "fps", 10, 15);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

     if (key == ' ') {
           drum.play();
    }


    float dis = ofGetFrameRate() * 5;
    if ((key == 'w' || key == 'W')) {
        y -= dis;
        if (y - size < 0) {
            y = 0;
		}
        auto seq = Sequence::create(
            EaseCubicActionOut::create(
            MoveTo::create(1, ofVec2f(x, y))),
            CallFunc::create([]() {}),
            nullptr);
        target.runAction(seq);
    }else if ((key == 's' || key == 'S')) { 
		y += dis;
        if (y + size > ofGetHeight()) {
			y = ofGetHeight();
		}
        auto seq = Sequence::create(
            EaseCubicActionOut::create(
            MoveTo::create(1, ofVec2f(x, y))),
            CallFunc::create([]() {}),
            nullptr);
        target.runAction(seq);
	} else if ((key == 'd' || key == 'D')) {
        x += dis;
        if (x + size > ofGetWidth()) {
            x = ofGetWidth()-size;
		}
        auto seq = Sequence::create(
            EaseCubicActionOut::create(
            MoveTo::create(1, ofVec2f(x, y))),
            CallFunc::create([]() {}),
            nullptr);
        target.runAction(seq);
    } else if ((key == 'a' || key == 'A')) {
        x -= dis;
        if (x - size < 0) {
            x = 0;
		}
        auto seq = Sequence::create(
            EaseCubicActionOut::create(
             MoveTo::create(1, ofVec2f(x, y))),
             CallFunc::create([]() {}),
             nullptr);

        target.runAction(seq);
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
