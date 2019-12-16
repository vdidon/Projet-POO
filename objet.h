#ifndef OBJET_H
#define OBJET_H

class objet {
public:
			// virtual objet(); CODEBLOCKS met une erreur : error: constructors cannot be declared 'virtual' [-fpermissive]|
	virtual ~objet() = default; //Destructeur (virtuelle)

	virtual bool PeutAllerEn(int x, int y) const = 0; //M�thode pour savoir si l'objet peut �tre d�placer (virtuelle)

	virtual char typeObjet() const; //M�thode pour conna�tre le type de l'objet (virtuelle)

	class TYPES { //Class permettant de donner un type aux objets
	public:
		static constexpr char OBJET = 'O'; 		/** Pas utile je pense */
		static constexpr char ROBOT = 'R';
		static constexpr char ROBOT_ANCIEN = 'A'; /** Changement de nom, j'ai mis RA � la place de A - pour moi, plus parlant */
		static constexpr char ROBOT_NOUVEAU = 'N'; /** Changement de nom, j'ai mis RN � la place de N - pour moi, plus parlant */
		static constexpr char ROBOT_PERSO = 'P'; /** Changement de nom, j'ai mis RP � la place de A - pour moi, plus parlant */
		static constexpr char JOUEUR = 'J';
		static constexpr char JOUEUR_BASE = 'B'; /** Changement de nom, j'ai mis JB � la place de B - pour moi, plus parlant */
		static constexpr char JOUEUR_EXPERT = 'E'; /** Changement de nom, j'ai mis JE � la place de E - pour moi, plus parlant */
		static constexpr char MUR = 'M';
		static constexpr char DEBRIS = 'D';
		static constexpr char VIDE = '.';
	};
};

#endif // OBJET_H
