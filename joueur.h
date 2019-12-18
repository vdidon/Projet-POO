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
        virtual localisation position() const = 0 ;

        /**
            Il faut rajouter la méthode pour le type de l'objet sinon erreur :
            obj\Debug\joueur.o:joueur.cpp:(.rdata$_ZTV6joueur[_ZTV6joueur]+0x28)||undefined reference to `objet::typeObjet() const'|
        */
        virtual char typeObjet() const override ;

        /**
            Méthode de objet ou terrain
        */
        /*static*/ bool evalCase(const Terrain &gr, int lig, int col) ;

        /*static*/ char testChoixUtilisateur(char choix, const string &phrase) ;
        /*static*/ void interactionJoueurExpert(int &x1, int &x2) ;
        /*static*/ void interactionJoueurBase(int &x1, int &x2) ;
        /*static*/ void echecMauvaisPas() ;
};

#endif // JOUEUR_H
