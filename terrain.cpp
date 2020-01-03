#include "terrain.h"

terrain::terrain(int hauteur, int largeur) : d_tableau(hauteur, std::vector <objet*>(largeur))
{
    for(int i = 0 ; i < hauteur ; i++)
    {
        for(int j = 0 ; j < largeur ; j++)
        {
            AjouterObjet(i, j, '.') ;
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
    d_tableau.resize(x) ;
    for(int i = 0 ; i < d_tableau.size() ; ++i)
    {
        d_tableau[i].resize(largeur()) ;
    }
}

void terrain::ChangerLargeur(int y)
{
    for(int i = 0 ; i < hauteur() ; ++i)
    {
        d_tableau[i].resize(y) ;
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

void terrain::AjouterObjet(int ligne, int colonne, const char &Type_Objet)
{
    objet *ObjetACreer ;
    /** Vérification du type de l'Objet au cas où un caractère invalide à été entré par erreur */
    if(CaractereInvalide(Type_Objet))
    {
        cout << "==> ERREUR DE CREATION : un caractere non valide qui est " << Type_Objet << " voulant etre creer en position (" << ligne << ", " << colonne << ") ne correspond a aucun objet.\n" ;
        cout << "--> Les seuls objets possibles sont representes par : " << objet::TYPES::DEBRIS << " (debris), " << objet::TYPES::JOUEUR_BASE << " (Joueur de base), " << objet::TYPES::JOUEUR_EXPERT << " (Joueur Expert), " << objet::TYPES::MUR << " (Mur), " << objet::TYPES::ROBOT_ANCIEN << " (Robot 1ere generation), " << objet::TYPES::ROBOT_NOUVEAU << " (Robot de 2e generation), " << objet::TYPES::ROBOT_PERSO << " (Robot Personnalisable (+ ses caracteristiques)) et " << objet::TYPES::VIDE << " (Case vide)" ;
    }
    /*else
    {
	    delete d_tableau[ligne][colonne] ;
    }*/ // POURQUOI ???
    switch(Type_Objet)
    {
        case objet::TYPES::VIDE :
            ObjetACreer = new CaseVide(Type_Objet) ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::DEBRIS :
            ObjetACreer = new debris(Type_Objet) ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::JOUEUR_BASE :
            ObjetACreer = new joueurBase(Type_Objet) ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::JOUEUR_EXPERT :
            ObjetACreer = new joueurExpert(Type_Objet) ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::MUR :
            ObjetACreer = new mur(Type_Objet) ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::ROBOT_ANCIEN :
            ObjetACreer = new robotAncien(Type_Objet) ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::ROBOT_NOUVEAU :
            ObjetACreer = new robotNouveau(Type_Objet) ;
            d_tableau[ligne][colonne] = ObjetACreer ;
            break ;

        case objet::TYPES::ROBOT_PERSO :
            int vitesseDeplacement ;
            bool direct[8] ;
            ObjetACreer = new robotPerso(vitesseDeplacement, direct, Type_Objet) ;
            d_tableau[ligne][colonne] = ObjetACreer ;

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
        f << H << " " << L << '\n' ;
        for(int i = 0 ; i < H ; i++)
        {
            for(int j = 0 ; j < L ; j++)
            {
                int Position_X = i, Position_Y = j ;
                auto Objet = typeCase(Position_X, Position_Y) ;
                f << Position_X << " " << Position_Y << " " << Objet << '\n' ;
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
                int direction1, direction2, direction3, direction4, direction5, direction6, direction7, direction8, vitesse ;
                f >> vitesse ;
                bool direct[8] ;
                f >> direction1 >> direction2 >> direction3 >> direction4 >> direction5 >> direction6 >> direction7 >> direction8 ;
                direct[0] = direction1 ;
                direct[1] = direction2 ;
                direct[2] = direction3 ;
                direct[3] = direction4 ;
                direct[4] = direction5 ;
                direct[5] = direction6 ;
                direct[6] = direction7 ;
                direct[7] = direction8 ;
                AjouterObjet(Position_X, Position_Y, Objet) ;
                break ;

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
	if(d_tableau[y2][x2]->d_type == objet::TYPES::VIDE)
	{
		/** Echange les pointeurs */
		objet* tmp = d_tableau[y1][x1] ;
		d_tableau[y1][x1] = d_tableau[y2][x2] ;
		d_tableau[y2][x2] = tmp ;
	}
	else
	{
		/** Colision entre 2 objets */
		delete d_tableau[y1][x1] ;
		delete d_tableau[y2][x2] ;
		d_tableau[y1][x1] = new CaseVide ;
		d_tableau[y2][x2] = new debris ;
	}
}
