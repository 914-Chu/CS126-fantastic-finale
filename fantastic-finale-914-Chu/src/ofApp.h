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
#include <ctime>
#include <cstdlib>

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


        ActionTarget target;
        Background background;
        ofImage mini;
        ofSoundPlayer drum;
        vector<Platform*> platforms;

};
