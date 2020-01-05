#include "doctest.h"
#include "terrain.h"

#include <sstream>

TEST_CASE("L'initialisation du terrain est correct")
{
    SUBCASE("La construction du terrain est correcte")
    {
        SUBCASE("La construction avec les valeurs par défaut est correcte")
        {
            terrain t{} ;
            REQUIRE_EQ(t.hauteur(), 0) ;
            REQUIRE_EQ(t.largeur(), 0) ;
        }

        SUBCASE("En passant des valeurs, la construction est correcte")
        {
            terrain t{2, 2} ;
            REQUIRE_EQ(t.hauteur(), 2) ;
            REQUIRE_EQ(t.largeur(), 2) ;
        }
    }

    SUBCASE("Les dimensions d'un terrain construit sont correctes")
    {
        SUBCASE("Les dimensions par défaut sont correctes")
        {
            terrain t{} ;

            SUBCASE("La hauteur est correcte")
            {
                REQUIRE_EQ(t.hauteur(), 0) ;
            }

            SUBCASE("La hauteur par défaut est correcte")
            {
                REQUIRE_EQ(t.largeur(), 0) ;
            }
        }

        SUBCASE("La hauteur d'un terrain construit est correcte")
        {
            terrain t{2, 2} ;

            SUBCASE("La hauteur donnée en paramètres es correcte")
            {
                REQUIRE_EQ(t.hauteur(), 2) ;
            }

            SUBCASE("La largeur donnée en paramètres es correcte")
            {
                REQUIRE_EQ(t.largeur(), 2) ;
            }
        }
    }

    SUBCASE("Le changement des dimensions est correcte")
    {
        int NewHauteur = 3, NewLargeur = 8 ;

        SUBCASE("Sur un terrain construit par défaut (taille 0)")
        {
            terrain t{} ;
            t.ChangerHauteur(NewHauteur) ;
            t.ChangerLargeur(NewLargeur) ;
            REQUIRE_EQ(t.largeur(), NewLargeur) ;
            REQUIRE_EQ(t.hauteur(), NewHauteur) ;
        }

        SUBCASE("Sur un terrain construit avec des valeurs")
        {
            int OldHauteur = 2, OldLargeur = 1 ;
            terrain t{OldHauteur, OldLargeur} ;

            t.ChangerHauteur(NewHauteur) ;
            t.ChangerLargeur(NewLargeur) ;
            REQUIRE_EQ(t.largeur(), NewLargeur) ;
            REQUIRE_EQ(t.hauteur(), NewHauteur) ;
        }
    }
}

