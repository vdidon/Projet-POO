#ifndef TERRAIN_H
#define TERRAIN_H

/** Biblioth�que "Standard" pour cout, cin, endl ... */
#include <iostream>

/** Pour ne pas avoir � �crire � chaque fois std::cout << ... mais just cout << ... */
using std::cout ;
using std::endl ;

#include <vector>

/** Biblioth�que pour les fichiers */
#include <fstream>

/** Classes Abstraites */
#include "objet.h"
#include "robot.h"
#include "joueur.h"

#include "debris.h"
#include "mur.h"
#include "CaseVide.h"

/** Classes d�riv�es de la classe joueur */
#include "joueurBase.h"
#include "joueurExpert.h"

/** Classes d�riv�es de la classe robot */
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
            @param t - un terrain � partir duquel on va construire le nouveau
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

        /** Proc�dure changeant la hauteur du terrain */
        void ChangerHauteur(int x) ;

        /** Proc�dure changeant la Largeur du terrain */
        void ChangerLargeur(int y) ;

        /** Fonction permettant de savoir si une case est bien dans le terrain
            @param l - La ligne de la case � v�rifier
            @param c - La colonne de la case � v�rifier
            @return Vrai si elle y est, Faux sinon
        */
        bool evalCase(int l, int c) const ;

        /** Fonction permettant de savoir si un caract�re ne correpondant � aucun objet � �t� entr�
            @param
            @return Vrai si le caract�re est diff�rents de tous les types d'objets, Faux sinon
        */
        bool CaractereInvalide(const char &TypeObjet) const ;

        /** Proc�dure permettant l'affichage du terrain de jeu
            @param t - Le terrain de jeu
        */
        void AffichageTerrain() const ;

        /** Proc�dure permettant de sauvegarder un terrain
            @param ost - un fichier pour sauvegarder le terrain
            @param NomFichier - le nom du fichier
        */
        void sauvegarder(const std::string &NomFichier) const ;

        /** Fonction permettant de lire un terrain
            @param NomFichier - le nom du fichier
            Le fichier est �crit de la fa�on suivante :
            10 10            (Hauteur et Largeur)
            0 0 J            (Joueur)
            2 5 A           (Robot de gen 1)
            2 6 P 01011      (Robot custom)
            1 3 D            (D�bris)
            ...
        */
        terrain& chargerTerrain(const std::string &NomFichier) ;

        /** M�thode permettant de r�cuperer la case (x,y) du terrain
            @param x - La ligne de la case � r�cup�rer
            @param y - La colonne de la case � r�cup�rer
            @return Une case du tableau donc unpointeur sur un objet
        */
        objet* Case(int x, int y) const ;

        /** M�thode permettant de r�cuperer le type d'une case
            @param x - La ligne de la case � r�cup�rer
            @param y - La colonne de la case � r�cup�rer
            @return Un caratc�re qui est le type de l'objet
        */
        char typeCase(int lig, int col) const ;

        /** Proc�dure permettant d'ajouter un objet dans le terrain
            @param ligne - la ligne de la case du type de l'objet � changer
            @param colonne - la colonne de la case du type de l'objet � changer
        */
        void AjouterObjet(int ligne, int colonne, const char &Type_Objet) ;

		/** Permet de d�placer un objet de coordonn�es (x1, y1) en (x2, y2)
            @param x1 - Coordonn�es x de d�part de l'objet
            @param y1 - Coordonn�es y de d�part de l'objet
            @param x2 - Coordonn�es x d'arriv�e de l'objet
            @param y2 - Coordonn�es y d'arriv�e de l'objet
		*/
		void deplacerObjet(int x1, int y1, int x2, int y2) ;

    private :

        std::vector <std::vector <objet*>> d_tableau ;

        /** Proc�dure permettant supprimer tous les objets du terrain */
        void viderLeTerrain() ;
};

#endif // TERRAIN_H
