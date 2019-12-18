#ifndef JOUEUREXPERT_H
#define JOUEUREXPERT_H

#include "joueur.h"

class joueurExpert : public joueur
{
    public :
        virtual bool PeutAllerEn(int dx, int dy)const override ;
};

#endif // JOUEUR1_H

