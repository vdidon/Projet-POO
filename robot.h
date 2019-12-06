#ifndef ROBOT_H
#define ROBOT_H

#include "objet.h"


// Faire d'autres classes pour les 2 types de robots


// Avoir une class robot customisable à la fin si on a le temps

class robot : public object
{
    public :
        robot() = default ;
        virtual bool deplace(int x, int y) override ;
};

#endif // ROBOT_H
