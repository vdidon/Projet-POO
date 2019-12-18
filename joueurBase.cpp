#include "joueurBase.h"

joueurBase::joueurBase(): d_vivant{true}, d_coordonnee{}
{}

bool joueurBase::deplaceEn(int x, int y)
{
    d_coordonnee.moveTo(x, y) ;
}

void joueurBase::tuer()
{
    d_vivant = false ;
}

bool joueurBase::estVivant() const
{
    return d_vivant ;
}

bool joueurBase::PeutAllerEn(int dx, int dy) const
{
    // A faire
}

/*char joueurBase::typeObjet() const
{
    return TYPES::JOUEUR_BASE ;
}*/
