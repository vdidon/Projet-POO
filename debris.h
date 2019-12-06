#ifndef DEBRIS_H
#define DEBRIS_H

#include "objet.h"

class debris : public objet
{
    public :
        debris() = default ;
        virtual bool deplace(int x, int y) override ;
};

#endif // DEBRIS_H
