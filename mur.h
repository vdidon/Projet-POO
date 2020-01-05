#ifndef MUR_H
#define MUR_H

#include "objet.h"

class mur : public objet
{
    public :

        mur() ;

        /**
            Méthode pour savoir si l'objet peut être déplacer (virtuelle)
        */
        virtual bool PeutAllerEn(int x, int y) const override ;

        /**
            Méthode pour connaître le type de l'objet (virtuelle)
        */
        virtual char typeObjet() const override ;
};

#endif // MUR_H
