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


class Dron : public ObiektZMozliwosciaRuchuIRotacji, public Prostopad
{    
public:
    //konstruktor w którym wyznaczam zależności współrzędnych każdego punktu w zależności punktu S
    Dron(drawNS::APIGnuPlot3D *gnuplotAPI, int x, int y, int z, float a, float b, float c);

    double kierunekXY() const override;

    double zDlaDolnejPodstawy() const;

    Wektor srodek() override;

private:
    std::vector<std::pair<uint, uint>> powierzchnie() const override;
};

#endif
