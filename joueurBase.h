#ifndef JOUEURBASE_H
#define JOUEURBASE_H

#include "joueur.h"

class joueurBase : public joueur
{
    public :
       virtual bool PeutAllerEn(int dx, int dy)const override ;

};

#endif // JOUEUR1_H
