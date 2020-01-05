#ifndef CASEVIDE_H
#define CASEVIDE_H

#include "objet.h"

class CaseVide : public objet
{
    public :

        CaseVide() ;

        /**
            M�thode pour savoir si l'objet peut �tre d�placer (virtuelle)
        */
        virtual bool PeutAllerEn(int x, int y) const override ;

        /**
            M�thode pour conna�tre le type de l'objet (virtuelle)
        */
        virtual char typeObjet() const override ;
};

#endif // CASEVIDE_H
