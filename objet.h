#ifndef OBJET_H
#define OBJET_H

class objet {
public:
	virtual ~objet(); //Destructeur (virtuelle)

	virtual bool PeutAllerEn(int dx, int dy) const = 0; //M�thode pour savoir si l'objet peut �tre d�placer (virtuelle)

	virtual char typeObjet() const; //M�thode pour conna�tre le type de l'objet (virtuelle)

	class TYPES { //Class permettant de donner un type aux objets
	public:
		static constexpr char OBJET = 'O'; 		/** Pas utile je pense */
		static constexpr char ROBOT = 'R';
		static constexpr char ROBOT_ANCIEN = 'A'; 
		static constexpr char ROBOT_NOUVEAU = 'N';
		static constexpr char ROBOT_PERSO = 'P';
		static constexpr char JOUEUR = 'J';
		static constexpr char JOUEUR_BASE = 'B';
		static constexpr char JOUEUR_EXPERT = 'E';
		static constexpr char MUR = 'M';
		static constexpr char DEBRIS = 'D';
		static constexpr char VIDE = '.';
	};
};

#endif // OBJET_H
