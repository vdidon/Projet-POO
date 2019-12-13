#ifndef MUR_H
#define MUR_H

#include "objet.h"

class mur : public objet
{
    public :
        mur() = default ; //Constructeur par d�faut
        virtual bool PeutAllerEn(int x, int y) override ; //M�thode pour savoir si l'objet peut �tre d�placer (virtuelle)
        virtual char typeObjet() const override; //M�thode pour conna�tre le type de l'objet (virtuelle)

    private :
        ... ;
};


#endif // MUR_H
