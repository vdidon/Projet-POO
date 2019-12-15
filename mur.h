#ifndef MUR_H
#define MUR_H

#include "objet.h"

class mur : public objet
{
    public : //Pas de constructeur ici car le constructeur est le m�me qu'objet
        virtual bool PeutAllerEn(int x, int y) override ; //M�thode pour savoir si l'objet peut �tre d�placer (virtuelle)
        virtual char typeObjet() const override; //M�thode pour conna�tre le type de l'objet (virtuelle)
};


#endif // MUR_H
