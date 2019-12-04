#pragma once
#include "ofVec2f.h"
#include "ofMain.h"

enum Direction {

    LEFT,
	RIGHT,
	DOWN
};

class Player {

	private:
		ofVec2f size;

	public:

		Player();
        ~Player(){};
        void Update();
};
