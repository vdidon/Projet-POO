#include "mur.h"

/**
    Un mur ne bouge pas, donc pas besoin de v�rifier. Mesure de s�curit�
*/
bool PeutAllerEn(int x, int y)
{
    return false ;
}

char mur::typeObjet() const
{
	return TYPES::MUR ;
}
