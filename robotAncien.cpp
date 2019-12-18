#include "robotAncien.h"

robotAncien::~robotAncien()
{}

/*char robotAncien::typeObjet() const
{
	return objet::TYPES::ROBOT_ANCIEN ;
}*/

bool robotAncien::PeutAllerEn(int dx, int dy) const
{
	return !(dx && dy) && abs(dx) <= 1 && abs(dy) <= 1 ;
}
