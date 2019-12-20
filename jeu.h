#ifndef JEU_H
#define JEU_H

#include "terrain.h"
#include <iostream>
#include <string>

// A voir si on aura besoin d'autres #include

class jeu
{
    public :

        jeu() ;
        void run() ;
        // int score() ;

    private :
        // Lance une partie du jeu :
        void lancerJeu();
        //Accède aux configuration :
        void configuration();
        // Permet de customiser le terrain :
        void customiserTerrain();

        // Si on a le temps
        //int d_score ;
        terrain d_terrain ;
};

#endif // JEU_H
