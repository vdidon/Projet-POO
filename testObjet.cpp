#include "doctest.h"
#include "objet.h"

TEST_CASE("Test d'un objet")
{
    SUBCASE("Une objet doit pouvoir donner son type")
    {
        objet obj ;
        REQUIRE_EQ(obj.typeObjet(), objet::TYPES::OBJET) ;
    }
}
