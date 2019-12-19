#ifndef ROBOTANCIEN_H
#define ROBOTANCIEN_H

#include "robot.h"

#include <cmath>

class robotAncien : public robot
{
    public :

        robotAncien() = default ;
		virtual ~robotAncien() override ;
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        // Voir si utile virtual char typeObjet() const override ;
};

#endif // ROBOTANCIEN_H
