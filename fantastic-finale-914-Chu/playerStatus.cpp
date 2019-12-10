//#include "playerStatus.h"
//
//PlayerStatus::PlayerStatus() { 
//
//	level = 0;
//    life = 0;
//    level_timer = 0;
//    adjusted = false;
//}
//
//void PlayerStatus::updateStatus(Platform collided) {
//    switch (collided.getType()) {
//        case NORMAL:
//            break;
//        case NAILS:
//            if (!adjusted) {
//                life--;
//                adjusted = true;
//            }
//            break;
//        case CONVEYORL:
//            if (!adjusted) {
//                life++;
//                adjusted = true;
//            }
//            break;
//        case CONVEYORR:
//
//            if (!adjusted) {
//                life++;
//                adjusted = true;
//            }
//            break;
//        case TRAMPOLINE:
//
//            if (!adjusted) {
//                life += 2;
//                adjusted = true;
//            }
//            break;
//        case FAKE:
//            if (!adjusted) {
//                life -= 2;
//                adjusted = true;
//            }
//            break;
//    }
//}
//
//void PlayerStatus::updateStatus(Platform collided) {
//
//}
//
//ofVec2f PlayerStatus::getLevel() {
//
//
//}