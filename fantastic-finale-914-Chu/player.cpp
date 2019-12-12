#include "player.h"

/*
 * Default constructor 
 */

Player::Player() {
    player.load("mini.png");
    scream.load("scream.wav");
    hit.load("hit.wav");
    size = ofVec2f(ofGetWidth() / 17, ofGetHeight() / 12.8);
    position = ofVec2f((ofGetWidth() - size.x) / 2, width + size.y);
    target.setPosition(position);
    dis = 1.5 * ofGetFrameRate();
    width = ofGetWidth() / 34.0;
    level_timer = 0;
    life = 10;
    level = 0;
    platform_stay = false;
    ceiling_touched = false;
}

void Player::draw() {
    player.draw(target.getPosition(), size.x, size.y);
}

/*
 * Update position and life according to player's situation.
 * Except for the FAKE platform, player will stay on the platfrom once collided.
 * Life will be adjusted only once on each platform.
 */

void Player::update(const deque<Platform *> &platforms) {
    const float delta = ofGetLastFrameTime();
    ActionManager::getInstance()->updateActions(delta);

    if (collide(platforms)) {
			if (collided.getType() != FAKE) {
                position = positionWithPlatform();
			}
            if (!platform_stay) {
                life += collided.getLifeEffect();
                platform_stay = true;
            }
    } else {
        position.y += 0.12 * ofGetFrameRate();
        platform_stay = false;
    }

    adjustX();
    adjustY();
    adjustLife();
    adjustLevel();

    auto seq = Sequence::create(
        EaseCircleActionOut::create(MoveTo::create(1, position)),
        CallFunc::create([]() {}), nullptr);
    target.runAction(seq);
}

/*
 * Update postion x when going left.
 */

void Player::goLeft() {
    position.x -= dis;
    adjustX();
}

/*
 * Update postion x when going right.
 */

void Player::goRight() {
    position.x += dis;
    adjustX();
}

/*
 * Check if the player fall on any platform, store the collided platform type.
 */

bool Player::collide(const deque<Platform *> &platforms) {
    for (Platform *platform : platforms) {
        if (platform->getPosition().y - (position.y) >= 0 &&
            platform->getPosition().y - (position.y) < size.y &&
            position.x + size.x >= platform->getPosition().x &&
            position.x <= platform->getPosition().x + platform->getSize().x) {
            collided = *platform;
            if (collided.getType() == NAILS) hit.play();
            return true;
        }
    }
    return false;
}

/*
 * Keep the player stay within the two walls.
 */

void Player::adjustX() {
    if (position.x < width) {
        position.x = width;
    } else if (position.x + size.x > ofGetWidth() * (3.0 / 4)) {
        position.x = ofGetWidth() * (3.0 / 4) - size.x;
    }
}

/*
 * Keep the player stay beneath the ceiling and end the game when fall out of the window.
 */

void Player::adjustY() {
    if (position.y >= ofGetHeight()) {
        scream.play();
        position.y = ofGetHeight();
        life = 0;
    } else if (position.y <= width) {
        hit.play();
        position.y = width;
        if (!ceiling_touched) {
            life -= 3;
            ceiling_touched = true;
        }
    } else {
        ceiling_touched = false;
	}
}

/*
 * Keep life in the range from 0 to 10.
 */

void Player::adjustLife() {
    if (life > 10) {
        life = 10;
    } else if (life < 0) {
        life = 0;
	}
}

/*
 * Update player's level every 4000 milli seconds.
 */

void Player::adjustLevel() {
    if (ofGetElapsedTimeMillis() > level_timer + 4000 && life > 0) {
        level_timer = ofGetElapsedTimeMillis();
        level++;
    }
}

/*
 * Generate player's position according to the collided platform's feature. 
 */

ofVec2f Player::positionWithPlatform() { 
	if (collided.getType() == CONVEYORL) {
        position.x -= dis * 0.1;
    } else if (collided.getType() == CONVEYORR) {
        position.x += dis * 0.1;
	}
	return ofVec2f(position.x,collided.getPosition().y - size.y * collided.getPositionRatio());
}

int Player::getLife() { return life; }

int Player::getLevel() { return level; }




