#include "robotPerso.h"

robotPerso::robotPerso(unsigned int vitesse, bool direction[8]) : d_vitesse{vitesse}, d_direction{direction}
{}

robotPerso::~robotPerso()
{}

char robotPerso::typeObjet() const
{
     return objet::TYPES::ROBOT_PERSO ;
}

bool robotPerso::bonneDirection(int dx, int dy) const
{
    if(dx > 0)
    {
	if(dy < 0)
        {
            return d_direction[1] ;
        }
		else
        {
            if(dy == 0)
            {
                return d_direction[2] ;
            }
            else
            {
                return d_direction[3] ;
            }
        }
    }
    else
    {
        if(dx == 0)
        {
            if(dy < 0)
            {
                return d_direction[0] ;
            }
            else
            {
                if(dy == 0)
                {
                    return true ;
                }
                else
                {
                    return d_direction[4] ;
                }
            }
        }
        else
        {
            if(dy < 0)
            {
                return d_direction[5] ;
            }
            else
            {
                if(dy == 0)
                {
                    return d_direction[6] ;
                }
                else
                {
                    return d_direction[7] ;
                }
            }
        }
    }
}

bool robotPerso::PeutAllerEn(int dx, int dy) const
{
	return abs(dx) <= d_vitesse && abs(dy) <= d_vitesse && bonneDirection(dx, dy) ;
}

