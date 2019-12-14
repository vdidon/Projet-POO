#include"localisation.h"

localisation::localisation() : localisation {0,0}
{}

localisation::localisation(int x, int y) : d_x{x}, d_y{y}
{}

int localisation::x() const
{
  return d_x;
}

int localisation::y() const
{
  return d_y;
}

void localisation::moveTo(double x, double y)
{
  d_x = x; d_y = y;
}