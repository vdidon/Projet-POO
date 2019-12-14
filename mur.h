#ifndef MUR_H
#define MUR_H

#include "objet.h"

class mur : public objet
{
    public :
        mur() = default ; //Constructeur par défaut
        virtual bool PeutAllerEn(int x, int y) override ; //Méthode pour savoir si l'objet peut être déplacer (virtuelle)
        virtual char typeObjet() const override; //Méthode pour connaître le type de l'objet (virtuelle)

    private :
        ... ;
};


#endif // MUR_H
