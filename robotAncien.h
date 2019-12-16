#ifndef ROBOTANCIEN_H
#define ROBOTANCIEN_H

#include "robot.h"

class robotAncien : public robot {
public:
	virtual bool PeutAllerEn(int dx, int dy) const final;

	char typeObjet() const final;
};


#endif //ROBOTANCIEN_H
