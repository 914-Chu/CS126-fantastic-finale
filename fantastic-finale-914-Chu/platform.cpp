#include "platform.h"

/*
 * Default constructor
 * Set up default size and a random initial position for the platform.
 */


Platform::Platform() {

	size = ofVec2f(ofGetWidth() / 5.7, ofGetHeight() / 30.7);
    position = ofVec2f(ofRandom(ofGetWidth() * (3.0 / 4) - size.x),ofGetHeight() - size.y);
}

/*
 * Make platforms keep going upward.
 */

void Platform::updatePosition() { position.y -= 0.05 * ofGetFrameRate(); }

PlatformType Platform::getType() { return type; }

ofVec2f Platform::getSize() { return size; }

ofVec2f Platform::getPosition() { return position; }

void Platform::draw() { platform.draw(position, size.x, size.y); }

float Platform::getPositionRatio() { return position_ratio; }

int Platform::getLifeEffect() { return life_effect; }

Normal::Normal() {
    platform.load("normal.png");
    type = NORMAL;
    position_ratio = 1.2;
    life_effect = 0;
}

Nail::Nail() {
    platform.load("nails.png");
    size = ofVec2f(ofGetWidth() / 5.7, ofGetHeight() / 30.7 * 2);
    type = NAILS;
    position_ratio = 1;
    life_effect = -1;
}

ConveyorL::ConveyorL() {
    platform.load("conveyor_left.png");
    type = CONVEYORL;
    position_ratio = 1.2;
    life_effect = 1;
}

ConveyorR::ConveyorR() {
    platform.load("conveyor_right.png");
    type = CONVEYORR;
    position_ratio = 1.2;
    life_effect = 1;
}

Fake::Fake() {
    platform.load("fake.png");
    type = FAKE;
    position_ratio = 0;
    life_effect = -2;
}

Trampoline::Trampoline() {
    platform.load("trampoline.png");
    type = TRAMPOLINE;
    position_ratio = 3;
    life_effect = 2;
}
