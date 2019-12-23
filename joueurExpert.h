#ifndef JOUEUREXPERT_H
#define JOUEUREXPERT_H

#include "joueur.h"

class joueurExpert : public joueur
{
    public :

        joueurExpert(const char &Type_Joueur_Expert = objet::TYPES::JOUEUR_EXPERT) ;
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        virtual char typeObjet() const override ;

    private :

        char d_type ;
};

#endif // JOUEUREXPERT_H
