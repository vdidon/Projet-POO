#ifndef DEBRIS_H
#define DEBRIS_H

#include "objet.h"

class debris : public objet
{
    public : //Pas de constructeur ici car le constructeur est le même qu'objet
        virtual bool PeutAllerEn(int x, int y) override ; //Méthode pour savoir si l'objet peut être déplacer (virtuelle)
        virtual char typeObjet() const override; //Méthode pour connaître le type de l'objet (virtuelle)
};

#endif // DEBRIS_H
