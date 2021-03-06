#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "prostopadl.hh"
#include "Wektor.hh"
#include "Macierz.hh"

#include <vector>
#include "Dr3D_gnuplot_api.hh"
#include "obiektzmozliwosciaruchuirotacji.hh"
#include "sroba.hh"

using drawNS::Point3D;

//clasa dron dziedziczy z prostopad długości boków oraz z bryly orientacje
// metody na wyliczenie orientacji są w bryle, natomiast w tej klasie jest metoda na wyliczanie wierzcholkow po ruchu
class Dron : public ObiektZMozliwosciaRuchuIRotacji, public Prostopad
{    
public:
    //konstruktor w którym wyznaczam zależności współrzędnych każdego punktu w zależności punktu S
    Dron(drawNS::APIGnuPlot3D *gnuplotAPI, int x=0, int y=0, int z=0, float a=3, float b=2, float c=2);

    double kierunekXY() const override;

    double zDlaDolnejPodstawy() const;

    Wektor srodek() override;

private:
    std::vector<std::pair<uint, uint>> powierzchnie() const override;
};

#endif
