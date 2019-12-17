#include "joueurExpert.h"

joueurExpert::joueurExpert(const localisation &pos): d_vivant{true}, d_coordonnee{pos}
{}

bool joueurExpert::deplaceEn(int x, int y)
{
	d_coordonnee.moveTo(x, y) ;
}

void joueurExpert::tuer()
{
    d_vivant = false ;
}

bool joueurExpert::estVivant() const
{
    return d_vivant ;
}

localisation joueurExpert::position() const
{
    return d_coordonnee ;
}
