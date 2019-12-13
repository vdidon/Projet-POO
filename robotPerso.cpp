//
// Created by vdido on 06/12/2019.
//

#include "robotPerso.h"
#include <cmath>

char robotPerso::typeObjet() const {
	return objet::TYPES::ROBOT_PERSO;
}

bool robotPerso::position(int x, int y) const {
	return abs(x) <= d_vitesse && abs(y) <= d_vitesse && bonneDirection(x, y);
}

bool robotPerso::bonneDirection(int dx, int dy) const {
	if (dx > 0) {
		if (dy < 0)
			return d_direction[1];
		else if (dy == 0)
			return d_direction[2];
		else
			return d_direction[3];
	} else if (dx == 0) {
		if (dy < 0)
			return d_direction[0];
		else if (dy == 0)
			return true;
		else
			return d_direction[4];
	} else {
		if (dy < 0)
			return d_direction[5];
		else if (dy == 0)
			return d_direction[6];
		else
			return d_direction[7];
	}

}

robotPerso::robotPerso(unsigned int vitesse, bool direction[8]) : d_vitesse{vitesse}, d_direction{direction} {}

