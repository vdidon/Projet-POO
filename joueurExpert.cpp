#include "joueurExpert.h"

joueurExpert::joueurExpert(): d_vivant{true}, d_coordonnee{}
{}

bool joueurExpert::deplaceEn(int x, int y)
{
	d_coordonnee.moveTo(x, y) ;
	return true ; // Sinon warning car doit retoruner quelque chose
}

void joueurExpert::tuer()
{
    d_vivant = false ;
}

bool joueurExpert::estVivant() const
{
    return d_vivant ;
}

bool joueurExpert::PeutAllerEn(int dx, int dy) const
{
    // A faire
}

/*char joueurExpert::typeObjet() const
{
    return TYPES::JOUEUR_EXPERT ;
}*/
