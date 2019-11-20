#include "game.h"



void Game::setup() {
    taipei101.load("Taipei101.jpg");
    drum.load("Bass-Drum-1.wav");
}

//--------------------------------------------------------------
void Game::update() {
    const float delta = ofGetLastFrameTime();
    ActionManager::getInstance()->updateActions(delta);
}

//--------------------------------------------------------------
void Game::draw() {
    taipei101.draw(0, 0, 1024, 768);
    // ofDrawBitmapString(ofToString(ofGetFrameRate()) + "fps", 10, 15);

    ofCircle(target.getPosition(), 20);
}

//--------------------------------------------------------------
void Game::keyPressed(int key) {
    if (key == ' ') {
        drum.play();
    }

    float dis = ofGetFrameRate() * 5;
    if ((key == 'w' || key == 'W')) {
        y -= dis;
        if (y - size < 0) {
            y = 0;
        }
        auto seq = Sequence::create(
            EaseBounceOut::create(MoveTo::create(1, ofVec2f(x, y))),
            CallFunc::create([]() {}), nullptr);
        target.runAction(seq);
    } else if ((key == 's' || key == 'S')) {
        y += dis;
        if (y + size > ofGetHeight()) {
            y = ofGetHeight();
        }
        auto seq = Sequence::create(
            EaseBounceOut::create(MoveTo::create(1, ofVec2f(x, y))),
            CallFunc::create([]() {}), nullptr);
        target.runAction(seq);
    } else if ((key == 'd' || key == 'D')) {
        x += dis;
        if (x + size > ofGetWidth()) {
            x = ofGetWidth();
        }
        auto seq = Sequence::create(
            EaseBounceOut::create(MoveTo::create(1, ofVec2f(x, y))),
            CallFunc::create([]() {}), nullptr);
        target.runAction(seq);
    } else if ((key == 'a' || key == 'A')) {
        x -= dis;
        if (x - size < 0) {
            x = 0;
        }
        auto seq = Sequence::create(
            EaseBounceOut::create(MoveTo::create(1, ofVec2f(x, y))),
            CallFunc::create([]() {}), nullptr);
        target.runAction(seq);
    }
}

//--------------------------------------------------------------
void Game::keyReleased(int key) {}

//--------------------------------------------------------------
void Game::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void Game::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void Game::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void Game::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void Game::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void Game::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void Game::windowResized(int w, int h) {}

//--------------------------------------------------------------
void Game::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void Game::dragEvent(ofDragInfo dragInfo) {}

void Game::exit() {}
