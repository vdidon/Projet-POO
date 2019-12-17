#ifndef TERRAIN_H
#define TERRAIN_H

/** Bibliothèque "Standard" pour cout, cin, endl ... */
#include <iostream>

/** Pour ne pas avoir à écrire à chaque fois std::cout << ... mais just cout << ... */
using std::cout ;

#include <vector>

/** Bibliothèque pour les fichiers */
#include <fstream>

/** Classes Abstraites */
#include "objet.h"
#include "robot.h"
#include "joueur.h"

#include "debris.h"
#include "mur.h"

/** Classes dérivées de la classe joueur */
#include "joueurBase.h"
#include "joueurExpert.h"

/** Classes dérivées de la classe robot */
#include "robotAncien.h"
#include "robotNouveau.h"
#include "robotPerso.h"

#include "localisation.h"

class terrain
{
    public :
        /** Constructeur de la classe terrain
            @param Largeur - la largeur du terrain
            @param Hauteur - la hauteur du terrain
        */
        terrain(int largeur, int hauteur) ;

        /** Constructeur par recopie de la classe terrain
            @param t - un terrain à partir duquel on va construire le nouveau
        */
        terrain(terrain &t) ;

        /** Procédure permettant de lire un terrain
            @param NomFichier - le nom du fichier
            Le fichier est écrit de la façon suivante :
            10 10            (Hauteur et Largeur)
            0 0 J            (Joueur)
            2 5 A           (Robot de gen 1)
            2 6 P 01011      (Robot custom)
            1 3 D            (Débris)
            ...
        */
        terrain chargerTerrain(const std::string &NomFichier) ;

        /** Procédure permettant de sauvegarder un terrain
            @param ost - un fichier pour sauvegarder le terrain
            @param NomFichier - le nom du fichier
        */
        void sauvegarder(const std::string &NomFichier) const ;

        /** Fonction retournant la hauteur du terrain
            @return un entier qui sera la hauteur du terrain
        */
        int hauteur() const ;

        /** Fonction retournant la largeur du terrain
            @return un entier qui sera la largeur du terrain
        */
        int largeur() const ;

        /** Procédure changeant la hauteur du terrain */
        void ChangerHauteur(int x) ;

        /** Procédure changeant la Largeur du terrain */
        void ChangerLargeur(int y) ;

        /** Procédure permettant l'affichage du terrain de jeu
            @param t - Le terrain de jeu
        */
        void AffichageTerrain(const terrain &t) const ;

        /** Méthode nous permettant d'accéder en lecture / écriture d'une case du tableau d'objet du terrain
            @param i - L'indice de la case que nous voulons renvoyer
            @return une case du tableau (exemple : .)
        */
        std::vector <objet*>& operator[](int i) ;

        private :

            std::vector <std::vector <objet*>> d_tableau ;
};

#endif // TERRAIN_H
