#include "doctest.h"
#include "robotPerso.h"

#include <iostream>

TEST_CASE("Tests pour RobotPerso")
{
	SUBCASE("Constructeur")
	{
		std::vector <bool> tmp = {1, 1, 1, 1, 1, 1, 1, 1} ;
		robotPerso r = robotPerso{2, tmp} ;
		REQUIRE_EQ(r.get_vitesse(), 2) ;
		for(int i = 0 ; i < 8 ; ++i)
        {
            REQUIRE_EQ(r.get_direction(i), tmp[i]) ;
		}
	}

	SUBCASE("typeObjet")
	{
		std::vector <bool> tmp = {1, 1, 1, 1, 1, 1, 1, 1} ;
		robotPerso r = robotPerso{2, tmp} ;
		REQUIRE_EQ(r.typeObjet(), objet::TYPES::ROBOT_PERSO) ;
	}

	SUBCASE("PeutAllerEn")
	{
		SUBCASE("Autorisé dans toute les directions")
		{
			std::vector <bool> tmp = {1, 1, 1, 1, 1, 1, 1, 1} ;
			robotPerso r = robotPerso{2, tmp} ;
			for(int i = -1 ; i <= 1 ; ++i)
            {
				for(int j = -1 ; j <= 1 ; ++j)
				{
					REQUIRE(r.PeutAllerEn(i, j)) ;
				}
			}
		}

		SUBCASE("Autorisé dans aucune directions")
		{
			std::vector <bool> tmp = {0, 0, 0, 0, 0, 0, 0, 0} ;
			robotPerso r = robotPerso{2, tmp} ;
			/**
			for(int i = -1 ; i <= 1 ; ++i)
            {
				for(int j = -1 ; j <= 1 ; ++j)
				{
				    std::cout << i << " " << j << std::endl ;
					//REQUIRE_FALSE(r.PeutAllerEn(i, j)) ;
                }
            } */
			// PROBLEME, il teste si il peut aller en 0 0 et c'est vrai donc il arrete les tests car ca renvoie true, ce cas n'est pas a tester donc
			// Il faut tout tester sauf 0 0 donc :

			REQUIRE_FALSE(r.PeutAllerEn(-1, -1)) ;
            REQUIRE_FALSE(r.PeutAllerEn(-1, 0)) ;
            REQUIRE_FALSE(r.PeutAllerEn(-1 , 1)) ;
            REQUIRE_FALSE(r.PeutAllerEn(0, -1)) ;
            REQUIRE(r.PeutAllerEn(0, 0)) ;
            REQUIRE_FALSE(r.PeutAllerEn(0, 1)) ;
            REQUIRE_FALSE(r.PeutAllerEn(1, -1)) ;
            REQUIRE_FALSE(r.PeutAllerEn(1, 0)) ;
            REQUIRE_FALSE(r.PeutAllerEn(1, 1)) ;
		}
	}
}
