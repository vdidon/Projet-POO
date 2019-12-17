#include "robotAncien.h"
#include <cmath>

char robotAncien::typeObjet() const {
	return objet::TYPES::ROBOT_ANCIEN;
}

bool robotAncien::PeutAllerEn(int dx, int dy) const {
	return !(dx && dy) && abs(dx) <= 1 && abs(dy) <= 1;
}

robotAncien::~robotAncien() {

}
