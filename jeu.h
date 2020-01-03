#ifndef JEU_H
#define JEU_H

#include "terrain.h"
#include <iostream>
#include <string>

// A voir si on aura besoin d'autres #include

class jeu
{
public:

	/**
	Initialise la classe jeu
	*/
	jeu();

	/**
	Lance le menu principal du jeu
	*/
	void run();

	// int score() ;

private:

	/**
	Permet de d�placer un objet de coordonn�es (x1,y1) en (x2,y2)
	@param x1 - Coordonn�es x de d�part de l'objet
	@param y1 - Coordonn�es y de d�part de l'objet
	@param x2 - Coordonn�es x d'arriv� de l'objet
	@param y2 - Coordonn�es y d'arriv� de l'objet
	*/
	//void deplacerObjet(int x1, int y1, int x2, int y2, char objet);

	/**
	Lance une partie de jeu
	*/
	void lancerJeu();

	/**
	Permet d'acc�der au menu de configuration du jeu
	*/
	void configuration();

	/**
	Permet d'acc�der au menu de customisation du terrain
	*/
	void customiserTerrain();

	// Si on a le temps
	//int d_score ;
	terrain d_terrain;
};

#endif // JEU_H
