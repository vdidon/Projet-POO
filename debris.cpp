#include "debris.h"

debris::debris()
{}

/**
    Un d�bris ne bouge pas, donc pas besoin de v�rifier. Mesure de s�curit�
*/
bool debris::PeutAllerEn(int x, int y) const
{
    return false ;
}

// voir si utile
/*char debris::typeObjet() const
{
	return TYPES::DEBRIS ;
}*/
