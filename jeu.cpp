#include "jeu.h"

// Classe faisant le jeu et sa partie
jeu::jeu() : d_terrain{}
{}

void jeu::run()
{
	int choix = INT_MAX;
	do
	{
		std::cout << "Menu : (Entrer le numéro correspondant à l'action que vous voulez effectué) " << std::endl;
		std::cout << "1 --> Lancer le jeu." << std::endl;
		std::cout << "2 --> Configuration." << std::endl;
		std::cout << "0 --> Quitter" << std::endl;
		std::cout << "Quel est votre choix : ";
		std::cin >> choix;
		std::cout << std::endl;
	} while (choix < 0 || choix > 5);
	switch (choix)
	{
	case 0:
		return 0;
		break;
	case 1:
		lancerJeu();
		run();
		break;
	case 2:
		configuration();
		run();
		break;
	}
}

void jeu::lancerJeu()
{
	// A faire
}

void jeu::configuration()
{
	int choix = INT_MAX;
	do
	{
		std::cout << "Menu de configuration :" << std::endl;
		std::cout << "1 --> Customiser le terrain." << std::endl;
		std::cout << "2 --> Charger un terrain depuis un fichier texte." << std::endl;
		std::cout << "3 --> Sauvegarder le terrain existant dans un fichier texte." << std::endl;
		std::cout << "0 --> Retourner au menu précédent." << std::endl;
		std::cout << "Votre choix : ";
		std::cin >> choix;
		std::cout << std::endl;
	} while (choix < 0 || choix > 3);
	switch (choix)
	{
	case 0:
	{
		return;
		break;
	}
	case 1:
	{
		customiserTerrain();
		configuration();
		break;
	}
	case 2:
	{
		std::string nomFichier;
		std::cout << "Entrer le nom du fichier dans lequel est contenu le terrain  (N'entrez pas le .txt avec) : ";
		std::cin >> nomFichier;
		d_terrain.chargerTerrain(nomFichier);
		configuration();
		break;
	}
	case 3:
	{
		std::string nomFichier;
		std::cout << "Entrer le nom du fichier dans lequel vous voulez sauvegarder le terrain (N'entrez pas le .txt avec) : ";
		std::cin >> nomFichier;
		d_terrain.sauvegarder(nomFichier);
		configuration();
		break;
	}
	}
}

void jeu::customiserTerrain()
{
	// À finir

	int choix = INT_MAX;
	do
	{
		std::cout << "Que voulez-vous faire : " << std::endl;
		std::cout << "1 --> Modifier la taille du tableau" << std::endl;
		std::cout << "2 --> Modifier une case du terrain" << std::endl;
		std::cout << "0 --> Revenir au menu précédent" << std::endl;
	} while (choix < 0 || choix > 2);
	switch (choix)
	{
	case 0:
		return;
		break;
	case 1:
		int choix2;
		do
		{
			std::cout << "Voulez-vous modifier :" << std::endl;
			std::cout << "1 --> la hauteur" << std::endl;
			std::cout << "2 --> la largeur" << std::endl;
			std::cin >> choix2;
		} while (choix2 != 1 && choix2 != 2);
		if (choix2 == 1)
		{
			int hauteur;
			do
			{
				std::cout << "Entrer la hauteur souhaitée : ";
				std::cin >> hauteur;
			} while (hauteur < 1);
			d_terrain.ChangerHauteur(hauteur);
		}
		else
		{
			int largeur;
			do
			{
				std::cout << "Entrer la largeur souhaitée : ";
				std::cin >> largeur;
			} while (largeur < 1);
			d_terrain.ChangerLargeur(largeur);
		}
		customiserTerrain();
		break;
	case 2:
		int x = -1, y = -1;
		do
		{
			std::cout << "Entrer les coordonnées souhaité à modifier : ";
			std::cin >> x >> y;
		} while (x < 0 || y < 0);
		if (d_terrain[x][y] == nullptr)
		{
			std::cout << "Case vide : quel objet ajouter ?"
				/* À finir */
				/* Il faut que l'utilisateur puissent créer des objets ici puis les placer dans cette case de coordonnées (x,y) */
		}
		else
		{
			std::cout << "Case occupé par un objet" << std::endl;
			std::cout << "Souhaitez-vous le modifier ou le supprimer ?" << std::endl;
			/* À finir */
			/* L'utilisateur doit avoir le choix entre le modifier ( robotancien --> robotnouveau ? ) ou le supprimer */
		}
		customiserTerrain();
		break;
	}
	
}
