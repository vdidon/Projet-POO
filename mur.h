#ifndef MUR_H
#define MUR_H

#include "objet.h"
#include "localisation.h"

class mur : public objet
{
    public :

        mur(const char &Type_Mur = objet::TYPES::MUR) ;

        /**
            M�thode pour savoir si l'objet peut �tre d�placer (virtuelle)
        */
        virtual bool PeutAllerEn(int x, int y) const override ;

        /**
            M�thode pour conna�tre le type de l'objet (virtuelle)
        */
        virtual char typeObjet() const override ;
};

#endif // MUR_H