TEST_CASE("Les valeurs du terrain sont correctes")
{
    int hauteur = 2, largeur = 2 ;
    terrain t{hauteur, largeur} ;

    SUBCASE("La case donnée se situe dans le terrain")
    {
        REQUIRE_EQ(t.evalCase(hauteur, largeur), true) ;
    }

    SUBCASE("Un terrain vide ne contient que des cases vides")
    {
        for(int i = 0 ; i < t.hauteur() ; i++)
        {
            for(int j = 0 ; j < t.largeur() ; j++)
            {
                REQUIRE_EQ(t.typeCase(i, j), objet::TYPES::VIDE) ;
            }
        }
    }

    SUBCASE("L'ajout d'un objet ne correspondant a aucun type donné est correct (Affcihera une erreur)")
    {
        SUBCASE("Sur un terrain ne contenant que des cases vides")
        {
            cout << "Sur un terrain aux cases vides : \n" ;
            int LigneCaseAjoutObjet = 0, ColonneCaseAjoutObjet = 1 ;
            t.AjouterObjet(LigneCaseAjoutObjet, ColonneCaseAjoutObjet, 'L') ;
        }

        /** Pour sauter une ligne entre les affichages */
        cout << endl ;

        SUBCASE("Sur un terrain contenant un ou plusieurs objets")
        {
            SUBCASE("Sur un terrain avec 1 objet et le reste que des cases vides")
            {
                cout << "Sur un terrain avec 1 objet et des cases vides : \n" ;

                int IndiceLigneCaseAjoutObjet = 0, IndiceColonneCaseAjoutObjet = 0 ;

                t.AjouterObjet(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet, 'L') ;
            }

            /** Pour sauter une ligne entre les affichages */
            cout << endl ;

            SUBCASE("Sur un terrain avec 2 (ou un nombre inférieur à la taille du terrain) et le reste des cases vides (on a au moins 1 case vide)")
            {
                cout << "Sur un terrain avec 2 objets (ou plus) et des cases vides : \n" ;

                int IndiceLigneCaseAjoutObjet1 = 0, IndiceColonneCaseAjoutObjet1 = 0 ;
                int IndiceLigneCaseAjoutObjet2 = 0, IndiceColonneCaseAjoutObjet2 = 1 ;

                t.AjouterObjet(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1, 'L') ;
                cout << endl ;
                t.AjouterObjet(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2, 'L') ;
            }

            /** Pour sauter une ligne entre les affichages */
            cout << endl ;
        }
    }

    SUBCASE("Le type d'une case est correct")
    {
        SUBCASE("Sur un terrain ne contenant que des cases vides")
        {
            int IndiceLigneCaseVoulue = 0, IndiceColonneCaseVoulue = 1 ;
            REQUIRE_EQ(t.typeCase(IndiceLigneCaseVoulue, IndiceColonneCaseVoulue), objet::TYPES::VIDE) ;
        }

        SUBCASE("Sur un terrain contenant un ou plusieurs objets")
        {
            SUBCASE("Sur un terrain avec 1 objet et le reste que des cases vides")
            {
                int IndiceLigneCaseAjoutObjet = 0, IndiceColonneCaseAjoutObjet = 0 ;

                t.AjouterObjet(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet, objet::TYPES::MUR) ;
                REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet), objet::TYPES::MUR) ;

                for(int i = 0 ; i < t.hauteur() ; i++)
                {
                    for(int j = 1 ; j < t.largeur() ; j++)
                    {
                        REQUIRE_EQ(t.typeCase(i, j), objet::TYPES::VIDE) ;
                    }
                }
            }

            SUBCASE("Sur un terrain avec 2 (ou un nombre inférieur à la taille du terrain) et le reste des cases vides (on a au moins 1 case vide)")
            {
                int IndiceLigneCaseAjoutObjet1 = 0, IndiceColonneCaseAjoutObjet1 = 0 ;
                int IndiceLigneCaseAjoutObjet2 = 0, IndiceColonneCaseAjoutObjet2 = 1 ;

                t.AjouterObjet(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1, objet::TYPES::MUR) ;
                REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1), objet::TYPES::MUR) ;

                t.AjouterObjet(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2, objet::TYPES::DEBRIS) ;
                REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2), objet::TYPES::DEBRIS) ;

                for(int i = 0 ; i < t.hauteur() ; i++)
                {
                    for(int j = IndiceColonneCaseAjoutObjet2 + 1 ; j < t.largeur() ; j++)
                    {
                        REQUIRE_EQ(t.typeCase(i, j), objet::TYPES::VIDE) ;
                    }
                }
            }

            SUBCASE("Sur un terrain ne contenant que des objets")
            {
                t.AjouterObjet(0, 0, objet::TYPES::MUR) ;
                REQUIRE_EQ(t.typeCase(0, 0), objet::TYPES::MUR) ;

                t.AjouterObjet(0, 1, objet::TYPES::JOUEUR_EXPERT) ;
                REQUIRE_EQ(t.typeCase(0, 1), objet::TYPES::JOUEUR_EXPERT) ;

                t.AjouterObjet(1, 0, objet::TYPES::JOUEUR_BASE) ;
                REQUIRE_EQ(t.typeCase(1, 0), objet::TYPES::JOUEUR_BASE) ;

                t.AjouterObjet(1, 1, objet::TYPES::ROBOT_ANCIEN) ;
                REQUIRE_EQ(t.typeCase(1, 1), objet::TYPES::ROBOT_ANCIEN) ;
            }
        }
    }

    SUBCASE("Le changement du type de la case, donc de l'objet est correct")
    {
        SUBCASE("Sur un terrain contenant un ou plusieurs objets")
        {
            SUBCASE("Sur un terrain avec 1 objet dont on va changer le type et le reste que des cases vides")
            {
                /** Ajout d'un premier objet pour change son type */
                int IndiceLigneCaseAjoutObjet = 0, IndiceColonneCaseAjoutObjet = 0 ;

                t.AjouterObjet(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet, objet::TYPES::MUR) ;
                REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet), objet::TYPES::MUR) ;

                /** Indice de la case à chercher pour changer le type
                    c'est-à-dire que la case où on a ajouté l'objet aura le type de cette case
                */
                int IndiceLigneCaseObjetRemplacant = 0, IndiceColonneCaseObjetRemplacant = 1 ;

                REQUIRE_EQ(t.typeCase(IndiceLigneCaseObjetRemplacant, IndiceColonneCaseObjetRemplacant), objet::TYPES::VIDE) ;

                cout << "Terrain 1 objet et que des cases vides :" << endl ;
                cout << "Avant le changement :" << endl ;
                t.AffichageTerrain() ;

                t.deplacerObjet(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet, IndiceLigneCaseObjetRemplacant, IndiceColonneCaseObjetRemplacant) ;

                cout << "Apres le changement :" << endl ;
                t.AffichageTerrain() ;

                REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet), objet::TYPES::MUR) ;
                REQUIRE_EQ(t.typeCase(IndiceLigneCaseObjetRemplacant, IndiceColonneCaseObjetRemplacant), objet::TYPES::VIDE) ;
            }

            SUBCASE("Sur un terrain avec 2 ou plus d'objets (ou un nombre inférieur à la taille du terrain) dont on va changer le type et le reste des cases vides (on a au moins 1 case vide)")
            {
                int IndiceLigneCaseAjoutObjet1 = 0, IndiceColonneCaseAjoutObjet1 = 0 ;
                int IndiceLigneCaseAjoutObjet2 = 0, IndiceColonneCaseAjoutObjet2 = 1 ;

                t.AjouterObjet(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1, objet::TYPES::MUR) ;
                REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1), objet::TYPES::MUR) ;

                t.AjouterObjet(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2, objet::TYPES::DEBRIS) ;
                REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2), objet::TYPES::DEBRIS) ;

                cout << "Terrain a deux objets ou plus : " << endl ;
                cout << "Terrain avant le changement : " << endl ;
                t.AffichageTerrain() ;

                t.deplacerObjet(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1, IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2) ;

                cout << "Terrain apres le changement : " << endl ;
                t.AffichageTerrain() ;

                REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1), objet::TYPES::MUR) ;
                REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2), objet::TYPES::DEBRIS) ;

            }

            SUBCASE("Sur un terrain ne contenant que des objets")
            {
                t.AjouterObjet(0, 0, objet::TYPES::MUR) ;
                t.AjouterObjet(0, 1, objet::TYPES::JOUEUR_EXPERT) ;
                t.AjouterObjet(1, 0, objet::TYPES::JOUEUR_BASE) ;
                t.AjouterObjet(1, 1, objet::TYPES::ROBOT_ANCIEN) ;

                cout << "Terrain ne comportant que des objets : " << endl ;
                cout << "Terrain avant le 1er changement : " << endl ;
                t.AffichageTerrain() ;

                REQUIRE_EQ(t.typeCase(0, 0), objet::TYPES::MUR) ;
                REQUIRE_EQ(t.typeCase(0, 1), objet::TYPES::JOUEUR_EXPERT) ;
                REQUIRE_EQ(t.typeCase(1, 0), objet::TYPES::JOUEUR_BASE) ;
                REQUIRE_EQ(t.typeCase(1, 1), objet::TYPES::ROBOT_ANCIEN) ;

                /** Change le mur avec le joueur expert : */
                t.deplacerObjet(0, 0, 0, 1) ;

                cout << "Terrain apres le 1er changement : " << endl ;
                t.AffichageTerrain() ;

                REQUIRE_EQ(t.typeCase(0, 0), objet::TYPES::MUR) ;
                REQUIRE_EQ(t.typeCase(0, 1), objet::TYPES::JOUEUR_EXPERT) ;

                /** Change le joueur de base avec le robot ancien : */
                t.deplacerObjet(1, 0, 1, 1) ;

                cout << "Terrain apres le 2e changement : " << endl ;
                t.AffichageTerrain() ;

                REQUIRE_EQ(t.typeCase(1, 0), objet::TYPES::ROBOT_ANCIEN) ;
                REQUIRE_EQ(t.typeCase(1, 1), objet::TYPES::JOUEUR_BASE) ;
            }
        }
    }
}

