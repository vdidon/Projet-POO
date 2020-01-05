#ifndef ROBOTANCIEN_H
#define ROBOTANCIEN_H

#include "robot.h"

class robotAncien : public robot
{
    public :

        robotAncien() ;
        ~robotAncien() override ;
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        virtual char typeObjet() const override ;
};

#endif // ROBOTANCIEN_H
