#ifndef OBJET_H
#define OBJET_H

class objet {
public:
	virtual ~objet() = default; //Destructeur (virtuelle)

	virtual bool PeutAllerEn(int x, int y) const = 0; //Méthode pour savoir si l'objet peut être déplacer (virtuelle)

	virtual char typeObjet() const; //Méthode pour connaître le type de l'objet (virtuelle)

	class TYPES { //Class permettant de donner un type aux objets
	public:
		static constexpr char OBJET = 'O';
		static constexpr char ROBOT = 'R';
		static constexpr char ROBOT_ANCIEN = 'A';
		static constexpr char ROBOT_NOUVEAU = 'N';
		static constexpr char ROBOT_PERSO = 'A';
		static constexpr char JOUEUR = 'J';
		static constexpr char JOUEUR_BASE = 'B';
		static constexpr char JOUEUR_EXPERT = 'E';
		static constexpr char MUR = 'M';
		static constexpr char DEBRIS = 'D';
		static constexpr char VIDE = ".";
	};
};

#endif // OBJET_H
