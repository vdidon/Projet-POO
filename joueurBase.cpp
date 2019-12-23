#include "joueurBase.h"
#include <algorithm>

joueurBase::joueurBase(const char &Type_Joueur_Base) : d_type{Type_Joueur_Base}
{}

bool joueurBase::PeutAllerEn(int dx, int dy) const
{
    return ((abs(dx) <= 1) && (abs(dy) <= 1)) ;
}

char joueurBase::typeObjet() const
{
    return d_type ;
}
