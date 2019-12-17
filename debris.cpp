#include "debris.h"

/**
    Un débris ne bouge pas, donc pas besoin de vérifier. Mesure de sécurité
*/
// Pose une erreur si on le décommente
bool debris::PeutAllerEn(int x, int y)
{
    return false ;
}

char debris::typeObjet() const
{
	return TYPES::DEBRIS ;
}
