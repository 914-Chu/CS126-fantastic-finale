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

class Player {
   private:
    ofVec2f size = ofVec2f(ofGetWidth() / 17, ofGetHeight() / 12.8);
    ofVec2f position = ofVec2f((ofGetWidth() - size.x) / 2, width+size.y);
    ofImage player;
    ActionTarget target;
    Platform collided;
    ofTrueTypeFont font;
    ofSoundPlayer scream;
    ofSoundPlayer hit;

    float dis = 1.5 * ofGetFrameRate();
    float width = ofGetWidth() / 34.0;
    float level_timer = 0;
    int life;
    int level = 0;
    bool adjusted;

   public:
    Player();
    ~Player(){};
    void draw();
    void update(const deque<Platform *> &platforms);
    void goLeft();
    void goRight();
    bool collide(const deque<Platform *> &platforms);
    void adjustX();
    void adjustY();
    void adjustLife();
    int getLife();
    int getLevel();
};
