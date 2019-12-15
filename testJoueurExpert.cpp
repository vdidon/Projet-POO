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
	
	SUBCASE("Le déplacement est correct")
    {
        localisation pos;
        joueurExpert j1Expert{pos};
        char choix;

        int positionX1=j1Expert.position().x();
        int positionY1=j1Expert.position().y();


        int resultatX1=0;
        int resultatY1=0;

        int x1=0;
        int y1=0;

        bool ok=false;

        while(ok==false)
        {
           joueur::interactionJoueurExpert(x1,y1);
        //if(joueur::evalCase(const Terrain& gr,int lig,int col)
        //{

            resultatX1=positionX1+x1;
            resultatY1=positionY1+y1;

            double diffCoordx=abs(x1-positionX1);
            double diffCoordy=abs(y1-positionY1);

            if(diffCoordx==1&& positionY1==y1 || positionX1==x1&& diffCoordy==1)
            {
                j1Expert.deplaceEn(resultatX1,resultatY1);
                ok=true;
            }
            else
            {
                joueur::echecMauvaisPas();
            }

        //}

        }

        REQUIRE_EQ(j1Expert.position().x(), resultatX1) ;
        REQUIRE_EQ(j1Expert.position().y(), resultatY1) ;
     }
}



