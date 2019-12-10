#include "background.h"

Background::Background() {
    ofSetBackgroundColor(ofColor(0, 0, 0));
    ceiling.load("ceiling.png");
    left_wall.load("wall.png");
    right_wall.load("wall.png");
    srand(time(0));
}

void Background::draw() {
    drawPlatforms();
    drawWallCeiling();
}

void Background::update() {
    updateWallsPos();

    if (ofGetElapsedTimeMillis() > platform_timer + 600) {
        platform_timer = ofGetElapsedTimeMillis();
        updatePlatforms();
    }
}

void Background::drawWallCeiling() {
    ceiling.draw(width, 0, ofGetWidth() * (3.0 / 4), width);

    left_wall.draw(
        lw_pos.x,
        fmod((ofGetHeight() + lw_pos.y), ofGetHeight()) - ofGetHeight(), width,
        ofGetHeight() * 2);
    left_wall.draw(lw_pos.x, fmod((ofGetHeight() + lw_pos.y), ofGetHeight()),
                   width, ofGetHeight() * 2);
    right_wall.draw(
        rw_pos.x,
        fmod((ofGetHeight() + rw_pos.y), ofGetHeight()) - ofGetHeight(), width,
        ofGetHeight() * 2);
    right_wall.draw(rw_pos.x, fmod((ofGetHeight() + rw_pos.y), ofGetHeight()),
                    width, ofGetHeight() * 2);
}

void Background::updateWallsPos() {
    lw_pos.y -= 0.05 * ofGetFrameRate();
    rw_pos.y -= 0.05 * ofGetFrameRate();
    rw_pos.x = ofGetWidth() * (3.0 / 4);
}

void Background::drawPlatforms() {
    for (Platform *p : platforms) {
        p->draw();
        p->updatePosition();
    }
}

void Background::updatePlatforms() {
    Platform *temp;
    int num = (rand() % 6);

    switch (num) {
        case 0:
            temp = new Normal();
            break;
        case 1:
            temp = new Nail();
            break;
        case 2:
            temp = new ConveyorL();
            break;
        case 3:
            temp = new ConveyorR();
            break;
        case 4:
            temp = new Fake();
            break;
        case 5:
            temp = new Trampoline();
            break;
    }

    platforms.push_back(temp);

    if (platforms.front()->getPosition().y <= 0) {
        platforms.pop_front();
    }
}

deque<Platform *> Background::getPlatforms() { return platforms; }

