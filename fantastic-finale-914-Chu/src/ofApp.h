#pragma once

#include "ofMain.h"
#include "ofImage.h"
#include "ofSoundPlayer.h"
#include "ofxActionManager.h"
#include "SFML/Graphics.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		 ofImage taipei101;
         ofSoundPlayer drum;

         float window_width = 1024;
         float window_height = 768;
         int x = 0;
         int y = 0;
         int keytime = 8;
         float size = 10;

		 ActionTarget target;
};