TEST_CASE("L'affichage d'un terrain est correct")
{
    SUBCASE("Afficher un terrain construit par défaut est correct")
    {
        terrain t{} ;
        t.AffichageTerrain() ;
    }

    SUBCASE("Afficher un terrain construit avec des dimensions données est correct")
    {
        int hauteur = 2, largeur = 2 ;
        terrain t{hauteur, largeur} ;

        SUBCASE("Ne contenant que des cases vides")
        {
            t.AffichageTerrain() ;
        }

        SUBCASE("Contenant 1 objet et le reste des cases vides")
        {
            int IndiceLigneCaseAjoutObjet = 0, IndiceColonneCaseAjoutObjet = 0 ;

            t.AjouterObjet(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet, objet::TYPES::MUR) ;
            REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet), objet::TYPES::MUR) ;

            t.AffichageTerrain() ;
        }

        SUBCASE("Contenant 2 objets ou plus (inférieur à la taille du terrain) et le reste des cases vides (on a au moins 1 case vide)")
        {
            int IndiceLigneCaseAjoutObjet1 = 0, IndiceColonneCaseAjoutObjet1 = 0 ;
            int IndiceLigneCaseAjoutObjet2 = 0, IndiceColonneCaseAjoutObjet2 = 1 ;

            t.AjouterObjet(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1, objet::TYPES::MUR) ;
            REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1), objet::TYPES::MUR) ;

            t.AjouterObjet(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2, objet::TYPES::DEBRIS) ;
            REQUIRE_EQ(t.typeCase(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2), objet::TYPES::DEBRIS) ;

            t.AffichageTerrain() ;
        }

        SUBCASE("Ne contenant que des objets")
        {
            t.AjouterObjet(0, 0, objet::TYPES::MUR) ;
            REQUIRE_EQ(t.typeCase(0, 0), objet::TYPES::MUR) ;

            t.AjouterObjet(0, 1, objet::TYPES::JOUEUR_EXPERT) ;
            REQUIRE_EQ(t.typeCase(0, 1), objet::TYPES::JOUEUR_EXPERT) ;

            t.AjouterObjet(1, 0, objet::TYPES::JOUEUR_BASE) ;
            REQUIRE_EQ(t.typeCase(1, 0), objet::TYPES::JOUEUR_BASE) ;

            t.AjouterObjet(1, 1, objet::TYPES::ROBOT_ANCIEN) ;
            REQUIRE_EQ(t.typeCase(1, 1), objet::TYPES::ROBOT_ANCIEN) ;

            t.AffichageTerrain() ;
        }
    }
}

