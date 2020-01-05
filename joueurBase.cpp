#include "joueurBase.h"

#include <algorithm>

joueurBase::joueurBase()
{}

bool joueurBase::PeutAllerEn(int dx, int dy) const
{
    return ((abs(dx) <= 1) && (abs(dy) <= 1)) ;
}

char joueurBase::typeObjet() const
{
    return objet::TYPES::JOUEUR_BASE;
}
