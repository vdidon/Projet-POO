#include "mur.h"

bool PeutAllerEn(int x, int y)
{
    return false; //Un mur ne bouge pas, donc pas besoin de v�rifier. Mesure de s�curit�
}

char objet::typeObjet() const {
	return TYPES::OBJET; //Pas de TYPES::MUR donc c'est juste un objet (comme debris)
}
