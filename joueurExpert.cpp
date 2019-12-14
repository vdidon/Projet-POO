#include "joueurExpert.h"

joueurExpert::joueurExpert(const localisation &pos):d_vivant{true}, d_coordonnee{pos}
{}

bool joueurExpert::deplaceEn(int x, int y)
{
	d_coordonnee.moveTo(x,y);
}
