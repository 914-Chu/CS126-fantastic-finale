#pragma once
#include "ofVec2f.h"
#include "ofMain.h"
#include "ofImage.h"
#include <string>

using namespace std;

enum PlatformType {
	NORMAL,
	NAILS,
	CONVEYORL,
	CONVEYORR,
	FAKE,
	TRAMPOLINE
};

class Platform {

	protected:
		
        ofImage platform;
        ofVec2f size;
        ofVec2f position;
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