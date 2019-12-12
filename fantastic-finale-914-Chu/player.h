#pragma once
#include <deque>
#include "ofImage.h"
#include "ofMain.h"
#include "ofVec2f.h"
#include "ofxActionManager.h"
#include "ofGraphics.h"
#include "ofTrueTypeFont.h"
#include "ofSoundPlayer.h"
#include "platform.h"

using namespace std;

/*
 * This class manage player's movement and keep track of currrent status.
 */

class Player {
   private:
    ofVec2f size;
    ofVec2f position;
    ofImage player;
    ActionTarget target;
    Platform collided;
    ofTrueTypeFont font;
    ofSoundPlayer scream;
    ofSoundPlayer hit;

    float dis;
    float width;
    float level_timer;
    int life;
    int level;
    bool platform_stay;
    bool ceiling_touched;

   public:
    Player();
    ~Player(){};
    void draw();
    void update(const deque<Platform *> &platforms);
    void goLeft();
    void goRight();
    void adjustX();
    void adjustY();
    void adjustLife();
    void adjustLevel();
    ofVec2f positionWithPlatform();
    int getLife();
    int getLevel();    
	bool collide(const deque<Platform *> &platforms);
};
