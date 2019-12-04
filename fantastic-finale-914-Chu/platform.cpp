#include "platform.h"

PlatformType Platform::getType() { 
	return type; 
}

ofVec2f Platform::getSize() {
	return size; 
}

ofVec2f Platform::getPosition() { return position; }

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

	platform.load("nail.png");
    size = ofVec2f(ofGetWidth() / 5.7, ofGetHeight() / 30.7 * 2);
    position = ofVec2f(ofRandom(ofGetWidth() - size.x), ofGetHeight() - size.y);
    type = NAIL;
}