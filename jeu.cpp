#include "jeu.h"


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
		return;
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


/*void jeu::deplacerObjet(int x1, int x2, int y1, int y2, char objet)
{
	if (d_terrain.typeCase(x2, y2) == '.')
	{
		d_terrain.ChangerTypeObjet(x2, y2, objet);
		d_terrain.ChangerTypeObjet(x1, y1, '.');
	}
	else
	{
		d_terrain.ChangerTypeObjet(x2, y2, 'D');
	}
}*/

void jeu::lancerJeu()
{
	// Plan de la méthode :
	/*
		D'abord vérifier qu'il y a un objet joueur (type quelconque) et au moins un robot
		Enregistrer la position du joueur pour éviter de devoir la chercher à nouveau
		Dans la boucle :
			Afficher le terrain
			Demander au joueur de déplacer son objet
			Déplacer les robots en fonction du joueur
			Vérifier si des robots se sont fait détruire, ou si le joueur a perdu
				--> Si le joueur n'a pas perdu et il reste des robots, Afficher le terrain et recommencer la boucle
				--> Si le joueur a perdu, afficher game over et quitter la boucle
				--> Si le joueur n'a pas perdu et il ne reste plus de robots, afficher Gagné et quitter la boucle
	*/
	// Ce qu'il reste à faire :
	/*
		- Vérifier que cela fonctionne
		- L'optimiser
	*/
	int joueurPresent = 0;
	int joueurX, joueurY;
	bool auMoinsUnRobot = false;
	for (int i = 0; i < d_terrain.hauteur() && (joueurPresent < 1 || auMoinsUnRobot == false); ++i)
	{
		for (int j = 0; j < d_terrain.largeur() && (joueurPresent < 1 || auMoinsUnRobot == false); ++j)
		{
			if (d_terrain.typeCase(i, j) == 'B' || d_terrain.typeCase(i, j) == 'E')
			{
				joueurPresent++;
				joueurX = i;
				joueurY = j;
			}
			if (d_terrain.typeCase(i, j) == 'A' || d_terrain.typeCase(i, j) == 'N' || d_terrain.typeCase(i, j) == 'P')
			{
				auMoinsUnRobot = true;
			}
		}
	}
	if (joueurPresent < 1 || joueurPresent > 1 || auMoinsUnRobot == false)
	{
		std::cout << "ERREUR : Vérifier que les conditions suivantes soient remplies :" << std::endl;
		std::cout << "- Il ne doit y avoir qu'un seul objet joueur dans le terrain" << std::endl;
		std::cout << "- Il doit y avoir au moins un objet robot dans le terrain" << std::endl;
		std::cout << "Retour au menu principal" << std::endl;
		std::cout << std::endl;
		return;
	}
	else
	{
		bool partieFinie = false;
		char typeJoueur = d_terrain.typeCase(joueurX, joueurY);
		/*
		 * Pourquoi différencier les 2 cas ? (fonction PeutAllerEn(int dx, int dy))
		 * Proposition :
		 * objet* objetJoueur = d_terrain.Case(joueurX, joueurY)
		 * ou mieux
		 * joueur* objetJoueur = dynamic_cast<joueur *>(d_terrain.Case(joueurX, joueurY))
		 */

		joueur* objetJoueur = dynamic_cast<joueur*>(d_terrain.Case(joueurX, joueurY));
		while (partieFinie == false)
		{
			d_terrain.AffichageTerrain();
			std::cout << std::endl;

			int x, y;
			int nbRobotsRestant = 0;
			std::cout << "Entrer l'incrémentation des coordonnées du joueur en x : ";
			std::cin >> x;
			std::cout << "Entrer l'incrémentation des coordonnées du joueur en y : ";
			std::cin >> y;
			if (objetJoueur->PeutAllerEn(x, y))
			{
				if (d_terrain.typeCase(joueurX + x, joueurY + y) == '.')
				{
					//d_terrain.ChangerTypeObjet(joueurX + x, joueurY + y, objetJoueur->typeObjet());
					//d_terrain.ChangerTypeObjet(joueurX, joueurY, '.');
					d_terrain.deplacerObjet(joueurX, joueurY,joueurX + x, joueurY + y);
					joueurX += x;
					joueurY += y;

					for (int i = 0; i < d_terrain.hauteur(); ++i)
					{
						for (int j = 0; j < d_terrain.largeur(); ++i)
						{
							if (d_terrain.typeCase(i, j) == 'A' || d_terrain.typeCase(i, j) == 'N' || d_terrain.typeCase(i, j) == 'P')
							{
								objet* objetRobot = d_terrain.Case(i, j);
								nbRobotsRestant++;
								if (i < joueurX)
								{
									if (j < joueurY)
									{
										if (objetRobot->PeutAllerEn(i + 1, j + 1))
										{
											//deplacerObjet(i, j, i + 1, j + 1, objetRobot->typeObjet());
											d_terrain.deplacerObjet(i, j, i + 1, j + 1);
										}
										else
										{
											if (x - i < y - j)
											{
												//deplacerObjet(i, j, i + 1, j, objetRobot->typeObjet());
												d_terrain.deplacerObjet(i, j, i + 1, j);
											}
											else
											{
												//deplacerObjet(i, j, i, j + 1, objetRobot->typeObjet());
												d_terrain.deplacerObjet(i, j, i, j + 1);
											}
										}
									}
									else if (j > joueurY)
									{
										if (objetRobot->PeutAllerEn(i + 1, j - 1))
										{
											//deplacerObjet(i, j, i + 1, j - 1, objetRobot->typeObjet());
											d_terrain.deplacerObjet(i, j, i + 1, j - 1);
										}
										else
										{
											if (x - i < y - j)
											{
												//deplacerObjet(i, j, i + 1, j, objetRobot->typeObjet());
												d_terrain.deplacerObjet(i, j, i + 1, j);
											}
											else
											{
												//deplacerObjet(i, j, i, j - 1, objetRobot->typeObjet());
												d_terrain.deplacerObjet(i, j, i, j - 1);
											}
										}
									}
									else
									{
										//deplacerObjet(i, j, i + 1, j, objetRobot->typeObjet());
										d_terrain.deplacerObjet(i, j, i + 1, j);
									}
								}
								else if (i > joueurX)
								{
									if (j < joueurY)
									{
										if (objetRobot->PeutAllerEn(i - 1, j + 1))
										{
											//deplacerObjet(i, j, i - 1, j + 1, objetRobot->typeObjet());
											d_terrain.deplacerObjet(i, j, i - 1, j + 1);
										}
										else
										{
											if (x - i < y - j)
											{
												//deplacerObjet(i, j, i - 1, j, objetRobot->typeObjet());
												d_terrain.deplacerObjet(i, j, i - 1, j);
											}
											else
											{
												//deplacerObjet(i, j, i, j + 1, objetRobot->typeObjet());
												d_terrain.deplacerObjet(i, j, i, j + 1);
											}
										}
									}
									else if (j > joueurY)
									{
										if (objetRobot->PeutAllerEn(i - 1, j - 1))
										{
											//deplacerObjet(i, j, i - 1, j - 1, objetRobot->typeObjet());
											d_terrain.deplacerObjet(i, j, i - 1, j - 1);
										}
										else
										{
											if (x - i < y - j)
											{
												//deplacerObjet(i, j, i - 1, j, objetRobot->typeObjet());
												d_terrain.deplacerObjet(i, j, i - 1, j);
											}
											else
											{
												//deplacerObjet(i, j, i, j - 1, objetRobot->typeObjet());
												d_terrain.deplacerObjet(i, j, i, j - 1);
											}
										}
									}
									else
									{
										//deplacerObjet(i, j, i - 1, j, objetRobot->typeObjet());
										d_terrain.deplacerObjet(i, j, i - 1, j);
									}
								}
								else
								{
									if (j < joueurY)
									{
										//deplacerObjet(i, j, i, j + 1, objetRobot->typeObjet());
										d_terrain.deplacerObjet(i, j, i, j + 1);
									}
									else
									{
										//deplacerObjet(i, j, i, j - 1, objetRobot->typeObjet());
										d_terrain.deplacerObjet(i, j, i, j - 1);
									}
								}
							}
						}
					}
				}
				else
				{
					std::cout << std::endl;
					d_terrain.AffichageTerrain();
					partieFinie = true;
					std::cout << "PERDU :(" << std::endl;
					std::cout << "Details de la défaite :" << std::endl;
					std::cout << "Le joueur aux coordonnées (" << joueurX << ',' << joueurY << ") est entré dans";
					std::cout << "l'objet de type [" << d_terrain.typeCase(joueurX + x, joueurY + y) << "] aux coordonnées (" << joueurX + x << ',' << joueurY + y << ")." << std::endl;
					std::cout << "Retour au menu principal ..." << std::endl;
					std::cout << std::endl;
				}
			}
			if (nbRobotsRestant == 0)
			{
				std::cout << std::endl;
				d_terrain.AffichageTerrain();
				std::cout << "GAGNE :D" << std::endl;
				std::cout << "Il ne reste plus aucun robot sur le terrain." << std::endl;
				std::cout << "Retour au menu principal ..." << std::endl;
				std::cout << std::endl;
			}
		}
	}

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
			int hauteur = 0;
			do
			{
				std::cout << "Entrer la hauteur souhaitée : ";
				std::cin >> hauteur;
			} while (hauteur < 1);
			d_terrain.ChangerHauteur(hauteur);
		}
		else
		{
			int largeur = 0;
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
		if (d_terrain.Case(x, y) == nullptr)
		{
			char objet;
			do
			{
				std::cout << "Indiquer le type de l'objet à ajouter :";
				std::cin >> objet;
			} while (d_terrain.CaractereInvalide(objet));
			d_terrain.AjouterObjet(x, y, objet);
		}
		else
		{
			int choix2 = 0;
			do
			{
				std::cout << "Case occupé par un objet" << std::endl;
				std::cout << "Souhaitez-vous le modifier ou le supprimer ?" << std::endl;
				std::cout << "1 --> Modifier le type de l'objet" << std::endl;
				std::cout << "2 --> Supprimer l'objet" << std::endl;
				std::cin >> choix2;
			} while (choix2 < 1 || choix2 > 2);
			if (choix2 == 1)
			{
				char objet;
				do
				{
					std::cout << "Indiquer le type de l'objet souhaité :";
					std::cin >> objet;
				} while (d_terrain.CaractereInvalide(objet));
				//d_terrain.ChangerTypeObjet(x, y, objet);
				d_terrain.AjouterObjet(y,x,objet);
			}
			else
			{
				//d_terrain.ChangerTypeObjet(x, y, '.');
				d_terrain.AjouterObjet(y,x,objet::TYPES::VIDE);
				std::cout << "Objet en case de coordonnées (" << x << ',' << y << ") a été supprimé !" << std::endl;
			}
		}
		customiserTerrain();
		break;
	}

}
