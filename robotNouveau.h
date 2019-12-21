#ifndef ROBOTNOUVEAU_H
#define ROBOTNOUVEAU_H

#include "robot.h"

class robotNouveau : public robot
{
    public :

        robotNouveau(const char &Type_robot_Nouveau = objet::TYPES::ROBOT_NOUVEAU) ;
        virtual ~robotNouveau() override ;
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        virtual char typeObjet() const override ;
};

#endif // ROBOTNOUVEAU_H
