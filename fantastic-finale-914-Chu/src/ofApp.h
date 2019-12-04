#pragma once

#include "ofMain.h"
#include "ofImage.h"
#include "ofSoundPlayer.h"
#include "ofxActionManager.h"
#include "ofUtils.h"
#include "../player.h"
#include "../platForm.h"
#include "../background.h"
#include <cmath>
#include <vector>

using namespace std;

enum GameState {
	START,
	RUN,
	EXIT
};

class ofApp : public ofBaseApp{

	private:
		GameState current_state = START;
        Player player;

	public:
		void setup();
		void update();
		void draw();
        void exit();
		void keyPressed(int key);
		void keyReleased(int key);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void drawBackGround();
        void drawPlatforms();
        void updatePlatforms();

		float object_size = ofGetWidth()/34.0;
        float size = ofGetWidth()/17;
        float last_time = 0;
        int x = (ofGetWidth()- size)/2;
        int y = 0;
        int level = 0;
        int total_level = 100;

        ActionTarget target;
        Background background;
        ofImage mini;
        ofImage ceiling;
        ofImage left_wall;
        ofImage right_wall;
        ofVec2f lw_pos = ofVec2f(0.0f, 0.0f);
        ofVec2f rw_pos = ofVec2f(ofGetWidth() - object_size, 0.0f);
        ofSoundPlayer drum;
        vector<Platform*> platforms;

};
