#ifndef JOUEURBASE_H
#define JOUEURBASE_H

#include "joueur.h"
#include "localisation.h"
#include "objet.h"


class joueurBase : public joueur
{
    public :

        joueurBase(const char &Type_Joueur_Base = objet::TYPES::JOUEUR_BASE) ;
        virtual bool deplaceEn(int x, int y) override ;
        virtual void tuer() override ;
        virtual bool estVivant() const override ;
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        virtual char typeObjet() const override ;

    private :

        bool d_vivant ;
        localisation d_coordonnee ;
};

#endif // JOUEURBASE_H
