#ifndef JOUEUR1_H
#define JOUEUR1_H

#include "joueur.h"

class joueur1 : public joueur
{
    public :
        joueur1() = default ;
        virtual bool deplace(int x, int y) override ;
};

#endif // JOUEUR1_H
