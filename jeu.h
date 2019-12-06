#ifndef JEU_H
#define JEU_H

#include "terrain.h"

class jeu
{
    public :
        jeu() ;
        void run() ;

        // int score() ;

    private :
        //int d_score ; // Si on a le temps
        terrain d_terrain ;
};

#endif // JEU_H
