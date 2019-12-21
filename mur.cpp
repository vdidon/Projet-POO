#include "mur.h"

mur::mur(const char &Type_Mur)
{
    d_type = Type_Mur ;
}

/**
    Un mur ne bouge pas, donc pas besoin de vérifier. Mesure de sécurité
*/
bool mur::PeutAllerEn(int x, int y) const
{
    return false ;
}

char mur::typeObjet() const
{
    return d_type ;
}
