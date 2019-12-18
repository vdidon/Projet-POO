#include "debris.h"

debris::debris()
{}

/**
    Un débris ne bouge pas, donc pas besoin de vérifier. Mesure de sécurité
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
