#ifndef ROBOTNOUVEAU_H
#define ROBOTNOUVEAU_H

#include "robot.h"

class robotNouveau : public robot {
public:
	virtual bool PeutAllerEn(int dx, int dy) const override;

	virtual char typeObjet() const final;

};


#endif //ROBOTNOUVEAU_H
