#pragma once
#include <cstdlib>
#include <ctime>
#include <deque>
#include "ofImage.h"
#include "ofMain.h"
#include "ofVec2f.h"
#include "platform.h"

using namespace std;

/*
 * This class is used to manage elements of backgrounds, 
 * including the ceiling, walls at the side, and random platforms.
 *
 */

class Background {
   private:
    float width = ofGetWidth() / 34.0;
    float platform_timer = 0;

    ofImage ceiling;
    ofImage left_wall;
    ofImage right_wall;
    ofVec2f lw_pos = ofVec2f(0.0f, 0.0f);
    ofVec2f rw_pos = ofVec2f(ofGetWidth() - width, 0.0f);
    deque<Platform*> platforms;

   public:
    Background();
    ~Background(){};
    void draw();
    void update();
    void drawWallCeiling();
    void updateWallsPos();
    void drawPlatforms();
    void updatePlatforms();
    deque<Platform*> getPlatforms();
};
