#ifndef ROBOTNOUVEAU_H
#define ROBOTNOUVEAU_H

#include "robot.h"

class robotNouveau : public robot {
public:
	virtual bool position(int x, int y) const final;

	virtual char typeObjet() const final;

};


#endif //ROBOTNOUVEAU_H
