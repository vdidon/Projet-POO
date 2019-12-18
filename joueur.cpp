#include "joueur.h"

joueur::~joueur()
{}

/** A voir si c'est une méthode de terrain ou non
bool evalCase(const Terrain &gr, int lig, int col)
{
    if(1 <= lig and lig <= gr.x() && 1 <= col and col <= gr.y())
    {
        return true ;
    }
    else
    {
        return false ;
    }

}
*/

char joueur::testChoixUtilisateur(char choix, const string &phrase)
{
    do
    {
        cout << phrase << endl ;
        cin >> choix ;
    } while(choix != 'y' && choix != 'n') ;
    return choix ;
}

void joueur::interactionJoueurExpert(int &x1, int &y1)
{
    char choix ;
    if(testChoixUtilisateur(choix, "Deplacer le joueur horizontalement ? (y or n)") == 'y')
    {
        cout << "Avancer ou reculer le joueur d'une case (x = 1 ou x = -1)" << endl ;
        cin >> x1 ;
    }
    else
    {
        if(testChoixUtilisateur(choix, "Deplacer le joueur verticalement ? (y or n)") == 'y')
        {
            cout << "Monter ou descendre le joueur d'une case (y = 1 ou y = -1)" << endl ;
            cin >> y1 ;
        }
    }
}

void joueur::interactionJoueurBase(int &x1, int &y1)
{
    char choix ;
    if(testChoixUtilisateur(choix, "Deplacer le joueur en diagonale? (y or n)") =='y')
    {
        cout << "Decaler le joueur d'une case en diagonale" << endl ;
        cout << "x : (x = 1 ou x = -1)" << endl ;
        cin >> x1 ;
        cout << "y : (y = 1 ou y = -1)" << endl ;
        cin >> y1 ;
    }
    else
    {
        joueur::interactionJoueurExpert(x1, y1) ;
    }
}

void joueur::echecMauvaisPas()
{
    cout << "Veuillez reessayer avec un pas correct" << endl ;
}
