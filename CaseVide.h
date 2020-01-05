#ifndef CASEVIDE_H
#define CASEVIDE_H

#include "objet.h"

class CaseVide : public objet
{
    public :

        CaseVide() ;

        /**
            Méthode pour savoir si l'objet peut être déplacer (virtuelle)
        */
        virtual bool PeutAllerEn(int x, int y) const override ;

        /**
            Méthode pour connaître le type de l'objet (virtuelle)
        */
        virtual char typeObjet() const override ;
};

#endif // CASEVIDE_H
