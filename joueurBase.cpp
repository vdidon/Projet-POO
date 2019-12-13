#include "joueurBase.h"


joueurBase::joueurBase(const localisation &pos):d_vivant{true}, d_coordonnee{pos}
{}

bool joueurBase::deplaceEn(int x, int y)
{
    d_coordonnee.moveTo(x,y);
}
void joueurBase::tuer()
{
    d_vivant=false;
}

bool joueurBase::estVivant() const
{
    return d_vivant;
}

localisation joueurBase::position() const
{
    return d_coordonnee;
}