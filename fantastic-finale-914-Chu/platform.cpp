#include "platform.h"

PlatformType Platform::getType() { 
	return type; 
}

ofVec2f Platform::getSize() {
	return size; 
}

ofVec2f Platform::getPosition() { 
	return position; 
}

void Platform::updatePosition() {

	position.y -= 0.05 * ofGetFrameRate();
}

void Platform::draw() { 
	
	platform.draw(position, size.x, size.y); 
}

Normal::Normal() {

	platform.load("normal.png");
    size = ofVec2f(ofGetWidth() / 5.7, ofGetHeight() / 30.7);
    position = ofVec2f(ofRandom(ofGetWidth()-size.x),ofGetHeight()-size.y);
    type = NORMAL;
}

Nail::Nail() {

	platform.load("nails.png");
    size = ofVec2f(ofGetWidth() / 5.7, ofGetHeight() / 30.7 * 2);
    position = ofVec2f(ofRandom(ofGetWidth() - size.x), ofGetHeight() - size.y);
    type = NAILS;
}

ConveyorL::ConveyorL() { 

	platform.load("conveyor_left.png");
    size = ofVec2f(ofGetWidth() / 5.7, ofGetHeight() / 30.7);
    position = ofVec2f(ofRandom(ofGetWidth() - size.x), ofGetHeight() - size.y);
    type = CONVEYORL;
}

ConveyorR::ConveyorR() {

	platform.load("conveyor_right.png");
    size = ofVec2f(ofGetWidth() / 5.7, ofGetHeight() / 30.7);
    position = ofVec2f(ofRandom(ofGetWidth() - size.x), ofGetHeight() - size.y);
    type = CONVEYORR;
}

Fake::Fake() {
	
	platform.load("fake.png");
    size = ofVec2f(ofGetWidth() / 5.7, ofGetHeight() / 30.7);
    position = ofVec2f(ofRandom(ofGetWidth() - size.x), ofGetHeight() - size.y);
    type = FAKE;
}

Trampoline::Trampoline() {

	platform.load("trampoline.png");
    size = ofVec2f(ofGetWidth() / 5.7, ofGetHeight() / 30.7);
    position = ofVec2f(ofRandom(ofGetWidth() - size.x), ofGetHeight() - size.y);
    type = FAKE;
}


