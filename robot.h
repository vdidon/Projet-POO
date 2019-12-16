#ifndef ROBOT_H
#define ROBOT_H

#include "objet.h"


// Faire d'autres classes pour les 2 types de robots


// Avoir une class robot customisable à la fin si on a le temps

class robot : public objet {
public :
	virtual bool PeutAllerEn(int dx, int dy) const override = 0;

	virtual char typeObjet() const override;
};

#endif // ROBOT_H
