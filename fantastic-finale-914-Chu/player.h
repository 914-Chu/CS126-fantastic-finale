#pragma once
#include "ofVec2f.h"
#include "ofMain.h"
#include "ofxActionManager.h"
#include "ofImage.h"
#include "ofVec2f.h"
#include "platform.h"
#include <vector>

enum Direction {
	
	NONE,
    LEFT,
	RIGHT,
	DOWN
};

class Player {

	private:

		ofVec2f size;
        ofVec2f position;
        ofImage player;
		ActionTarget target;
        Direction current_dir = NONE;
        Platform collided;

		float dis = 2 * ofGetFrameRate();
        float width = ofGetWidth() / 34.0;

	public:

		Player();
        ~Player(){};
        void draw();
        void update();
        void goLeft();
        void goRight();
        /*bool collide(const vector<Platform> &platforms);*/
};
