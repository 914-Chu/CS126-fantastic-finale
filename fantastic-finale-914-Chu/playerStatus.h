#pragma once
#include "ofVec2f.h"
#include "ofMain.h"
#include "platform.h"

class PlayerStatus {

	private:

		int level;
        int life;
        float level_timer;
        bool adjusted;
	public:
		
		PlayerStatus();
        ~PlayerStatus() {};
        void updateStatus(Platform collided);
        ofVec2f getLevel();
};
