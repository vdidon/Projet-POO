#include "debris.h"

bool debris::PeutAllerEn(int x, int y)
{
    return false; //Un mur ne bouge pas (sauf peut-�tre dans une dimension alternative), donc pas besoin de v�rifier. Mesure de s�curit�
}

char objet::typeObjet() const {
	return TYPES::OBJET; //Pas de TYPES::DEBRIS donc c'est juste un objet (comme mur)
}