#include "debris.h"

debris::debris(const char &Type_Debris)
{
    d_type = Type_Debris ;
}

/**
    Un d�bris ne bouge pas, donc pas besoin de v�rifier. Mesure de s�curit�
*/
bool debris::PeutAllerEn(int x, int y) const
{
    return false ;
}

char debris::typeObjet() const
{
    return d_type ;
}
