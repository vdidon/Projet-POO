#include "robotAncien.h"
#include <cmath>

bool robotAncien::position(int x, int y) const {
	return !(x && y) && abs(x) <= 1 && abs(y) <= 1;
}

char robotAncien::typeObjet() const {
	return objet::TYPES::ROBOT_ANCIEN;
}
