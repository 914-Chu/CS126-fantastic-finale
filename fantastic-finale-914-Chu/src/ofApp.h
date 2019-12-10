#pragma once

#include "../background.h"
#include "../platForm.h"
#include "../player.h"
#include "ofImage.h"
#include "ofMain.h"
#include "ofSoundPlayer.h"
#include "ofUtils.h"
#include "ofTrueTypeFont.h"
#include "ofxActionManager.h"

using namespace std;

enum GameState { START, RUN, EXIT };

class ofApp : public ofBaseApp {
   private:
    Background background;
    ofSoundPlayer bgm;
    GameState current_state = GameState::START;
    Player player;
    ofImage start;
    ofImage end;
    ofTrueTypeFont font;

   public:
    void setup();
    void update();
    void draw();
    void exit();
    void keyPressed(int key);
};
