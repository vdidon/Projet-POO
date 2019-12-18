#ifndef DEBRIS_H
#define DEBRIS_H

#include "objet.h"

class debris : public objet
{
    public :

        debris() ;

        /**
            Méthode pour savoir si l'objet peut être déplacer (virtuelle)
        */
        virtual bool PeutAllerEn(int x, int y) const override ;

        /**
            Méthode pour connaître le type de l'objet (virtuelle)
        */
        // Voir si utile
        //virtual char typeObjet() const override ;
};

#endif // DEBRIS_H
