#include "mur.h"

mur::mur()
{

}

/**
    Un mur ne bouge pas, donc pas besoin de v�rifier. Mesure de s�curit�
*/
bool mur::PeutAllerEn(int x, int y) const
{
    return false ;
}

char mur::typeObjet() const
{
    return objet::TYPES::MUR;
}
