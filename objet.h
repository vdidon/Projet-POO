#ifndef OBJET_H
#define OBJET_H

class objet
{
    virtual ~objet() ;
    virtual bool deplace(int x, int y) = 0 ;
    virtual char typeObjet() const = 0 ;
};

#endif // OBJET_H
