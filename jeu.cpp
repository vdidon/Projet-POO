#include "jeu.h"

jeu::jeu() : d_terrain{}
{}

void jeu::run()
{
	int choix = INT_MAX;
	do
	{
		cout << "Menu : (Entrer le numero correspondant a l'action que vous voulez effectuer) " << endl;
		cout << "1 --> Lancer le jeu." << endl;
		cout << "2 --> Configuration." << endl;
		cout << "0 --> Quitter" << endl;
		cout << "Quel est votre choix : ";
		cin >> choix;
		cout << endl;
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

bool jeu::verificationDeplacement(int x1, int y1, int x2, int y2)
{
	if (d_terrain.typeCase(x2, y2) == objet::TYPES::JOUEUR_BASE || d_terrain.typeCase(x2, y2) == objet::TYPES::JOUEUR_EXPERT)
	{
		return true;
	}
	else if (d_terrain.typeCase(x2, y2) != objet::TYPES::VIDE)
	{
		//Supprime les deux objets
		d_terrain.AjouterObjet(x1, y1, objet::TYPES::VIDE);
		d_terrain.AjouterObjet(x2, y2, objet::TYPES::VIDE);
		//Cree un debris a l'emplacement du deuxieme objet
		d_terrain.AjouterObjet(x2, y2, objet::TYPES::DEBRIS);
	}
	else
	{
		d_terrain.deplacerObjet(x1, y1, x2, y2);
	}
	return false;
}

void jeu::lancerJeu()
{
	int joueurPresent = 0;
	int joueurX, joueurY;
	bool auMoinsUnRobot = false;
	for (int i = 0; i < d_terrain.hauteur() && (joueurPresent < 1 || auMoinsUnRobot == false); ++i)
	{
		for (int j = 0; j < d_terrain.largeur() && (joueurPresent < 1 || auMoinsUnRobot == false); ++j)
		{
			if (d_terrain.typeCase(i, j) == objet::TYPES::JOUEUR_BASE || d_terrain.typeCase(i, j) == objet::TYPES::JOUEUR_EXPERT)
			{
				joueurPresent++;
				joueurX = i;
				joueurY = j;
			}
			if (d_terrain.typeCase(i, j) == objet::TYPES::ROBOT_ANCIEN || d_terrain.typeCase(i, j) == objet::TYPES::ROBOT_NOUVEAU || d_terrain.typeCase(i, j) == objet::TYPES::ROBOT_PERSO)
			{
				auMoinsUnRobot = true;
			}
		}
	}
	if (joueurPresent < 1 || joueurPresent > 1 || auMoinsUnRobot == false)
	{
		cout << "ERREUR : Verifier que les conditions suivantes soient remplies :" << endl;
		cout << "- Il ne doit y avoir qu'un seul objet joueur dans le terrain" << endl;
		cout << "- Il doit y avoir au moins un objet robot dans le terrain" << endl;
		cout << "Retour au menu principal" << endl;
		cout << endl;
		return;
	}
	else
	{
		bool partieFinie = false;
		bool victoireJoueur = false;
		bool accidentDuJoueur = false;
		char typeJoueur = d_terrain.typeCase(joueurX, joueurY);
		joueur* objetJoueur = dynamic_cast<joueur*>(d_terrain.Case(joueurX, joueurY));
		int x, y;
		while (partieFinie == false)
		{
			d_terrain.AffichageTerrain();
			cout << endl;

			int nbRobotsRestant = 0;
			cout << "Entrer l'incrementation des coordonnees du joueur en x : ";
			cin >> x;
			cout << "Entrer l'incrementation des coordonnees du joueur en y : ";
			cin >> y;
			if (objetJoueur->PeutAllerEn(x, y))
			{
				if (d_terrain.typeCase(joueurX + x, joueurY + y) == objet::TYPES::VIDE)
				{
					d_terrain.deplacerObjet(joueurX, joueurY, joueurX + x, joueurY + y);
					joueurX += x;
					joueurY += y;
				}
				else
				{
					partieFinie = true;
					accidentDuJoueur = true;
				}
			}
			for (int i = 0; i < d_terrain.hauteur(); ++i)
			{
				for (int j = 0; j < d_terrain.largeur(); ++j)
				{
					if (d_terrain.typeCase(i, j) == objet::TYPES::ROBOT_ANCIEN || d_terrain.typeCase(i, j) == objet::TYPES::ROBOT_NOUVEAU || d_terrain.typeCase(i, j) == objet::TYPES::ROBOT_PERSO)
					{
						objet* objetRobot = d_terrain.Case(i, j);
						nbRobotsRestant++;
						if (i < joueurX)
						{
							if (j < joueurY)
							{
								if (objetRobot->PeutAllerEn(i + 1, j + 1))
								{
									partieFinie = verificationDeplacement(i, j, i + 1, j + 1);
								}
								else
								{
									if (x - i < y - j)
									{
										partieFinie = verificationDeplacement(i, j, i + 1, j);
									}
									else
									{
										partieFinie = verificationDeplacement(i, j, i, j + 1);
									}
								}
							}
							else if (j > joueurY)
							{
								if (objetRobot->PeutAllerEn(i + 1, j - 1))
								{
									partieFinie = verificationDeplacement(i, j, i + 1, j - 1);
								}
								else
								{
									if (x - i < y - j)
									{
										partieFinie = verificationDeplacement(i, j, i + 1, j);
									}
									else
									{
										partieFinie = verificationDeplacement(i, j, i, j - 1);
									}
								}
							}
							else
							{
								partieFinie = verificationDeplacement(i, j, i + 1, j);
							}
						}
						else if (i > joueurX)
						{
							if (j < joueurY)
							{
								if (objetRobot->PeutAllerEn(i - 1, j + 1))
								{
									partieFinie = verificationDeplacement(i, j, i - 1, j + 1);
								}
								else
								{
									if (x - i < y - j)
									{
										partieFinie = verificationDeplacement(i, j, i - 1, j);
									}
									else
									{
										partieFinie = verificationDeplacement(i, j, i, j + 1);
									}
								}
							}
							else if (j > joueurY)
							{
								if (objetRobot->PeutAllerEn(i - 1, j - 1))
								{
									partieFinie = verificationDeplacement(i, j, i - 1, j - 1);
								}
								else
								{
									if (x - i < y - j)
									{
										partieFinie = verificationDeplacement(i, j, i - 1, j);
									}
									else
									{
										partieFinie = verificationDeplacement(i, j, i, j - 1);
									}
								}
							}
							else
							{
								partieFinie = verificationDeplacement(i, j, i - 1, j);
							}
						}
						else
						{
							if (j < joueurY)
							{
								partieFinie = verificationDeplacement(i, j, i, j + 1);
							}
							else
							{
								partieFinie = verificationDeplacement(i, j, i, j - 1);
							}
						}
					}
				}
			}
			if (nbRobotsRestant == 0)
			{
				partieFinie = true;
				victoireJoueur = true;

			}
		}
		if (victoireJoueur == true)
		{
			cout << endl;
			d_terrain.AffichageTerrain();
			cout << "GAGNE :D" << endl;
			cout << "Il ne reste plus aucun robot sur le terrain." << endl;
			cout << "Retour au menu principal ..." << endl;
			cout << endl;
		}
		else if (accidentDuJoueur == true)
		{
			cout << endl;
			d_terrain.AffichageTerrain();
			cout << "PERDU :(" << endl;
			cout << "Le joueur aux coordonnees (" << joueurX << ',' << joueurY << ") est entre dans";
			cout << "l'objet de type [" << d_terrain.typeCase(joueurX + x, joueurY + y) << "] aux coordonnees (" << joueurX + x << ',' << joueurY + y << ")." << endl;
			cout << "Retour au menu principal ..." << endl;
			cout << endl;
		}
		else
		{
			cout << endl;
			d_terrain.AffichageTerrain();
			cout << "PERDU :(" << endl;
			cout << "Un robot a ecrase le joueur" << endl;
			cout << "Retour au menu principal ..." << endl;
			cout << endl;
		}
	}
}

void jeu::configuration()
{
	int choix = INT_MAX;
	do
	{
		cout << "Menu de configuration :" << endl;
		cout << "1 --> Customiser le terrain." << endl;
		cout << "2 --> Charger un terrain depuis un fichier texte." << endl;
		cout << "3 --> Sauvegarder le terrain existant dans un fichier texte." << endl;
		cout << "0 --> Retourner au menu precedent." << endl;
		cout << "Votre choix : ";
		cin >> choix;
		cout << endl;
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
		cout << "Entrer le nom du fichier dans lequel est contenu le terrain  (N'entrez pas le .txt avec) : ";
		cin >> nomFichier;
		d_terrain.chargerTerrain(nomFichier);
		configuration();
		break;
	}

	case 3:
	{
		std::string nomFichier;
		cout << "Entrer le nom du fichier dans lequel vous voulez sauvegarder le terrain (N'entrez pas le .txt avec) : ";
		cin >> nomFichier;
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
		cout << "Que voulez-vous faire : " << endl;
		cout << "1 --> Modifier la taille du tableau" << endl;
		cout << "2 --> Modifier une case du terrain" << endl;
		cout << "0 --> Revenir au menu precedent" << endl;
		cin >> choix;
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
			cout << "Voulez-vous modifier :" << endl;
			cout << "1 --> la hauteur" << endl;
			cout << "2 --> la largeur" << endl;
			cin >> choix2;
		} while (choix2 != 1 && choix2 != 2);
		if (choix2 == 1)
		{
			int hauteur = 0;
			do
			{
				cout << "Entrer la hauteur souhaitee : ";
				cin >> hauteur;
			} while (hauteur < 1);
			d_terrain.ChangerHauteur(hauteur);
		}
		else
		{
			int largeur = 0;
			do
			{
				cout << "Entrer la largeur souhaitee : ";
				cin >> largeur;
			} while (largeur < 1);
			d_terrain.ChangerLargeur(largeur);
		}
		customiserTerrain();
		break;

	case 2:
		int x = -1, y = -1;
		do
		{
			cout << "Entrer les coordonnees souhaite a modifier : ";
			cin >> x >> y;
		} while (x < 0 || y < 0);
		if (d_terrain.Case(x, y) == nullptr)
		{
			char objet;
			do
			{
				cout << "Indiquer le type de l'objet a ajouter :";
				cin >> objet;
			} while (d_terrain.CaractereInvalide(objet));
			d_terrain.AjouterObjet(x, y, objet);
		}
		else
		{
			int choix2 = 0;
			do
			{
				cout << "Case occupe par un objet" << endl;
				cout << "Souhaitez-vous le modifier ou le supprimer ?" << endl;
				cout << "1 --> Modifier le type de l'objet" << endl;
				cout << "2 --> Supprimer l'objet" << endl;
				cin >> choix2;
			} while (choix2 < 1 || choix2 > 2);
			if (choix2 == 1)
			{
				char objet;
				do
				{
					cout << "Indiquer le type de l'objet souhaite :";
					cin >> objet;
				} while (d_terrain.CaractereInvalide(objet));
				d_terrain.AjouterObjet(x, y, objet);
			}
			else
			{
				d_terrain.AjouterObjet(y, x, objet::TYPES::VIDE);
				cout << "Objet en case de coordonnees (" << x << ',' << y << ") a ete supprime !" << endl;
			}
		}
		customiserTerrain();
		break;
	}
}
