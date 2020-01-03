#ifndef TERRAIN_H
#define TERRAIN_H

/** Bibliothèque "Standard" pour cout, cin, endl ... */
#include <iostream>

/** Pour ne pas avoir à écrire à chaque fois std::cout << ... mais just cout << ... */
using std::cout ;
using std::endl ;

#include <vector>

/** Bibliothèque pour les fichiers */
#include <fstream>

/** Classes Abstraites */
#include "objet.h"
#include "robot.h"
#include "joueur.h"

#include "debris.h"
#include "mur.h"
#include "CaseVide.h"

/** Classes dérivées de la classe joueur */
#include "joueurBase.h"
#include "joueurExpert.h"

/** Classes dérivées de la classe robot */
#include "robotAncien.h"
#include "robotNouveau.h"
#include "robotPerso.h"

class terrain
{
    public :

        /** Constructeur de la classe terrain
            @param hauteur - la hauteur du terrain
            @param largeur - la largeur du terrain
        */
        terrain(int hauteur = 0, int largeur = 0) ;

        /** Destructeur */
        ~terrain() = default ;

        /** Constructeur par recopie de la classe terrain
            @param t - un terrain à partir duquel on va construire le nouveau
        */
        terrain(const terrain &t) ;

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

        /** Fonction permettant de savoir si une case est bien dans le terrain
            @param l - La ligne de la case à vérifier
            @param c - La colonne de la case à vérifier
            @return Vrai si elle y est, Faux sinon
        */
        bool evalCase(int l, int c) const ;

        /** Fonction permettant de savoir si un caractère ne correpondant à aucun objet à été entré
            @param
            @return Vrai si le caractère est différents de tous les types d'objets, Faux sinon
        */
        bool CaractereInvalide(const char &TypeObjet) const ;

        /** Procédure permettant l'affichage du terrain de jeu
            @param t - Le terrain de jeu
        */
        void AffichageTerrain() const ;

        /** Procédure permettant de sauvegarder un terrain
            @param ost - un fichier pour sauvegarder le terrain
            @param NomFichier - le nom du fichier
        */
        void sauvegarder(const std::string &NomFichier) const ;

        /** Fonction permettant de lire un terrain
            @param NomFichier - le nom du fichier
            Le fichier est écrit de la façon suivante :
            10 10            (Hauteur et Largeur)
            0 0 J            (Joueur)
            2 5 A           (Robot de gen 1)
            2 6 P 01011      (Robot custom)
            1 3 D            (Débris)
            ...
        */
        terrain& chargerTerrain(const std::string &NomFichier) ;

        /** Méthode permettant de récuperer la case (x,y) du terrain
            @param x - La ligne de la case à récupérer
            @param y - La colonne de la case à récupérer
            @return Une case du tableau donc unpointeur sur un objet
        */
        objet* Case(int x, int y) const ;

        /** Méthode permettant de récuperer le type d'une case
            @param x - La ligne de la case à récupérer
            @param y - La colonne de la case à récupérer
            @return Un caratcère qui est le type de l'objet
        */
        char typeCase(int lig, int col) const ;

        /** Procédure permettant d'ajouter un objet dans le terrain
            @param ligne - la ligne de la case du type de l'objet à changer
            @param colonne - la colonne de la case du type de l'objet à changer
        */
        void AjouterObjet(int ligne, int colonne, const char &Type_Objet) ;

		/** Permet de déplacer un objet de coordonnées (x1, y1) en (x2, y2)
            @param x1 - Coordonnées x de départ de l'objet
            @param y1 - Coordonnées y de départ de l'objet
            @param x2 - Coordonnées x d'arrivée de l'objet
            @param y2 - Coordonnées y d'arrivée de l'objet
		*/
		void deplacerObjet(int x1, int y1, int x2, int y2) ;

    private :

        std::vector <std::vector <objet*>> d_tableau ;

        /** Procédure permettant supprimer tous les objets du terrain */
        void viderLeTerrain() ;
};

#endif // TERRAIN_H
