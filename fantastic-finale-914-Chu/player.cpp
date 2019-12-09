#include "player.h"

Player::Player() {
    player.load("mini.png");
    size = ofVec2f(ofGetWidth() / 17, ofGetHeight() / 12.8);
    position = ofVec2f((ofGetWidth() - size.x) / 2, width);
    target.setPosition(position);
    dead = false;
}

void Player::draw() { player.draw(target.getPosition(), size.x, size.y); }

void Player::update(const deque<Platform *> &platforms) {
    const float delta = ofGetLastFrameTime();
    ActionManager::getInstance()->updateActions(delta);

    if (collide(platforms)) {
        if (collided.getPosition().y - size.y <= ofGetHeight() - size.y &&
            collided.getPosition().y - size.y >= width) {
            switch (collided.getType()) {
                case NORMAL:
                    position.y = collided.getPosition().y - size.y * 1.2;
                    break;
                case NAILS:
                    position.y = collided.getPosition().y - size.y;
                    break;
                case CONVEYORL:
                    position.y = collided.getPosition().y - size.y * 1.2;
                    position.x -= dis * 0.1;
                    break;
                case CONVEYORR:
                    position.y = collided.getPosition().y - size.y * 1.2;
                    position.x += dis * 0.1;
                    break;
                case TRAMPOLINE:
                    position.y = collided.getPosition().y - size.y * 1.8;
                    break;
                case FAKE:
                    // position.y = collided.getPosition().y - size.y * 1.2;
                    break;
            }

        } else if (collided.getPosition().y - size.y < width) {
            position.y = width;
        } else {
            position.y = ofGetHeight() - size.y;
        }
    } else {
        position.y += 0.12 * ofGetFrameRate();
    }

    adjustX();
    adjustY();

    auto seq = Sequence::create(
        EaseCircleActionOut::create(MoveTo::create(1, position)),
        CallFunc::create([]() {}), nullptr);
    target.runAction(seq);
}

void Player::goLeft() {
    position.x -= dis;
    adjustX();
}

void Player::goRight() {
    position.x += dis;
    adjustX();
}

bool Player::collide(const deque<Platform *> &platforms) {
    for (Platform *platform : platforms) {
        if (platform->getPosition().y - (position.y) >= 0 &&
            platform->getPosition().y - (position.y) < size.y &&
            position.x + size.x >= platform->getPosition().x &&
            position.x <= platform->getPosition().x + platform->getSize().x) {
            collided = *platform;
            return true;
        }
    }
    return false;
}

void Player::adjustX() {
    if (position.x < width) {
        position.x = width;
    } else if (position.x + size.x > ofGetWidth() * (3.0 / 4)) {
        position.x = ofGetWidth() * (3.0 / 4) - size.x;
    }
}

void Player::adjustY() {
    if (position.y >= ofGetHeight()) {
        position.y = ofGetHeight();
        dead = true;
    } else if (position.y <= width) {
        position.y = width;
    }
}

bool Player::isDead() { return dead; }