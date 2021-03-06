#ifndef SROBA_HH
#define SROBA_HH

#include "obiektzmozliwosciaruchuirotacji.hh"

// Sroba jest reprezentowana przez graniastosłop z sześciokątem foremynm w podstawie
class Sroba : public ObiektZMozliwosciaRuchuIRotacji
{
public:
    // a - bok szesciakata formnego
    Sroba(drawNS::APIGnuPlot3D *gnuplotAPI, const Point3D &p, double a, double H);

private:
    Wektor srodek() override;
    std::vector<std::pair<uint, uint>> powierzchnie() const override;

    double kierunekXY() const override;
};

#endif // SROBA_H
