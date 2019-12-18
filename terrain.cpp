#include "terrain.h"

terrain::terrain(int largeur, int hauteur) : d_tableau{hauteur, std::vector <objet*>(largeur, nullptr)}
{}

terrain::terrain(terrain &t) : terrain(t.hauteur(), t.largeur())
{
    for(int i = 0 ; i < hauteur() ; i++)
    {
        for(int j = 0 ; j < largeur() ; j++)
        {
            d_tableau[i][j] = t[i][j] ;
        }
    }
}

// Reste encore à tester si fonctionnel (DOCTEST)
terrain terrain::chargerTerrain(const std::string &NomFichier)
{
    std::ifstream f(NomFichier + ".txt") ;
    int Hauteur = hauteur(), Largeur = largeur() ;
    char retourALaLigne = '\n', espace = ' ' ;
    f >> Hauteur >> espace >> Largeur >> retourALaLigne ;
    // Remet le vecteur à l'état de départ, c'est-à-dire taille 0 et aucun élément
    terrain t(Largeur, Hauteur) ;
    while(!f.eof())
    {
        for(int i = 0 ; i < hauteur() ; ++i)
        {
            for(int j = 0 ; j < largeur() ; ++j)
            {
                int Position_X = i, Position_Y = j ;
                char Objet ;
                f >> Position_X >> espace >> Position_Y >> espace >> Objet >> retourALaLigne ;
                switch(Objet)
                {
                    case objet::TYPES::DEBRIS :
                        // Pose une erreur si on le décommente
                        t.d_tableau[Position_X][Position_Y] = debris() ;
                        break ;
                    case objet::TYPES::JOUEUR_BASE :
                        // Pose une erreur si on le décommente
                        t.d_tableau[Position_X][Position_Y] = new joueurBase(localisation(Position_X, Position_Y)) ;
                        break ;
                    case objet::TYPES::JOUEUR_EXPERT :
                        // Pose une erreur si on le décommente
                        t.d_tableau[Position_X][Position_Y] = new joueurExpert(localisation(Position_X, Position_Y)) ;
                        break ;
                    case objet::TYPES::MUR :
                        // Pose une erreur si on le décommente
                        t.d_tableau[Position_X][Position_Y] = new mur() ;
                            break ;
                    case objet::TYPES::ROBOT_ANCIEN :
                        t.d_tableau[Position_X][Position_Y] = new robotAncien() ;
                        break ;
                    case objet::TYPES::ROBOT_NOUVEAU :
                        t.d_tableau[Position_X][Position_Y] = new robotNouveau() ;
                        break ;
                    case objet::TYPES::ROBOT_PERSO :
                        // Pose une erreur si on le décommente
                        t.d_tableau[Position_X][Position_Y] = new robotPerso(/* Vitesse, tableau de direction */) ;
                        break ;
                }
            }
        }
    }
    return t ;
}

// Reste encore à tester si fonctionnel (DOCTEST)
void terrain::sauvegarder(const std::string &NomFichier) const
{
    std::ofstream f(NomFichier + ".txt") ;
    if(!f)
    {
        return ;
    }
    else
    {
        int H = hauteur(), L = largeur() ;
        f << H << " " << L << '\n' ;
        for(int i = 0 ; i < H ; ++i)
        {
            for(int j = 0 ; j < L ; ++j)
            {
                int Position_X = i, Position_Y = j ;
                auto Objet = d_tableau[i][j] ;
                f << Position_X << " " << Position_Y << " " << Objet << '\n' ;
            }
        }
    }
}

int terrain::hauteur() const
{
    return d_tableau.size() ;
}

int terrain::largeur() const
{
    return d_tableau[0].size() ;
}

void terrain::ChangerHauteur(int x)
{
    d_tableau.resize(x) ;
    for(int i = 0 ; i < d_tableau.size() ; ++i)
    {
        d_tableau[i].resize(largeur()) ;
    }
}

void terrain::ChangerLargeur(int y)
{
    for(int i = 0 ; i < hauteur() ; ++i)
    {
        d_tableau[i].resize(y) ;
    }
}

std::vector <objet*>& terrain::operator[](int i)
{
    return d_tableau[i] ;
}

void terrain::AffichageTerrain(const terrain &t) const
{
    for(int i = 0 ; i < t.hauteur() ; i++)
    {
        for(int j = 0 ; j < t.largeur() ; j++)
        {
            cout << d_tableau[i][j] ;
        }
        cout << endl ;
    }
}
