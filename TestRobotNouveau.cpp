#include "doctest.h"
#include "robotNouveau.h"

TEST_CASE ("Tests pour robotNouveau") {
	robotNouveau r = robotNouveau{};

	SUBCASE("typeObjet") {
				REQUIRE_EQ(r.typeObjet(), objet::TYPES::ROBOT_NOUVEAU);
	}

	SUBCASE("PeutAllerEn") {
		SUBCASE("Directions autorisés") {
					REQUIRE(r.PeutAllerEn(-1, 0));
					REQUIRE(r.PeutAllerEn(0, -1));
					REQUIRE(r.PeutAllerEn(1, 0));
					REQUIRE(r.PeutAllerEn(0, 1));
					REQUIRE(r.PeutAllerEn(-1, -1));
					REQUIRE(r.PeutAllerEn(1, -1));
					REQUIRE(r.PeutAllerEn(1, 1));
					REQUIRE(r.PeutAllerEn(-1, 1));
		}
		SUBCASE("Déplacement de plus d'une case") {
					REQUIRE_FALSE(r.PeutAllerEn(-2, 0));
					REQUIRE_FALSE(r.PeutAllerEn(0, -2));
					REQUIRE_FALSE(r.PeutAllerEn(2, 0));
					REQUIRE_FALSE(r.PeutAllerEn(0, 2));
					REQUIRE_FALSE(r.PeutAllerEn(2, 1));
					REQUIRE_FALSE(r.PeutAllerEn(1, 2));
		}
	}
}


