#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    mini.load("mini.png");
    drum.load("Bass-Drum-1.wav");
	target.setPosition(ofVec2f(x,y));
}

//--------------------------------------------------------------
void ofApp::update() {
    
    const float delta = ofGetLastFrameTime();
    ActionManager::getInstance()->updateActions(delta);
    if (y < ofGetHeight()- size) {
        y += 0.1 * ofGetFrameRate();
    } else {
        y = ofGetHeight() - size;
	}

	auto seq = Sequence::create(
        EaseCubicActionOut::create(MoveTo::create(1, ofVec2f(x, y))),
        CallFunc::create([]() {}), nullptr);
    target.runAction(seq);

	background.updateWallsPos();

	if (ofGetElapsedTimeMillis() > last_time + 600) {
        last_time = ofGetElapsedTimeMillis();
		updatePlatforms();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {

	background.draw();
    drawPlatforms();
	mini.draw(target.getPosition(), size, size);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

    if (key == ' ') {
           drum.play();
    }

    float dis = 2*ofGetFrameRate();
    if ((key == 'd' || key == 'D')) {
        x += dis;
        if (x + size > ofGetWidth() - object_size) {
            x = ofGetWidth() - object_size - size;
		}
    } else if ((key == 'a' || key == 'A')) {
        x -= dis;
        if (x - size < object_size) {
            x = object_size;
		} 
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

	platforms.clear();
}

void ofApp::drawPlatforms() {

	for (Platform *p : platforms) {
		p->draw();
        p->updatePosition();
	}
	
}

void ofApp::updatePlatforms() { 

	Platform *r = new Normal();
	platforms.push_back(r);
}
    