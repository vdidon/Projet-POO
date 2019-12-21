#include "robotNouveau.h"

#include <cmath>

robotNouveau::robotNouveau(const char &Type_robot_Nouveau)
{
    d_type = Type_robot_Nouveau ;
}

robotNouveau::~robotNouveau()
{}

char robotNouveau::typeObjet() const
{
    return d_type ;
}

bool robotNouveau::PeutAllerEn(int dx, int dy) const
{
     return abs(dx) <= 1 && abs(dy) <= 1 ;
}
