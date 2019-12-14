#ifndef DEBRIS_H
#define DEBRIS_H

#include "objet.h"

class debris : public objet
{
    public :
        debris() = default ; //Constructeur par d�faut
        virtual bool PeutAllerEn(int x, int y) override ; //M�thode pour savoir si l'objet peut �tre d�placer (virtuelle)
        virtual char typeObjet() const override; //M�thode pour conna�tre le type de l'objet (virtuelle)
};

#endif // DEBRIS_H
