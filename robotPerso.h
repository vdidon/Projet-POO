#ifndef ROBOTPERSO_H
#define ROBOTPERSO_H

#include "robot.h"

class robotPerso : public robot {
public:
	robotPerso(unsigned int vitesse, bool direction[8]);

	virtual bool PeutAllerEn(int dx, int dy) const override;

	virtual char typeObjet() const final;

private:
	unsigned int d_vitesse; // vitesse du robot à chaque tour

	bool d_direction[8]; // directions dans les quels peut se déplacé le robot,
	// vers le haut en premier puis le sens horaire

	bool bonneDirection(int dx, int dy) const;
};


#endif //ROBOTPERSO_H
