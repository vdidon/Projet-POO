#ifndef JEU_H
#define JEU_H

#include "terrain.h"

// A voir si on aura besoin d'autres #include

class jeu
{
    public :

        jeu() ;
        void run() ;
        // int score() ;

    private :

        // Si on a le temps
        //int d_score ;
        terrain d_terrain ;
};

#endif // JEU_H
