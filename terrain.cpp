#include "terrain.h"

terrain::terrain(int hauteur, int largeur) : d_tableau(hauteur, std::vector <objet*>(largeur))
{
    for(int i = 0 ; i < hauteur ; i++)
    {
        for(int j = 0 ; j < largeur ; j++)
        {
            //AjouterObjet(i, j, objet::TYPES::VIDE) ;
            d_tableau[i][j] = new CaseVide();
        }
    }
}

terrain::terrain(const terrain &t)
{
    d_tableau.resize(t.hauteur()) ;
    for(int i = 0 ; i < hauteur() ; i++)
    {
        d_tableau[i].resize(t.largeur()) ;
        for(int j = 0 ; j < largeur() ; j++)
        {
            d_tableau[i][j] = t.d_tableau[i][j] ;
        }
    }
}

int terrain::hauteur() const
{
    return d_tableau.size() ;
}

int terrain::largeur() const
{
    /** Il faut faire un test pour savoir si la hauteur est égale à 0,
        car si c'est le cas d_tableau[0] n'existeras pas
    */
    if(hauteur() == 0)
    {
        return 0 ;
    }
    else
    {
        return d_tableau[0].size() ;
    }
}

void terrain::ChangerHauteur(int x)
{
	int ancienneHauteur = hauteur() ;
	if(x < ancienneHauteur)  // Supprimer les objets qui ne sont plus dans le tableau
	{
		for (int i = x ; i < ancienneHauteur ; i++)
        {
			for (int j = 0 ; j < largeur() ; j++)
			{
				delete d_tableau[i][j] ;
			}
		}
	}
	d_tableau.resize(x);
	if(hauteur() > ancienneHauteur)  // On rajoute des cases vides dans les cases supplémentaires
	{
		for(int i = ancienneHauteur ; i < hauteur() ; i++)
        {
			d_tableau[i].resize(largeur());
			for(int j = 0 ; j < largeur() ; j++)
			{
				d_tableau[i][j] = new CaseVide() ;
			}
		}
	}
}

void terrain::ChangerLargeur(int y)
{
	int ancienneLargeur = largeur() ;
	for(int i = 0 ; i < hauteur() ; i++)
	{
		if(y < ancienneLargeur) // Supprimer les objets qui ne sont plus dans le tableau
		{
			for (int j = y ; j < ancienneLargeur ; j++)
			{
				delete d_tableau[i][j] ;
			}
		}
		d_tableau[i].resize(y);
		if(y > ancienneLargeur) // On rajoute des cases vides dans les cases supplémentaires
		{
			for (int j = ancienneLargeur; j < y; ++j)
			{
				d_tableau[i][j]= new CaseVide();
			}
		}
	}
}

objet* terrain::Case(int x, int y) const
{
    return d_tableau[x][y] ;
}

char terrain::typeCase(int lig, int col) const
{
    return Case(lig, col)->typeObjet() ;
}

void terrain::AffichageTerrain() const
{
    for(int i = 0 ; i < hauteur() ; i++)
    {
        for(int j = 0 ; j < largeur() ; j++)
        {
            cout << typeCase(i, j) ;
        }
        cout << endl ;
    }
    cout << endl ;
}

bool terrain::evalCase(int l, int c) const
{
    return (1 <= l && l <= hauteur() && 1 <= c && c <= largeur()) ;
}

bool terrain::CaractereInvalide(const char &TypeObjet) const
{
    return (TypeObjet != objet::TYPES::DEBRIS && TypeObjet != objet::TYPES::JOUEUR_BASE && TypeObjet != objet::TYPES::JOUEUR_EXPERT && TypeObjet != objet::TYPES::MUR && TypeObjet != objet::TYPES::ROBOT_ANCIEN && TypeObjet != objet::TYPES::ROBOT_NOUVEAU && TypeObjet != objet::TYPES::ROBOT_PERSO && TypeObjet != objet::TYPES::VIDE) ;
}

void terrain::AjouterRobotPerso(int Ligne, int Colonne, int &Vitesse, std::vector <bool> &Direction, const char &CaractereRobot, std::ifstream &ist)
{
    Direction.resize(8) ;
    ist >> Vitesse ;
    bool direction1, direction2, direction3, direction4, direction5, direction6, direction7, direction8 ;
    ist >> direction1 >> direction2 >> direction3 >> direction4 >> direction5 >> direction6 >> direction7 >> direction8 ;
    Direction[0] = direction1 ;
    Direction[1] = direction2 ;
    Direction[2] = direction3 ;
    Direction[3] = direction4 ;
    Direction[4] = direction5 ;
    Direction[5] = direction6 ;
    Direction[6] = direction7 ;
    Direction[7] = direction8 ;
    d_tableau[Ligne][Colonne] = new robotPerso(Vitesse, Direction) ;
}

