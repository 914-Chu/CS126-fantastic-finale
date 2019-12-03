#pragma once
#include "ofImage.h"

class Background {
	
	public:
		Background();
        ~Background();
        void Load();
        void Draw(float height, float width);

		ofImage _ceiling;
        ofImage _left_wall;
        ofImage _right_wall;
        float _object_size = 30;
};
