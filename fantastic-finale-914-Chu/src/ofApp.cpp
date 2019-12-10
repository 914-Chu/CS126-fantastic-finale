#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    bgm.load("bgm.wav");
    bgm.play();
    start.load("start.png");
    end.load("exit.png");
}

//--------------------------------------------------------------
void ofApp::update() {
    background.update();
    if (current_state == GameState::RUN) {
        player.update(background.getPlatforms());
        if (player.isDead()) {
            current_state = GameState::EXIT;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    background.draw();

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

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

void ofApp::exit() {}
