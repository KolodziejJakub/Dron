#include "taflawody.hh"

double TaflaWody::wyznaczZ(double x) const
{
    return pobierzZ() + cos(x);
}
