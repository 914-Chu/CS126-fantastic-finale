#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    bgm.load("bgm.wav");
    //bgm.play();
    start.load("start.png");
    end.load("exit.png");
    font.load("font.ttf", 32);
}

//--------------------------------------------------------------
void ofApp::update() {
    background.update();
	if (current_state == GameState::RUN) {
        player.update(background.getPlatforms());
        if (player.getLife()==0) {
            current_state = GameState::EXIT;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    background.draw();
    font.drawString("LIFE :\n" + to_string(player.getLife()), ofGetWidth() * 0.8,ofGetHeight() * 0.1);
    font.drawString("LEVEL :\n" + to_string(player.getLevel()),  ofGetWidth() * 0.8,ofGetHeight() * 0.25);
    switch (current_state) {
        case GameState::START:
            start.draw(ofGetWidth()*(1.0/7),ofGetHeight()*(1.0/4),ofGetWidth()/2,ofGetHeight()/2);
            break;
        case GameState::RUN:
            player.draw();
            break;
        case GameState::EXIT:
            end.draw(ofGetWidth() * (1.0 /7), ofGetHeight() * (1.0 /4),ofGetWidth() / 2, ofGetHeight() / 2);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    float dis = 2 * ofGetFrameRate();
    if ((key == 'd' || key == 'D')) {
        player.goRight();
    } else if ((key == 'a' || key == 'A')) {
        player.goLeft();
    } else if (key == ' ') {
        current_state = GameState::RUN;
    }
    player.update(background.getPlatforms());
}

void ofApp::exit() {}
