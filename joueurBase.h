#ifndef JOUEURBASE_H
#define JOUEURBASE_H

#include "joueur.h"
#include "objet.h"

class joueurBase : public joueur
{
    public :

        joueurBase(const char &Type_Joueur_Base) ;
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        virtual char typeObjet() const override ;

    private :

        char d_type ;
};

#endif // JOUEURBASE_H
