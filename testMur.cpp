#include "doctest.h"
#include "mur.h"

TEST_CASE("Test d'un mur")
{
    SUBCASE("Une mur doit afficher qu'il ne peut pas se déplacer")
    {
        int x = 1, y = 0 ;
        mur m ;
        REQUIRE_EQ(m.PeutAllerEn(x, y), false) ;
    }

    SUBCASE("Une mur doit pouvoir donner son type")
    {
        mur m ;
        REQUIRE_EQ(m.typeObjet(), objet::TYPES::MUR) ;
    }
}
