#include "robotNouveau.h"
#include <cmath>

robotNouveau::~robotNouveau() {}

char robotNouveau::typeObjet() const {
	return objet::TYPES::ROBOT_NOUVEAU;
}

bool robotNouveau::PeutAllerEn(int dx, int dy) const {
	return abs(dx) <= 1 && abs(dy) <= 1;
}
