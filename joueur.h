#ifndef JOUEUR_H
#define JOUEUR_H

#include "objet.h"
#include<string>

using std::string;

class localisation;
class Terrain;
class joueur //: public objet cause des erreurs
{
    public :

        //heriter de objet
        virtual ~joueur() ;
        virtual bool deplaceEn(int x, int y) = 0 ;

        virtual void tuer()=0;
        virtual bool estVivant()const=0;
        virtual localisation position()const =0 ;

        static bool evalCase(const Terrain& gr,int lig,int col);// methode de objet ou terrain

        static char testChoixUtilisateur(char choix, const string &phrase);
        static void interactionJoueurExpert(int &x1, int &x2);
        static void interactionJoueurBase(int &x1, int &x2);
        static void echecMauvaisPas();
};

#endif // JOUEUR_H
