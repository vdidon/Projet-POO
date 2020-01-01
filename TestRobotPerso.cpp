#include "doctest.h"
#include "robotPerso.h"

TEST_CASE ("Tests pour RobotPerso") {
	SUBCASE("Constructeur") {
		bool tmp[] = {1, 1, 1, 1, 1, 1, 1, 1};
		robotPerso r = robotPerso{2, tmp};
		REQUIRE_EQ(r.get_vitesse(), 2);
		for (int i = 0; i < 8; ++i) {
			REQUIRE_EQ(r.get_direction()[i], tmp[i]);
		}
	}

	SUBCASE("typeObjet") {
		bool tmp[] = {1, 1, 1, 1, 1, 1, 1, 1};
		robotPerso r = robotPerso{2, tmp};
		REQUIRE_EQ(r.typeObjet(), objet::TYPES::ROBOT_PERSO);
	}

	SUBCASE("PeutAllerEn") {
		SUBCASE("Autorisé dans toute les directions") {
			bool tmp[] = {1, 1, 1, 1, 1, 1, 1, 1};
			robotPerso r = robotPerso{2, tmp};
			for (int i = -1; i <= 1; ++i) {
				for (int j = -1; j <= 1; ++j) {
					REQUIRE(r.PeutAllerEn(i, j));
				}
			}
		}

		SUBCASE("Autorisé dans aucune directions") {
			bool tmp[] = {0, 0, 0, 0, 0, 0, 0, 0};
			robotPerso r = robotPerso{2, tmp};
			for (int i = -1; i <= 1; ++i) {
				for (int j = -1; j <= 1; ++j) {
					REQUIRE_FALSE(r.PeutAllerEn(i, j));
				}
			}
		}
	}
}
