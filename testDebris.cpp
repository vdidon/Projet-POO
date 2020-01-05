#include "doctest.h"
#include "debris.h"

TEST_CASE("Test d'un débris")
{
    SUBCASE("Une débris doit afficher qu'il ne peut pas se déplacer")
    {
        int x = 1, y = 0 ;
        debris deb{} ;
        REQUIRE_EQ(deb.PeutAllerEn(x, y), false) ;
    }

    SUBCASE("Une débris doit pouvoir donner son type")
    {
        debris deb{} ;
        REQUIRE_EQ(deb.typeObjet(), objet::TYPES::DEBRIS) ;
    }
}
