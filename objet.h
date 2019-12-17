#ifndef OBJET_H
#define OBJET_H

class objet
{
    public :

        /**
            Destructeur (virtuel)
        */
        virtual ~objet() ;

        /**
            Méthode pour savoir si l'objet peut être déplacer (virtuelle)
        */
        virtual bool PeutAllerEn(int dx, int dy) const = 0 ;

        /**
            Méthode pour connaître le type de l'objet (virtuelle)
        */
        virtual char typeObjet() const ;

        /**
            Classe permettant de donner un type aux objets
        */
        class TYPES
        {
            public :

                static constexpr char ROBOT_ANCIEN = 'A' ;
                static constexpr char ROBOT_NOUVEAU = 'N' ;
                static constexpr char ROBOT_PERSO = 'P' ;
                static constexpr char JOUEUR_BASE = 'B' ;
                static constexpr char JOUEUR_EXPERT = 'E' ;
                static constexpr char MUR = 'M' ;
                static constexpr char DEBRIS = 'D' ;
                /**
                    Du coup, il faut rajouter aussi les abstrait : Objet, Robot, Joueur
                */
                static constexpr char OBJET = 'O' ;
                static constexpr char ROBOT = 'R' ;
                static constexpr char JOUEUR = 'J' ;
        };
};

#endif // OBJET_H
