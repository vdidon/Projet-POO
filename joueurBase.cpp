#include "joueurBase.h"
#include <algorithm>

/*
//Methode PeutAllerEn implementer pour joueur de base
*/
bool joueurBase::PeutAllerEn(int dx, int dy)const
{

    if(abs(dx)<=1 && abs(dy)<=1)
    {
        return true;
    }
    else
    {
        return false;
    }

}



