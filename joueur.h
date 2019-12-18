#ifndef JOUEUR_H
#define JOUEUR_H

#include "objet.h"

#include <string>
#include <iostream>

using std::cout ;
using std::endl ;
using std::cin ;
using std::string ;

class localisation ;
class Terrain ;

class joueur : public objet
{
    public :

        /**
            Herité de la classe objet
        */
        virtual ~joueur() ;
        virtual bool deplaceEn(int x, int y) = 0 ;
        virtual void tuer() = 0 ;
        virtual bool estVivant() const = 0 ;

        /**
            Méthode de objet ou terrain
        */
        bool evalCase(const Terrain &gr, int lig, int col) ;

        char testChoixUtilisateur(char choix, const string &phrase) ;
        void interactionJoueurExpert(int &x1, int &x2) ;
        void interactionJoueurBase(int &x1, int &x2) ;
        void echecMauvaisPas() ;
};

#endif // JOUEUR_H
