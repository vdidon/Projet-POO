#include "joueurExpert.h"
#include <algorithm>

joueurExpert::joueurExpert(const char &Type_Joueur_Expert): d_type{Type_Joueur_Expert}
{}

bool joueurExpert::PeutAllerEn(int dx, int dy) const
{
    int dxValeurAbsolue = abs(dx) ;
    int dyValeurAbsolue = abs(dy) ;
    return (((dxValeurAbsolue == 1) && (dyValeurAbsolue == 0)) || ((dxValeurAbsolue == 0) && (dyValeurAbsolue == 1))) ;
}

char joueurExpert::typeObjet() const
{
    return d_type ;
}
