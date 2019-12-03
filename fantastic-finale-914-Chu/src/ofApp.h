#pragma once

#include "ofMain.h"
#include "ofImage.h"
#include "ofSoundPlayer.h"
#include "ofxActionManager.h"
#include "../player.h"
#include "../background.h"

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
	
		 ofImage taipei101;
         ofImage mini;
         ofSoundPlayer drum;

         float window_width = 1024;
         float window_height = 768;
         int x = 0;
         int y = 0;
		 float size = 100;

		 ActionTarget target;
         Background background;
};
