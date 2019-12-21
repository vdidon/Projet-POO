#include "robotAncien.h"

#include <cmath>

robotAncien::robotAncien(const char &Type_Robot_Ancien)
{
    d_type = Type_Robot_Ancien ;
}

robotAncien::~robotAncien()
{}

char robotAncien::typeObjet() const
{
	return d_type ;
}

bool robotAncien::PeutAllerEn(int dx, int dy) const
{
	return !(dx && dy) && abs(dx) <= 1 && abs(dy) <= 1 ;
}
