#ifndef JOUEURBASE_H
#define JOUEURBASE_H

#include "joueur.h"
#include "objet.h"

class joueurBase : public joueur
{
    public :

        joueurBase() ;
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        virtual char typeObjet() const override ;
};

#endif // JOUEURBASE_H
