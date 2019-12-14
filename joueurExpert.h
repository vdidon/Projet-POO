#ifndef JOUEUREXPERT_H
#define JOUEUREXPERT_H

#include "joueur.h"

class joueurExpert : public joueur
{
    public :
        joueurExpert(const localisation &pos);
        virtual bool deplaceEn(int x, int y) override ;
		
		virtual void tuer() override ;
        virtual bool estVivant() const override;
        virtual localisation position() const override;
};

#endif // JOUEUREXPERT_H
