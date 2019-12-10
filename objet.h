#ifndef OBJET_H
#define OBJET_H

class objet {
public:
	virtual ~objet() = default;

	virtual bool deplace(int x, int y) const = 0;

	virtual char typeObjet() const;

	class TYPES {
	public:
		static constexpr char OBJET = 'O';
		static constexpr char ROBOT = 'R';
		static constexpr char ROBOT_ANCIEN = 'A';
		static constexpr char ROBOT_NOUVEAU = 'N';
		static constexpr char ROBOT_PERSO = 'A';
		static constexpr char JOUEUR = 'J';
		static constexpr char JOUEUR_BASE = 'B';
		static constexpr char JOUEUR_EXPERT = 'E';
	};
};

#endif // OBJET_H
