#include "doctest.h"
#include "debris.h"

TEST_CASE("Test d'un d�bris")
{
    SUBCASE("Une d�bris doit afficher qu'il ne peut pas se d�placer")
    {
        int x = 1, y = 0 ;
        debris deb{} ;
        REQUIRE_EQ(deb.PeutAllerEn(x, y), false) ;
    }

    SUBCASE("Une d�bris doit pouvoir donner son type")
    {
        debris deb{} ;
        REQUIRE_EQ(deb.typeObjet(), objet::TYPES::DEBRIS) ;
    }
}
