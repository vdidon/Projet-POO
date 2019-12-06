#ifndef JOUEUR_H
#define JOUEUR_H

#include "objet.h"

class joueur : public objet
{
    public :
        virtual ~joueur() ; // Destructeur virtuel
        virtual bool deplace(int x, int y) = 0 ;
};

#endif // JOUEUR_H
