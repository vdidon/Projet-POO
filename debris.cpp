#include "debris.h"

debris::debris(const char &Type_Debris)
{
    d_type = Type_Debris ;
}

/**
    Un débris ne bouge pas, donc pas besoin de vérifier. Mesure de sécurité
*/
bool debris::PeutAllerEn(int x, int y) const
{
    return false ;
}

char debris::typeObjet() const
{
    return d_type ;
}
