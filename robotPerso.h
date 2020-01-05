#ifndef ROBOTPERSO_H
#define ROBOTPERSO_H

#include "robot.h"

#include <vector>

class robotPerso : public robot
{
    public :

        robotPerso(unsigned int vitesse, const std::vector <bool> &direction, const char &Type_Robot_Perso = objet::TYPES::ROBOT_PERSO) ;
        virtual ~robotPerso() ;
        virtual bool PeutAllerEn(int dx, int dy) const override ;
        virtual char typeObjet() const override ;
        unsigned int get_vitesse() const ;
        bool get_direction(int i) const ;

    private :

        /**
            Vitesse du robot � chaque tour
        */
        unsigned int d_vitesse ;

        /**
            Directions dans lesquels peut se d�placer un robot
            Verticalement (1�re case) puis dans le sens des aiguilles d'une montre
        */
        std::vector <bool> d_direction ;

        bool bonneDirection(int dx, int dy) const ;
};

#endif // ROBOTPERSO_H
