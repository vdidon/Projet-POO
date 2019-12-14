#ifndef JOUEUREXPERT_H
#define JOUEUREXPERT_H

#include "joueur.h"

class joueurExpert : public joueur
{
    public :
        joueurExpert(const localisation &pos);
        virtual bool deplaceEn(int x, int y) override ;
};

#endif // JOUEUREXPERT_H
