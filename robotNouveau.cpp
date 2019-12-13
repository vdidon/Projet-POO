#include <cmath>
#include "robotNouveau.h"

bool robotNouveau::position(int x, int y) const {
	return abs(x) <= 1 && abs(y) <= 1;
}

char robotNouveau::typeObjet() const {
	return objet::TYPES::ROBOT_NOUVEAU;
}
