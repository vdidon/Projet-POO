#include "joueurBase.h"

#include <algorithm>

joueurBase::joueurBase(const char &Type_Joueur_Base) : d_vivant{true}, d_coordonnee{}
{
    d_type = Type_Joueur_Base ;
}

bool joueurBase::deplaceEn(int x, int y)
{
    d_coordonnee.moveTo(x, y) ;
    return ((d_coordonnee.x() == x) && (d_coordonnee.y() == y)) ;
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
    return ((abs(dx) <= 1) && (abs(dy) <= 1)) ;
}

char joueurBase::typeObjet() const
{
    return d_type ;
}
