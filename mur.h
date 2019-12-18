#ifndef MUR_H
#define MUR_H

#include "objet.h"
#include "localisation.h"

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
        // Voir si utile virtual char typeObjet() const override ;

    private :

        localisation d_coordonnee ;
};

#endif // MUR_H
