#include "life.h"

Life::Life() {

}

Life::~Life() {}

void Life::Update(bool hurt, int level) {

	if (hurt) {
        life--;
    }

	if (level % 5 == 0) {
        life++;
	}
}

int Life::GetCurrentLife() { return life; }
