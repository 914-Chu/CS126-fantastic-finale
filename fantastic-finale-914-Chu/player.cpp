#include "player.h"

Player::Player() {
    player.load("mini.png");
    target.setPosition(position);
    adjusted = false;
    life = 10;
}

void Player::draw() { 
	player.draw(target.getPosition(), size.x, size.y);
}

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
                    if (!adjusted) {
                        life --;
                        adjusted = true;
                    }
                    break;
                case CONVEYORL:
                    position.y = collided.getPosition().y - size.y * 1.2;
                    position.x -= dis * 0.1;
                    if (!adjusted) {
                        life++;
                        adjusted = true;
                    }
                    break;
                case CONVEYORR:
                    position.y = collided.getPosition().y - size.y * 1.2;
                    position.x += dis * 0.1;
                    if (!adjusted) {
                        life++;
                        adjusted = true;
                    }
                    break;
                case TRAMPOLINE:
                    position.y = collided.getPosition().y - size.y * 3;
                    if (!adjusted) {
                        life += 2;
                        adjusted = true;
                    }
                    break;
                case FAKE:
                    if (!adjusted) {
                        life-=2;
                        adjusted = true;
                    }
                    break;
            }
        } else if (collided.getPosition().y - size.y < width) {
            position.y = width;
            if (!adjusted) {
                life -= 3;
                adjusted = true;
            }
        }
    } else {
        position.y += 0.12 * ofGetFrameRate();
        adjusted = false;
    }

    adjustX();
    adjustY();
    adjustLife();

    auto seq = Sequence::create(
        EaseCircleActionOut::create(MoveTo::create(1, position)),
        CallFunc::create([]() {}), nullptr);
    target.runAction(seq);

	if (ofGetElapsedTimeMillis() > level_timer + 4000 && life > 0) {
        level_timer = ofGetElapsedTimeMillis();
        level++;
    }
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
        life = 0;
    } else if (position.y <= width) {
        position.y = width;
        if (!adjusted) {
            life -= 3;
            adjusted = true;
        }
    }
}

void Player::adjustLife() {
    if (life > 10) {
        life = 10;
    } else if (life < 0) {
        life = 0;
	}
}

int Player::getLife() { return life; }

int Player::getLevel() { return level; }

int Player::getRecord() { return record; }