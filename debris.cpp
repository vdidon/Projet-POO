#include "debris.h"

/**
    Un d�bris ne bouge pas, donc pas besoin de v�rifier. Mesure de s�curit�
*/
// Pose une erreur si on le d�commente
bool debris::PeutAllerEn(int x, int y)
{
    return false ;
}

char debris::typeObjet() const
{
	return TYPES::DEBRIS ;
}
