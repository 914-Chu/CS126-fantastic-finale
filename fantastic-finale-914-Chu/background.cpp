#include "background.h"

Background::Background() {

	ofSetBackgroundColor(ofColor(0, 0, 0));
	ceiling.load("ceiling.png");
    left_wall.load("wall.png");
    right_wall.load("wall.png");

}

void Background::draw() {

	ceiling.draw(width, 0, ofGetWidth() - width, width);

    left_wall.draw( lw_pos.x, fmod((ofGetHeight() + lw_pos.y), ofGetHeight()) - ofGetHeight(),
					width, ofGetHeight() * 2);
    left_wall.draw(lw_pos.x, fmod((ofGetHeight() + lw_pos.y), ofGetHeight()),
                   width, ofGetHeight() * 2);
    right_wall.draw(rw_pos.x,fmod((ofGetHeight() + rw_pos.y), ofGetHeight()) - ofGetHeight(),
				   width, ofGetHeight() * 2);
    right_wall.draw(rw_pos.x, fmod((ofGetHeight() + rw_pos.y), ofGetHeight()),
                    width, ofGetHeight() * 2);
}

void Background::updateWallsPos() {

	lw_pos.y -= 0.05 * ofGetFrameRate();
    rw_pos.y -= 0.05 * ofGetFrameRate();
    rw_pos.x = ofGetWidth() - width;
}