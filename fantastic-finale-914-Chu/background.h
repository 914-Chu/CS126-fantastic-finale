#pragma once
#include "ofMain.h"
#include "ofImage.h"
#include "ofVec2f.h"

class Background {
	
	private:

		float width = ofGetWidth() / 34.0;	

		ofImage ceiling;
		ofImage left_wall;
		ofImage right_wall;
        ofVec2f lw_pos = ofVec2f(0.0f, 0.0f);
        ofVec2f rw_pos = ofVec2f(ofGetWidth() - width, 0.0f);

	public:
		Background();
         ~Background(){};
        void draw();
        void updateWallsPos();
		
};