TEST_CASE("Les opérations diverses sur un terrain sont correctes")
{
    SUBCASE("Vider le terrain est correct")
    {
        SUBCASE("Un terrain vide est bien vidé")
        {
            terrain tVide{} ;
            tVide.viderLeTerrain() ;
            for(int i = 0 ; i < tVide.hauteur() ; i++)
            {
                for(int j = 0 ; j < tVide.largeur() ; j++)
                {
                    REQUIRE_EQ(tVide.Case(i, j), nullptr) ;
                }
            }
        }
    }

    SUBCASE("La création d'un nouveau terrain grâce à un ancien est correct")
    {
        SUBCASE("A Partir d'un terrain construit par défaut est correct")
        {
            terrain tDepart{} ;
            terrain tCopie{tDepart} ;

            SUBCASE("Les dimensions sont les mêmes")
            {
                REQUIRE_EQ(tCopie.hauteur(), tDepart.hauteur()) ;
                REQUIRE_EQ(tCopie.largeur(), tDepart.largeur()) ;
            }

            SUBCASE("Les types des cases sont les mêmes")
            {
                for(int i = 0 ; i < tCopie.hauteur() ; i++)
                {
                    for(int j = 0 ; j < tCopie.largeur() ; j++)
                    {
                        REQUIRE_EQ(tCopie.typeCase(i, j), tDepart.typeCase(i, j)) ;
                    }
                }
            }
        }

        SUBCASE("A partir d'un terrain construit avec des dimensions données")
        {
            int hauteur = 2, largeur = 2 ;
            terrain TDepart{largeur, hauteur} ;

            SUBCASE("Les dimensions sont les mêmes")
            {
                terrain TCopie{TDepart} ;

                REQUIRE_EQ(TCopie.hauteur(), TDepart.hauteur()) ;
                REQUIRE_EQ(TCopie.largeur(), TDepart.largeur()) ;
            }

            SUBCASE("Les types des cases sont les mêmes")
            {
                SUBCASE("Sur des terrains ne contenant que des cases vides")
                {
                    terrain TCopie{TDepart} ;
                    for(int i = 0 ; i < TCopie.hauteur() ; i++)
                    {
                        for(int j = 0 ; j < TCopie.largeur() ; j++)
                        {
                            REQUIRE_EQ(TCopie.typeCase(i, j), TDepart.typeCase(i, j)) ;
                        }
                    }
                }
            }

            SUBCASE("Sur des terrains contenant 1 objet et le reste sont des cases vides")
            {
                int IndiceLigneCaseAjoutObjet = 0, IndiceColonneCaseAjoutObjet = 0 ;

                TDepart.AjouterObjet(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet, objet::TYPES::MUR) ;
                REQUIRE_EQ(TDepart.typeCase(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet), objet::TYPES::MUR) ;

                terrain TCopie{TDepart} ;

                for(int i = 0 ; i < TCopie.hauteur() ; i++)
                {
                    for(int j = 0 ; j < TCopie.largeur() ; j++)
                    {
                        REQUIRE_EQ(TCopie.typeCase(i, j), TDepart.typeCase(i, j)) ;
                    }
                }
            }

            SUBCASE("Sur des terrains contenant 2 objet ou plus (inférieur à la taille) et le reste sont des cases vides (on aura au moins une case vide)")
            {
                int IndiceLigneCaseAjoutObjet1 = 0, IndiceColonneCaseAjoutObjet1 = 0 ;
                int IndiceLigneCaseAjoutObjet2 = 0, IndiceColonneCaseAjoutObjet2 = 1 ;

                TDepart.AjouterObjet(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1, objet::TYPES::MUR) ;
                REQUIRE_EQ(TDepart.typeCase(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1), objet::TYPES::MUR) ;

                TDepart.AjouterObjet(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2, objet::TYPES::DEBRIS) ;
                REQUIRE_EQ(TDepart.typeCase(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2), objet::TYPES::DEBRIS) ;

                terrain TCopie{TDepart} ;

                for(int i = 0 ; i < TCopie.hauteur() ; i++)
                {
                    for(int j = 0 ; j < TCopie.largeur() ; j++)
                    {
                        REQUIRE_EQ(TCopie.typeCase(i, j), TDepart.typeCase(i, j)) ;
                    }
                }
            }

            SUBCASE("Sur des terrains ne contenant que des objets")
            {
                TDepart.AjouterObjet(0, 0, objet::TYPES::MUR) ;
                REQUIRE_EQ(TDepart.typeCase(0, 0), objet::TYPES::MUR) ;

                TDepart.AjouterObjet(0, 1, objet::TYPES::JOUEUR_EXPERT) ;
                REQUIRE_EQ(TDepart.typeCase(0, 1), objet::TYPES::JOUEUR_EXPERT) ;

                TDepart.AjouterObjet(1, 0, objet::TYPES::JOUEUR_BASE) ;
                REQUIRE_EQ(TDepart.typeCase(1, 0), objet::TYPES::JOUEUR_BASE) ;

                TDepart.AjouterObjet(1, 1, objet::TYPES::ROBOT_ANCIEN) ;
                REQUIRE_EQ(TDepart.typeCase(1, 1), objet::TYPES::ROBOT_ANCIEN) ;

                terrain TCopie{TDepart} ;

                for(int i = 0 ; i < TCopie.hauteur() ; i++)
                {
                    for(int j = 0 ; j < TCopie.largeur() ; j++)
                    {
                        REQUIRE_EQ(TCopie.typeCase(i, j), TDepart.typeCase(i, j)) ;
                    }
                }
            }
        }
    }

    SUBCASE("La sauvegarde d'un terrain dans un fichier est correct")
    {
        /** Le fichier de sauvegarde n'est pas obligé d'être créer avant l'appel de la fonction de sauvegarde
            car s'il n'existe pas, la fonction le créer.
        */

        SUBCASE("La sauvegarde d'un terrain construit par défaut est correcte")
        {
            terrain t{} ;
            t.sauvegarder("SauvegardeTerrain_Default") ;
        }

        SUBCASE("La sauvegarde d'un terrain construit avec des dimensions est correcte")
        {
            int hauteur = 2, largeur = 2 ;
            terrain T{hauteur, largeur} ;

            SUBCASE("La sauvegarde d'un terrain contenant des cases vides est correcte")
            {
                T.sauvegarder("SauvegardeTerrainDimension_Vide") ;
            }

            SUBCASE("La sauvegarde d'un terrain contenant 1 ou plusieurs objets est correcte")
            {
                SUBCASE("1 Objet et le reste que des cases vides")
                {
                    int IndiceLigneCaseAjoutObjet = 0, IndiceColonneCaseAjoutObjet = 0 ;

                    T.AjouterObjet(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet, objet::TYPES::MUR) ;
                    REQUIRE_EQ(T.typeCase(IndiceLigneCaseAjoutObjet, IndiceColonneCaseAjoutObjet), objet::TYPES::MUR) ;

                    T.sauvegarder("SauvegardeTerrainDimension_1Objet") ;
                }

                SUBCASE("2 objet ou plus (Nombre inférieur à la taille du terrain) et le reste des cases vides (on aura au moins 1 case vide)")
                {
                    int IndiceLigneCaseAjoutObjet1 = 0, IndiceColonneCaseAjoutObjet1 = 0 ;
                    int IndiceLigneCaseAjoutObjet2 = 0, IndiceColonneCaseAjoutObjet2 = 1 ;

                    T.AjouterObjet(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1, objet::TYPES::MUR) ;
                    REQUIRE_EQ(T.typeCase(IndiceLigneCaseAjoutObjet1, IndiceColonneCaseAjoutObjet1), objet::TYPES::MUR) ;

                    T.AjouterObjet(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2, objet::TYPES::DEBRIS) ;
                    REQUIRE_EQ(T.typeCase(IndiceLigneCaseAjoutObjet2, IndiceColonneCaseAjoutObjet2), objet::TYPES::DEBRIS) ;

                    T.sauvegarder("SauvegardeTerrainDimension_2ObjetOuPlus") ;
                }

                SUBCASE("Un terrain contenant que des objets")
                {
                    T.AjouterObjet(0, 0, objet::TYPES::MUR) ;
                    REQUIRE_EQ(T.typeCase(0, 0), objet::TYPES::MUR) ;

                    T.AjouterObjet(0, 1, objet::TYPES::JOUEUR_EXPERT) ;
                    REQUIRE_EQ(T.typeCase(0, 1), objet::TYPES::JOUEUR_EXPERT) ;

                    T.AjouterObjet(1, 0, objet::TYPES::JOUEUR_BASE) ;
                    REQUIRE_EQ(T.typeCase(1, 0), objet::TYPES::JOUEUR_BASE) ;

                    T.AjouterObjet(1, 1, objet::TYPES::ROBOT_ANCIEN) ;
                    REQUIRE_EQ(T.typeCase(1, 1), objet::TYPES::ROBOT_ANCIEN) ;

                    T.sauvegarder("SauvegardeTerrainDimension_CompletObjet") ;
                }
            }
        }
    }

    /** Pour sauter une ligne entre les affichages */
    cout << endl ;

    SUBCASE("Le chargement d'un terrain est correct")
    {
        /** ATTENTION : AVANT D'APPELER LA FONCTION DE CHARGEMENT DU TERRAIN,
            LE FICHIER CONTENANT CE TERRAIN DOIT ABSOLUMENT EXISTER
        */
        terrain t{} ;

        SUBCASE("Un robot customisable est bien chargé dans le terrain")
        {
            t.chargerTerrain("FichierTerrain_RobotPerso") ;
            REQUIRE_EQ(dynamic_cast <robotPerso*>(t.Case(0,0))->get_vitesse(), 2) ;
		    for(int i = 0 ; i < 8 ; i++)
            {
		    	REQUIRE_EQ(dynamic_cast <robotPerso*>(t.Case(0,0))->get_direction(i), i % 2) ;
            }
        }

        SUBCASE("Le chargement d'un terrain dont le fichier n'existe pas est correct (doit affiché que le fichier n'existe pas)")
        {
            t.chargerTerrain("FichierTerrain_Inexistant") ;
        }

        SUBCASE("Le chargement d'un terrain construit par défaut est correct")
        {
            t.chargerTerrain("FichierTerrain_Defaut") ;
        }

        SUBCASE("Le chargement d'un terrin construit avec des dimensions est correct")
        {
            SUBCASE("Un terrain ne contenant que des cases vides")
            {
                t.chargerTerrain("FichierTerrainDimension_Vide") ;
            }

            SUBCASE("Un terrain contenant 1 objet et le reste en cases vides")
            {
                t.chargerTerrain("FichierTerrainDimension_1Objet") ;
            }

            SUBCASE("Un terrain contenant 2 objets ou plus (Nombre inférieur à la taille du terrain) et le reste en cases vides (on aura au moins une case vide)")
            {
                t.chargerTerrain("FichierTerrainDimension_2ObjetsOuPlus") ;
            }

            SUBCASE("Un terrain ne contenant que des objets")
            {
                t.chargerTerrain("FichierTerrainDimension_CompletObjet") ;
            }

            SUBCASE("Un terrain contenant un caractère erroné")
            {
                t.chargerTerrain("FichierTerrainDimension_CaractereInvalide") ;
            }
        }
    }
}
