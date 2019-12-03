#include "background.h"

Background::Background() {

}

Background::~Background() {

}

void Background::Load() {

    _ceiling.load("ceiling.png");
    _left_wall.load("wall.png");
    _right_wall.load("wall.png");
}
void Background::Draw(float height, float width) {
    _ceiling.draw(_object_size, 0, width - _object_size, _object_size);
    _left_wall.draw(0, 0, _object_size, height);
    _right_wall.draw(width - _object_size, 0, _object_size, height);
}
