#include "player.h"

Player::Player() {
	
	player.load("mini.png");
    size = ofVec2f(ofGetWidth() / 17, ofGetHeight() / 12.8);
    position = ofVec2f((ofGetWidth() - size.x) / 2, width);
    target.setPosition(position);

	//spriteRenderer = new ofxSpriteSheetRenderer(
 //       1, 10000, 0, 32);  
 //   spriteRenderer->loadTexture("player.png", 256, GL_NEAREST);  
 //   ofEnableAlphaBlending();
}

void Player::draw() {

	player.draw(target.getPosition(), size.x, size.y); 
}

void Player::update(const deque<Platform*> &platforms) {

	const float delta = ofGetLastFrameTime();
    ActionManager::getInstance()->updateActions(delta);

	if (collide(platforms)) {

		//if (collided.getType() == NAILS) {

		//	if (position.y < ofGetHeight() - size.y) {
		//		position.y = collided.getPosition().y - size.y;
  //          } else {
		//		position.y = ofGetHeight() - size.y;
  //          }
		//} else {

		//	if (position.y < ofGetHeight() - size.y) {
  //               position.y = collided.getPosition().y - size.y;
  //          } else {
  //               position.y = ofGetHeight() - size.y;
  //          }
		//}
        if (collided.getPosition().y - size.y <= ofGetHeight() - size.y &&
            collided.getPosition().y - size.y >= width) {
			position.y = collided.getPosition().y - size.y*1.2;
        } else if (collided.getPosition().y - size.y < width) {
            position.y = width;
        } else {
            position.y = ofGetHeight() - size.y;
		}
    } else if (position.y < ofGetHeight() - size.y) {
        position.y += 0.12 * ofGetFrameRate();
    } else {
		position.y = ofGetHeight() - size.y;
	}

    auto seq = Sequence::create(
        EaseCircleActionOut::create(MoveTo::create(1, position)),
        CallFunc::create([]() {}), nullptr);
    target.runAction(seq);
    //target.runAction(MoveTo::create(1,position));

	//spriteRenderer->clear();  
 //   spriteRenderer->update(ofGetElapsedTimeMillis());  

 //   sort(sprites.begin(), sprites.end(),sortVertically);  

 //   if (sprites.size() > 0) {
 //       for (int i = sprites.size() - 1; i >= 0; i--){
 //           sprites[i]->pos.y += sprites[i]->speed;  
 //           
//            if (sprites[i]->pos.y >ofGetHeight() + 16) {
 //               delete sprites[i];  
 //               sprites.erase(sprites.begin() + i);  
 //           } else {                
 //               spriteRenderer->addCenteredTile( &sprites[i]->animation, sprites[i]->pos.x,
 //													sprites[i]->pos.y); 
 //       }
    //}

    //for (int i = 0; i < 10; i++) {
    //    basicSprite* newSprite = new basicSprite(); 
    //    newSprite->pos.set(ofRandom(0, ofGetWidth()), -16); 
    //    newSprite->speed = ofRandom(1, 5);                  
    //    newSprite->animation = walkAnimation;  
    //    newSprite->animation.frame_duration /= newSprite->speed;  
    //    newSprite->animation.index = (int)ofRandom(0, 4) * 8;  
    //    sprites.push_back(newSprite);  
    //}
}

void Player::goLeft() {
	position.x -= dis;
    if (position.x - size.x < width) {
        position.x = width;
    }
}

void Player::goRight() {
	position.x += dis;
    if (position.x + size.x > ofGetWidth() - width) {
        position.x = ofGetWidth() - width - size.x;
    }
}

bool Player::collide(const deque<Platform*> &platforms) {

	for (Platform *platform : platforms) {
        if (platform->getPosition().y  - (position.y) >= 0 &&
            platform->getPosition().y - (position.y) < 10 &&
			position.x + size.x>= platform->getPosition().x &&
            position.x  <= platform->getPosition().x + platform->getSize().x) {
            cout << platform->getPosition().y << ":y" << position.y << ": "<< size.y<<endl;
            collided = *platform;
            return true;
		}
    }
    return false;
}