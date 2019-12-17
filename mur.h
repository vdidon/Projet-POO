#ifndef MUR_H
#define MUR_H

#include "objet.h"

class mur : public objet
{
    public :

        /** Remarque fausse : Pas de constructeur ici
            car le constructeur est le même qu'objet
            ==> Avoir s'il en faut un
        */
        /* Cosntructeur ??? */

        /**
            Méthode pour savoir si l'objet peut être déplacer (virtuelle)
        */
        // Pose une erreur si on le décommente
        virtual bool PeutAllerEn(int x, int y) override ;

        /**
            Méthode pour connaître le type de l'objet (virtuelle)
        */
        virtual char typeObjet() const override ;
};

#endif // MUR_H
