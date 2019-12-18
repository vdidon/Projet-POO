#ifndef ROBOT_H
#define ROBOT_H

#include "objet.h"

class robot : public objet
{
    public :

        virtual ~robot() ;
        virtual bool PeutAllerEn(int dx, int dy) const = 0 ;
};

#endif // ROBOT_H
