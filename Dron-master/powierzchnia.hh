#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include "obiekt.hh"

class Powierzchnia : public Obiekt
{
public:
    Powierzchnia(drawNS::APIGnuPlot3D *gnuplotAPI, int z, int startX = -5, int endX = 5, int startY = -5, int endY = 5);

    virtual std::vector<std::vector<Point3D> > surface() const;

    // Domyślnie zwraca wartość przekazną w konstruktorze,
    // ale może zmienić zachowanie tak, żeby tworzyć "niestandardowe" powierzchnie
    virtual double wyznaczZ(double x) const;

    double pobierzZ() const;

private:
    int z;
    int startX = -5;
    int endX = 5;
    int startY = -5;
    int endY = 5;
};

#endif // POWIERZCHNIA_H
