#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <vector>

#include "objet.h"

/*#include "joueur.h"
#include "robot.h"
#include "mur.h"
#include "debris.h"*/

class terrain
{
    public :
        terrain(int largeur, int hauteur) ; // Constructeur par défaut
        terrain(const terrain &t) ;  // Constructeur par recopie
        void chargerTerrain(istream &ist) ;   //Charge une configuration écrit de façon :
                                                    /**
                                                        0 0 J            (Joueur)
                                                        2 5 R1           (Robot de gen 1)
                                                        2 6 R 01011      (Robot custom)
                                                        1 3 D            (Débris)
                                                    */
        // static terrain& creer(istream &ist) ; A VOIR SI UTILE (= chargerTerrain)
        void sauvegarder(ostream &ost) const ; // Sauvegarder une config vers un fichier
        int hauteur() const ;    // Return la hauteur
        int largeur() const ;    // Return la largeur
        void resizeHauteur(int x) ;  // Pour changer la hauteur
        void resizeLargeur(int y) ;  // Pour changer la largeur
        vector <objet*>& operator[](int i) ; // accès a d_tableau
        private:
            //int d_largeur, d_hauteur ;
            vector <vector <objet*>> d_tableau ;
};

#endif // TERRAIN_H
