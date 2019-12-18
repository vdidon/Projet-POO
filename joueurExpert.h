#ifndef JOUEUREXPERT_H
#define JOUEUREXPERT_H

#include "joueur.h"
#include "localisation.h"

class joueurExpert : public joueur
{
    public :

        joueurExpert() ;
        virtual bool deplaceEn(int x, int y) override ;
		virtual void tuer() override ;
        virtual bool estVivant() const override ;

        /**
            Méthode de la classe objet car
            joueurExpert est un joueur qui est lui-même un objet
        */
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        // Voir si utile virtual char typeObjet() const override ;

    private :

        bool d_vivant ;
        localisation d_coordonnee ;
};

#endif // JOUEUREXPERT_H
