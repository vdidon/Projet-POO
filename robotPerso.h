#ifndef ROBOTPERSO_H
#define ROBOTPERSO_H

#include "robot.h"

class robotPerso : public robot {
public:
	robotPerso(unsigned int vitesse, bool direction[8]);

	virtual ~robotPerso() override ;

	virtual bool PeutAllerEn(int dx, int dy) const override;

	virtual char typeObjet() const final;

	unsigned int get_vitesse() const;

	bool* get_direction();

private:
	/**
            Vitesse du robot à chaque tour
        */
	unsigned int d_vitesse ;

	/**
		Directions dans lesquels peut se déplacer un robot
		Verticalement (1ère case) puis dans le sens des aiguilles d'une montre
	*/
	bool d_direction[8] ;

	bool bonneDirection(int dx, int dy) const;
};


#endif //ROBOTPERSO_H
