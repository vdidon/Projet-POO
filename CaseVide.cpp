#include "CaseVide.h"

CaseVide::CaseVide(const char &Type_Case_Vide)
{
    d_type = Type_Case_Vide ;
}

bool CaseVide::PeutAllerEn(int x, int y) const
{
    return false ;
}

char CaseVide::typeObjet() const
{
    return d_type ;
}
