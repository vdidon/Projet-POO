#ifndef JOUEUREXPERT_H
#define JOUEUREXPERT_H

#include "joueur.h"

class joueurExpert : public joueur
{
    public :
        joueurExpert() = default ;
        virtual bool deplace(int x, int y) override ;
};

#endif // JOUEUREXPERT_H
