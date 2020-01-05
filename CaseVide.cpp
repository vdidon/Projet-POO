#include "CaseVide.h"

CaseVide::CaseVide()
{
}

bool CaseVide::PeutAllerEn(int x, int y) const
{
    return false ;
}

char CaseVide::typeObjet() const
{
    return objet::TYPES::VIDE ;
}
