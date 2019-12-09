#pragma once
#include <deque>
#include "ofImage.h"
#include "ofMain.h"
#include "ofVec2f.h"
#include "ofxActionManager.h"
#include "platform.h"

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

    float dis = 1.5 * ofGetFrameRate();
    float width = ofGetWidth() / 34.0;
    bool dead;

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
    bool isDead();
};
