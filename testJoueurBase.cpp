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
	
	SUBCASE("Le déplacement est correct")
    {
        localisation pos;
        joueurBase j1Base{pos};
        char choix;

        int positionX1=j1Base.position().x();
        int positionY1=j1Base.position().y();

        int resultatX1=0;
        int resultatY1=0;

        int x1=0;
        int y1=0;
        bool ok=false;

        while(ok==false)
        {
            joueur::interactionJoueurBase(x1,y1);

        //if(joueur::evalCase(const Terrain& gr,int lig,int col) //Teste si valeur pas en dehors du terrain
        //{
            resultatX1=positionX1+x1;
            resultatY1=positionY1+y1;

            int diffCoordx=abs(x1-positionX1);
            int diffCoordy=abs(y1-positionY1);

            if(diffCoordx<=1&& diffCoordy<=1) //test bien que le pas vaut 1
            {
                j1Base.deplaceEn(resultatX1,resultatY1);
                ok=true;
            }
            else
            {
                joueur::echecMauvaisPas();
            }

        //}

        }

        REQUIRE_EQ(j1Base.position().x(), resultatX1) ;
        REQUIRE_EQ(j1Base.position().y(), resultatY1) ;
     }
}


