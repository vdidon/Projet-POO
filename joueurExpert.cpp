#include "joueurExpert.h"
#include <algorithm>


/*
//Methode PeutAllerEn implementer pour le joueur expert 
*/
bool joueurExpert::PeutAllerEn(int dx, int dy)const
{
    int dxValeurAbsolue=abs(dx);
    int dyValeurAbsolue=abs(dy);
    if((dxValeurAbsolue==1&& dyValeurAbsolue==0) || (dxValeurAbsolue==0&& dyValeurAbsolue==1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

