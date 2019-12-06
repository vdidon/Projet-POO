#ifndef JOUEURBASE_H
#define JOUEURBASE_H

#include "joueur.h"

class joueurBase : public joueur
{
    public :
        joueurBase() = default ;
        virtual bool deplace(int x, int y) override ;
};

#endif // JOUEURBASE_H
