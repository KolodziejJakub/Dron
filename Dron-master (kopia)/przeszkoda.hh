#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>
#include "prostopadl.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "dron.hh"

#include <vector>
#include "Dr3D_gnuplot_api.hh"
#include "obiektzmozliwosciaruchuirotacji.hh"
#include "sroba.hh"


class Przeszkoda: public ObiektZMozliwosciaRuchuIRotacji, public Prostopad
{
    private:
    std::vector<std::pair<uint, uint>> powierzchnie() const override;

    public:
    Przeszkoda(drawNS::APIGnuPlot3D *gnuplotAPI, int x, int y, int z, float a, float b, float c);

    double kierunekXY() const override;

    Wektor srodek() override;

    bool czyKolizja(Dron dron/*później wskaźnik na drona*/);
};

#endif