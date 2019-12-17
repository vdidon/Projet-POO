#ifndef ROBOTANCIEN_H
#define ROBOTANCIEN_H

#include "robot.h"

class robotAncien : public robot {
public:
	robotAncien() = default;

	virtual ~robotAncien();

	virtual bool PeutAllerEn(int dx, int dy) const override;

	char typeObjet() const final;
};


#endif //ROBOTANCIEN_H
