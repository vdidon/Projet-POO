#ifndef LOCALISATION_H
#define LOCALISATION_H

#include<iosfwd>

class localisation {
public:
///Cionstructeur par défaut : point (0,0)
  localisation();
  
/**
  Constructeur avec les coordonnées
  @param x x-coordonnée
  @param y y-coordonnée
*/
  localisation(int x, int y);
  
  ///@return the x-coordonnée
  int x()  const;
///@return the y-coordonnée
  int y()  const;
  
  /**
  Change les coordonées
  @param x the new x-coordonnée
  @param y the new y-coordonnée
*/
void moveTo(double x, double y);

private:


};
#endif
