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
		
		private:
        bool d_vivant;
        localisation d_coordonnee;
};

#endif // JOUEUREXPERT_H
