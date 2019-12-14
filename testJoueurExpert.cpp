#include "doctest.h"
#include "joueurExpert.h"


TEST_CASE("Test des opérations du joueur expert")
{
     SUBCASE("Le joueur est bien mort")
    {
        localisation pos{};
        joueurExpert j1Expert {pos};

        bool vivant = false;
        j1Expert.tuer();
        REQUIRE_EQ(j1Expert.estVivant(), vivant) ;
    }
}



