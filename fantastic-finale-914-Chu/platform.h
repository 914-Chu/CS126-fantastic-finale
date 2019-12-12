#pragma once
#include <string>
#include "ofImage.h"
#include "ofMain.h"
#include "ofVec2f.h"

using namespace std;

enum PlatformType { NORMAL, NAILS, CONVEYORL, CONVEYORR, FAKE, TRAMPOLINE};

/*
 * This is the base class of all types of platform. 
 * Take care of platform's movement and features.
 */


class Platform {

   protected:
    ofImage platform;
    ofVec2f size;
    ofVec2f position;
    PlatformType type;
    float position_ratio; // relation with player position.
    int life_effect;      // specific effect on player.

   public:
    Platform();
    ~Platform(){};
    PlatformType getType();
    ofVec2f getSize();
    ofVec2f getPosition();
    void updatePosition();
    void draw();
    float getPositionRatio();
    int getLifeEffect();
};

class Normal : public Platform {
   public:
    Normal();
    ~Normal(){};
};

class Nail : public Platform {
   public:
    Nail();
    ~Nail(){};
};

class ConveyorL : public Platform {
   public:
    ConveyorL();
    ~ConveyorL(){};
};

class ConveyorR : public Platform {
   public:
    ConveyorR();
    ~ConveyorR(){};
};

class Fake : public Platform {
   public:
    Fake();
    ~Fake(){};
};

class Trampoline : public Platform {
   public:
    Trampoline();
    ~Trampoline(){};
};