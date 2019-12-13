#ifndef ROBOTANCIEN_H
#define ROBOTANCIEN_H

#include "robot.h"

class robotAncien : public robot {
public:
	robotAncien() = default;

	virtual bool position(int x, int y) const final;

	char typeObjet() const final;
};


#endif //ROBOTANCIEN_H
