#ifndef JOUEUREXPERT_H
#define JOUEUREXPERT_H

#include "joueur.h"
#include "localisation.h"

class joueurExpert : public joueur
{
    public :

        joueurExpert(const char &Type_Joueur_Expert = objet::TYPES::JOUEUR_EXPERT) ;
        virtual bool deplaceEn(int x, int y) override ;
        virtual void tuer() override ;
        virtual bool estVivant() const override ;
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        virtual char typeObjet() const override ;

    private :

        bool d_vivant ;
        localisation d_coordonnee ;
};

#endif // JOUEUREXPERT_H
