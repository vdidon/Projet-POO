#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN //permet d'eviter des erreurs au niveau de SUBCASE mais a inclure qu'une fois
#include "doctest.h"
#include "joueurBase.h"

TEST_CASE("Test des opérations du joueur de base")
{
    SUBCASE("Le joueur est bien mort")
    {
        localisation pos;
        joueurBase j1Base {pos};
        bool vivant = false;
        j1Base.tuer();
        REQUIRE_EQ(j1Base.estVivant(), vivant) ;
    }
}


