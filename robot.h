#ifndef ROBOT_H
#define ROBOT_H

#include "objet.h"

class robot : public objet {
public :
	virtual ~robot() override;
	//virtual char typeObjet() const override;
};

#endif // ROBOT_H
