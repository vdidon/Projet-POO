#ifndef DEBRIS_H
#define DEBRIS_H

#include "objet.h"

class debris : public objet
{
    public :

        debris() ;

        /**
            M�thode pour savoir si l'objet peut �tre d�placer (virtuelle)
        */
        virtual bool PeutAllerEn(int x, int y) const override ;

        /**
            M�thode pour conna�tre le type de l'objet (virtuelle)
        */
        // Voir si utile
        //virtual char typeObjet() const override ;
};

#endif // DEBRIS_H
