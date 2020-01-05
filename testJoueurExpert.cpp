#include "doctest.h"
#include "joueurExpert.h"

void leJoueurExpertPeutEtreDeplacer(const joueurExpert &jExpert, int dx, int dy)
{
    bool JoueurExpertAutoriserDeplacement = jExpert.PeutAllerEn(dx, dy) ;
    REQUIRE_EQ(JoueurExpertAutoriserDeplacement, true) ;
}

TEST_CASE("Le deplacement du joueur expert est correct")
{
    joueurExpert jExpert1{} ;
    SUBCASE("Le deplacement horizontale est correct")
    {
        int dx = -1 ;
        int dy = 0 ;
        leJoueurExpertPeutEtreDeplacer(jExpert1, dx, dy) ;

        dx = 1 ;
        leJoueurExpertPeutEtreDeplacer(jExpert1, dx, dy) ;
    }

    SUBCASE("Le deplacement verticale est correct")
    {
        int dx = 0 ;
        int dy = -1 ;
        leJoueurExpertPeutEtreDeplacer(jExpert1, dx, dy) ;

        dy = 1 ;
        leJoueurExpertPeutEtreDeplacer(jExpert1, dx, dy) ;
    }
}