void terrain::AjouterObjet(int ligne, int colonne, const char &Type_Objet)
{
    objet *ObjetACreer ;
    /** Vérification du type de l'Objet au cas où un caractère invalide à été entré par erreur */
    if(CaractereInvalide(Type_Objet))
    {
        cout << "==> ERREUR DE CREATION : un caractere non valide qui est " << Type_Objet << " voulant etre creer en position (" << ligne << ", " << colonne << ") ne correspond a aucun objet.\n" ;
        cout << "--> Les seuls objets possibles sont representes par : " << objet::TYPES::DEBRIS << " (debris), " << objet::TYPES::JOUEUR_BASE << " (Joueur de base), " << objet::TYPES::JOUEUR_EXPERT << " (Joueur Expert), " << objet::TYPES::MUR << " (Mur), " << objet::TYPES::ROBOT_ANCIEN << " (Robot 1ere generation), " << objet::TYPES::ROBOT_NOUVEAU << " (Robot de 2e generation), " << objet::TYPES::ROBOT_PERSO << " (Robot Personnalisable (+ ses caracteristiques)) et " << objet::TYPES::VIDE << " (Case vide)" ;
    }
    else if (d_tableau[ligne][colonne]->typeObjet()!=Type_Objet)
    {
		d_tableau[ligne][colonne] = nullptr ;
	    //delete d_tableau[ligne][colonne] ;
    }
    switch(Type_Objet)
    {
        case objet::TYPES::VIDE :
            ObjetACreer = new CaseVide() ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::DEBRIS :
            ObjetACreer = new debris() ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::JOUEUR_BASE :
            ObjetACreer = new joueurBase() ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::JOUEUR_EXPERT :
            ObjetACreer = new joueurExpert() ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::MUR :
            ObjetACreer = new mur() ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::ROBOT_ANCIEN :
            ObjetACreer = new robotAncien() ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::ROBOT_NOUVEAU :
            ObjetACreer = new robotNouveau() ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::ROBOT_PERSO :
        {
            int vitesseDeplacement ;
            std::vector <bool> direct ;
            std::ifstream f{} ;
            AjouterRobotPerso(ligne, colonne, vitesseDeplacement, direct, Type_Objet, f) ;
        }

        /** Autre cas si un robot customisable est dans le terrain pour éviter d'afficher une erreur qui n'existe pas */
        default :
            if(Type_Objet == 0 || Type_Objet == 1)
            {
                cout << "Erreur, les seuls objets possibles sont representes par : " << objet::TYPES::DEBRIS << " (debris), " << objet::TYPES::JOUEUR_BASE << " (Joueur de base), " << objet::TYPES::JOUEUR_EXPERT << " (Joueur Expert), " << objet::TYPES::MUR << " (Mur), " << objet::TYPES::ROBOT_ANCIEN << " (Robot 1ere generation), " << objet::TYPES::ROBOT_NOUVEAU << " (Robot de 2e generation), " << objet::TYPES::ROBOT_PERSO << " (Robot Personnalisable (+ ses caracteristiques)) et " << objet::TYPES::VIDE << " (Case vide)" ;
            }
    }
}

void terrain::sauvegarder(const std::string &NomFichier) const
{
    std::ofstream f(NomFichier + ".txt") ;
    if(!f)
    {
        return ;
    }
    else
    {
        int H = hauteur(), L = largeur() ;
        f << H << ' ' << L << endl ;
        for(int i = 0 ; i < H ; i++)
        {
            for(int j = 0 ; j < L ; j++)
            {
                int Position_X = i, Position_Y = j ;
                auto Objet = typeCase(Position_X, Position_Y) ;
                f << Position_X << ' ' << Position_Y << ' ' << Objet << endl ;
            }
        }
    }
    f.close() ;
    cout << "==> Le fichier : " << NomFichier + ".txt" << " a bien ete cree" << endl ;
}

