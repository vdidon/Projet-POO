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

        /**
            Permet de vérifier s'il y a déplacement ou destruction d'un objet
            @param x1 - Coordonnées x de départ de l'objet
            @param y1 - Coordonnées y de départ de l'objet
            @param x2 - Coordonnées x d'arrivée de l'objet
            @param y2 - Coordonnées y d'arrivée de l'objet
            @return true si le robot ecrase le joueur
        */
        bool verificationDeplacement(int x1, int y1, int x2, int y2);

        terrain d_terrain ;
};

#endif // JEU_H
