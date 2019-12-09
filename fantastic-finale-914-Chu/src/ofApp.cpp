#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    bgm.load("bgm.wav");
    bgm.play();
}

//--------------------------------------------------------------
void ofApp::update() {
    background.update();
    player.update(background.getPlatforms());
    if (player.isDead()) {
        current_state = GameState::EXIT;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    background.draw();

    switch (current_state) {
        case GameState::START:

            break;
        case GameState::RUN:
            player.draw();
            break;
        case GameState::EXIT:

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

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

void ofApp::exit() {}
