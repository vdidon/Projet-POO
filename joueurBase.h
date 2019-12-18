#ifndef JOUEURBASE_H
#define JOUEURBASE_H

#include "joueur.h"
#include "localisation.h"

class joueurBase : public joueur
{
    public :

        joueurBase() ;
        virtual bool deplaceEn(int x, int y) override ;
        virtual void tuer() override ;
        virtual bool estVivant() const override ;

        /**
            Méthode de la classe objet car
            joueurBase est un joueur qui est lui-même un objet
        */
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        //Voir si utlise virtual char typeObjet() const override ;

    private :

        bool d_vivant ;
        localisation d_coordonnee ;
};

#endif // JOUEURBASE_H
