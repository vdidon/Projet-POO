#include "joueurExpert.h"

#include <algorithm>

joueurExpert::joueurExpert(const char &Type_Joueur_Expert): d_vivant{true}, d_coordonnee{}
{
    d_type = Type_Joueur_Expert ;
}

bool joueurExpert::deplaceEn(int x, int y)
{
	d_coordonnee.moveTo(x, y) ;
	return ((d_coordonnee.x() == x) && (d_coordonnee.y() == y)) ; // Retourne si les coordonnées ont bien changée
}

void joueurExpert::tuer()
{
    d_vivant = false ;
}

bool joueurExpert::estVivant() const
{
    return d_vivant ;
}

bool joueurExpert::PeutAllerEn(int dx, int dy) const
{
    int dxValeurAbsolue = abs(dx) ;
    int dyValeurAbsolue = abs(dy) ;
    return (((dxValeurAbsolue == 1) && (dyValeurAbsolue == 0)) || ((dxValeurAbsolue == 0) && (dyValeurAbsolue == 1))) ;
    // simplicfication
}

char joueurExpert::typeObjet() const
{
    return d_type ;
}
