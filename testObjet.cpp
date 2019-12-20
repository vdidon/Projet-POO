#include "doctest.h"
#include "objet.h"


TEST_CASE("Test d'un objet")
{
    SUBCASE("Une objet doit pouvoir donner son type")
    {
        objet ob;
        REQUIRE_EQ(ob.typeObjet(), objet::TYPES::OBJET);
    }
}