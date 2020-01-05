#ifndef JEU_H
#define JEU_H

#include "terrain.h"

#include <iostream>
#include <string>

using std::cout ;
using std::cin ;
using std::endl ;

class jeu
{
    public :

        /**
            Initialise la classe jeu
        */
        jeu() ;

        /**
            Lance le menu principal du jeu
        */
        void run() ;

    private :

        /**
            Lance une partie de jeu
        */
        void lancerJeu() ;

        /**
            Permet d'accéder au menu de configuration du jeu
        */
        void configuration() ;

        /**
            Permet d'accéder au menu de customisation du terrain
        */
        void customiserTerrain() ;

        terrain d_terrain ;
};

#endif // JEU_H
