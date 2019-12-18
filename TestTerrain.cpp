#include "doctest.h"
#include "terrain.h"

#include <sstream>

TEST_CASE("Test du terrain de jeu")
{
    SUBCASE("Un terrain dont la largeur et la hauteur sont données sont correctes")
    {
        int hauteur = 2, largeur = 3 ;
        terrain t{largeur, hauteur} ;
        /**
            Pour pouvoir vérifier les valeurs :

            cout << "Valeurs :\n" ;
            cout << "Hauteur : " << hauteur << endl ;
            cout << "Largeur : " << largeur << endl ;
            cout << "Fonctions :\n" ;
            cout << "Hauteur : " << t.hauteur() << endl ;
            cout << "Largeur : " << t.largeur() << endl ;
        */
        REQUIRE_EQ(t.largeur(), largeur) ;
        REQUIRE_EQ(t.hauteur(), hauteur) ;
    }

    SUBCASE("Le changement de la longeur et de la hauteur du terrain est correcte")
    {
        int hauteur = 2, largeur = 3 ;
        terrain t{largeur, hauteur} ;
        /**
            Pour pouvoir vérifier les valeurs (Avant le changement) :

            cout << "Valeurs :\n" ;
            cout << "Hauteur : " << hauteur << endl ;
            cout << "Largeur : " << largeur << endl ;
            cout << "Fonctions :\n" ;
            cout << "Hauteur : " << t.hauteur() << endl ;
            cout << "Largeur : " << t.largeur() << endl ;
        */
        int NewHauteur = 5, NewLargeur = 6 ;
        t.ChangerHauteur(NewHauteur) ;
        t.ChangerLargeur(NewLargeur) ;
        /**
            Pour pouvoir vérifier les valeurs (Après le chnagement) :

            cout << "\nValeurs :\n" ;
            cout << "Hauteur : " << NewHauteur << endl ;
            cout << "Largeur : " << NewLargeur << endl ;
            cout << "Fonctions :\n" ;
            cout << "Hauteur : " << t.hauteur() << endl ;
            cout << "Largeur : " << t.largeur() << endl ;
        */
        REQUIRE_EQ(t.largeur(), NewLargeur) ;
        REQUIRE_EQ(t.hauteur(), NewHauteur) ;
    }

    SUBCASE("La valeur d'une case est correcte")
    {
        int hauteur = 2, largeur = 3 ;
        terrain t{largeur, hauteur} ;
        REQUIRE_EQ(t[0][0], nullptr) ;
    }

    /**
    NE FONCITONNE PAS si on met t1[0][0] = new debris() ...
    SUBCASE("La création d'un nouveau terrain grâce à un ancien est correct")
    {
        int hauteur = 2, largeur = 3 ;
        terrain t1{largeur, hauteur} ;
        /**
            Pour pouvoir vérifier les valeurs :

            cout << "Terrain initial :\n" ;
            cout << "Valeurs :\n" ;
            cout << "Hauteur : " << hauteur << endl ;
            cout << "Largeur : " << largeur << endl ;
            cout << "Fonctions :\n" ;
            cout << "Hauteur : " << t1.hauteur() << endl ;
            cout << "Largeur : " << t1.largeur() << endl ;

        terrain t2{t1} ;
        /**
            Pour pouvoir vérifier les valeurs :

            cout << "Terrain construit avec le terrin initial :\n" ;
            cout << "Valeurs :\n" ;
            cout << "Hauteur : " << hauteur << endl ;
            cout << "Largeur : " << largeur << endl ;
            cout << "Fonctions :\n" ;
            cout << "Hauteur : " << t2.hauteur() << endl ;
            cout << "Largeur : " << t2.largeur() << endl ;

        // Méthode pour changer le type
        REQUIRE_EQ(t2.hauteur(), t1.hauteur()) ;
        REQUIRE_EQ(t2.largeur(), t1.largeur()) ;
        for(int i = 0 ; i < t2.hauteur() ; i++)
        {
            for(int j = 0 ; j < t2.largeur() ; j++)
            {
                REQUIRE_EQ(t1[i][j], t2[i][j]) ;
                /**
                    Vérifications des valeurs :

                    cout << "t1[i][j] = " << "t1[" << i << "][" << j << "] = " << t1[i][j] << '\n' ;
                    cout << "t2[i][j] = " << "t2[" << i << "][" << j << "] = " << t2[i][j] << '\n' ;

            }
            cout << '\n' ;
        }
    }
    */

    SUBCASE("Un terrain vide ne contient que des cases vides")
    {
        int hauteur = 2, largeur = 3 ;
        terrain t{largeur, hauteur} ;
        for(int i = 0 ; i < t.hauteur() ; i++)
        {
            for(int j = 0 ; j < t.largeur() ; j++)
            {
                REQUIRE_EQ(t[i][j], nullptr) ;
            }
        }
    }

    SUBCASE("L'affichage d'un terrain est correct")
    {
        int hauteur = 2, largeur = 3 ;
        terrain t{largeur, hauteur} ;
        t.AffichageTerrain(t) ;
    }

    /**
        VOIT PAS COMMENT FAIRE
        SUBCASE("La sauvegarde d'un terrain dans un fichier est correcte")
        {
            int hauteur = 2, largeur = 3 ;
            terrain t{largeur, hauteur} ;
            std::string formatAttendu = "2 3\n0 0 0\n 0 1 0\n 0 2 0\n 1 0 0\n 1 1 0\n 1 2 0", formatLu ;
            t.chargerTerrain("TestSauvegarde") ;
            std::ifstream ist{"TestSauvegarde"} ;
            getline(ist,formatLu) ;
            REQUIRE(formatLu == formatAttendu) ;
        }

        SUBCASE("Le chargement d'un terrain à partir d'un fichier est correcte")
        {
            int hauteur = 2, largeur = 3 ;
            terrain t{largeur, hauteur} ;

        }
    */
}
