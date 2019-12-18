#ifndef MUR_H
#define MUR_H

#include "objet.h"

class mur : public objet
{
    public :

        /** Remarque fausse : Pas de constructeur ici
            car le constructeur est le m�me qu'objet
            ==> Avoir s'il en faut un
        */
        /* Cosntructeur ??? */

        /**
            M�thode pour savoir si l'objet peut �tre d�placer (virtuelle)
        */
        // Pose une erreur si on le d�commente
        virtual bool PeutAllerEn(int x, int y) override ;

        /**
            M�thode pour conna�tre le type de l'objet (virtuelle)
        */
        virtual char typeObjet() const override ;
};

#endif // MUR_H