terrain& terrain::chargerTerrain(const std::string &NomFichier)
{
    std::ifstream f(NomFichier + ".txt") ;
    if(!f)
    {
        cout << "ERREUR : Impossible de creer le terrain car le fichier " << NomFichier + ".txt" << " n'existe pas" << endl ;
        /**
            Efface entièrement le tableau pour renvoyer un terrain vide
        */
        viderLeTerrain() ;
		d_tableau.clear() ;
        return *this ;
    }
    int Hauteur, Largeur ;
    f >> Hauteur >> Largeur ;
    /**
        Efface totalement le tableau représenant le terrain.
    */
    viderLeTerrain() ;
	d_tableau.clear() ;
    /**
        Redimentionne le tableau
    */
    ChangerHauteur(Hauteur) ;
    ChangerLargeur(Largeur) ;
    while(!f.eof())
    {
        int Position_X, Position_Y ;
        char Objet ;
        f >> Position_X >> Position_Y >> Objet ;
        switch(Objet)
        {
            case objet::TYPES::DEBRIS :
                AjouterObjet(Position_X, Position_Y, Objet) ;
                break ;

            case objet::TYPES::JOUEUR_BASE :
                AjouterObjet(Position_X, Position_Y, Objet) ;
                break ;

            case objet::TYPES::JOUEUR_EXPERT :
                AjouterObjet(Position_X, Position_Y, Objet) ;
                break ;

            case objet::TYPES::MUR :
                AjouterObjet(Position_X, Position_Y, Objet) ;
                break ;

            case objet::TYPES::ROBOT_ANCIEN :
                AjouterObjet(Position_X, Position_Y, Objet) ;
                break ;

            case objet::TYPES::ROBOT_NOUVEAU :
                AjouterObjet(Position_X, Position_Y, Objet) ;
                break ;

            case objet::TYPES::ROBOT_PERSO :
                {int vitesse ;
                std::vector <bool> direct ;
                AjouterRobotPerso(Position_X, Position_Y, vitesse, direct, Objet, f) ;
                break ;}

            case objet::TYPES::VIDE :
	                AjouterObjet(Position_X, Position_Y, Objet) ;
                break ;

            default :
                cout << "==> ERREUR DE CREATION : un caractere non valide qui est " << Objet << " voulant etre creer en position (" << Position_X << ", " << Position_Y << ") ne correspond a aucun objet.\n" ;
                cout << "--> Le terrain contenu dans " << NomFichier + ".txt" << " n'as donc pas pu etre creer" << endl ;
                viderLeTerrain() ;
				d_tableau.clear() ;
                return *this ;
        }
    }
    f.close() ;
    cout << "==> Le fichier : " << NomFichier + ".txt" << " contenant le terrain a creer le terrain : \n" ;
    AffichageTerrain() ;
    cout << "qui est le terrain attendu.\n" ;
    return *this ;
}

void terrain::viderLeTerrain()
{
	for(int i = 0 ; i < hauteur() ; i++)
    {
		for(int j = 0 ; j < largeur() ; j++)
        {
			delete d_tableau[i][j] ;
		}
	}
}

void terrain::deplacerObjet(int x1, int y1, int x2, int y2)
{
    if(typeCase(x1, y1) == objet::TYPES::DEBRIS)
    {
        cout << "On ne peut pas deplacer un debris." ;
        return ;
    }
    if(typeCase(x1, y1) == objet::TYPES::MUR)
    {
        cout << "On ne peut pas deplacer un mur." ;
        return ;
    }
    if(typeCase(x2, y2) == objet::TYPES::DEBRIS)
    {
        cout << "On ne peut pas deplacer un debris." ;
        return ;
    }
    if(typeCase(x2, y2) == objet::TYPES::MUR)
    {
        cout << "On ne peut pas deplacer un mur." ;
        return ;
    }
    if(typeCase(x1, y1) == objet::TYPES::ROBOT_ANCIEN || typeCase(x1, y1) == objet::TYPES::ROBOT_NOUVEAU || typeCase(x1, y1) == objet::TYPES::ROBOT_PERSO)
    {
        if(typeCase(x2, y2) == objet::TYPES::JOUEUR_BASE || typeCase(x2, y2) == objet::TYPES::JOUEUR_EXPERT)
        {
            /** Colision entre un robot et un joueur  */
            cout << "Le joueur est ecrase." ;
            return ;
        }
    }
    /** Echange les pointeurs */
    objet* tmp = d_tableau[x1][y1] ;
    d_tableau[x1][y1] = d_tableau[x2][y2] ;
    d_tableau[x2][y2] = tmp ;
}
