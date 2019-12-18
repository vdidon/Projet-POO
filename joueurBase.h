#ifndef JOUEURBASE_H
#define JOUEURBASE_H

#include "joueur.h"
#include "localisation.h"

class joueurBase : public joueur
{
    public :

        joueurBase(const localisation &pos) ;
        virtual bool deplaceEn(int x, int y) override ;
        virtual void tuer() override ;
        virtual bool estVivant() const override ;
        virtual localisation position() const override ;

    private :

        bool d_vivant ;
        localisation d_coordonnee ;
};

#endif // JOUEURBASE_H
