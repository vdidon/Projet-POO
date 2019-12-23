#include "doctest.h"
#include "joueurBase.h"

void leJoueurBasePeutEtreDeplacer(const joueurBase &jBase, int dx, int dy)
{
    bool JoueurBaseAutoriserDeplacement = jBase.PeutAllerEn(dx, dy) ;
    REQUIRE_EQ(JoueurBaseAutoriserDeplacement, true) ;
}

TEST_CASE("Le deplacement du joueur de base est correct")
{
    char typeJoueur = objet::TYPES::JOUEUR_BASE ;
    joueurBase jBase1{typeJoueur} ;

    SUBCASE("Le deplacement en diagonale est correct")
    {
        int dx = 1 ;
        int dy = 1 ;
        leJoueurBasePeutEtreDeplacer(jBase1, dx, dy) ;

        dy = -1 ;
        leJoueurBasePeutEtreDeplacer(jBase1, dx, dy) ;

        dx = -1 ;
        leJoueurBasePeutEtreDeplacer(jBase1, dx, dy) ;

        dx = -1 ;
        dy = 1 ;
        leJoueurBasePeutEtreDeplacer(jBase1, dx, dy) ;
    }

    SUBCASE("Le deplacement horizontale est correct")
    {
        int dx = -1 ;
        int dy = 0 ;
        leJoueurBasePeutEtreDeplacer(jBase1, dx, dy) ;

        dx = 1 ;
        leJoueurBasePeutEtreDeplacer(jBase1, dx, dy) ;
    }

    SUBCASE("Le deplacement verticale est correct")
    {
        int dx = 0 ;
        int dy = -1 ;
        leJoueurBasePeutEtreDeplacer(jBase1, dx, dy) ;

        dy = 1 ;
        leJoueurBasePeutEtreDeplacer(jBase1, dx, dy) ;
    }
}
