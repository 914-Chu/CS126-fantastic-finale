#pragma once
#include <string>
#include "ofImage.h"
#include "ofMain.h"
#include "ofVec2f.h"

using namespace std;

enum PlatformType { NORMAL, NAILS, CONVEYORL, CONVEYORR, FAKE, TRAMPOLINE};

class Platform {
   protected:
    ofImage platform;
    ofVec2f size = ofVec2f(ofGetWidth() / 5.7, ofGetHeight() / 30.7);
    ofVec2f position = ofVec2f(ofRandom(ofGetWidth() * (3.0 / 4) - size.x),
                               ofGetHeight() - size.y);
    PlatformType type;

   public:
    Platform(){};
    ~Platform(){};
    PlatformType getType();
    ofVec2f getSize();
    ofVec2f getPosition();
    void updatePosition();
    void draw();
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