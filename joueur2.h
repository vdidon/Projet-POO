#ifndef JOUEUR2_H
#define JOUEUR2_H

#include "joueur.h"

class joueur2 : public joueur
{
    public :
        joueur2() = default ;
        virtual bool deplace(int x, int y) override ;
};

#endif // JOUEUR2_H
