#ifndef ROBOTNOUVEAU_H
#define ROBOTNOUVEAU_H

#include "robot.h"



class robotNouveau : public robot
{
    public :

        robotNouveau() = default ;
        virtual ~robotNouveau() override ;
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        //Voir si utile virtual char typeObjet() const override ;
};

#endif // ROBOTNOUVEAU_H
