#ifndef SILNIK_HH
#define SILNIK_HH

#include "dron.hh"
#include "Dr3D_gnuplot_api.hh"
#include "sroba.hh"
#include "taflawody.hh"
#include "przeszkoda.hh"

// Główna klasa, która odpowiada za prawidłowe wyświetlanie obiektów w gnuplocie oraz za wykrywanie kolizji z dnem/powierzchnią
class Silnik
{
public:
    Silnik();

    void obrocDrona(double kat);
    void wykonajRuchDrona(double kat, double odleglosc);
    void resetDoDomyslnegoPolozenia();

private:
    Dron stworzDrona();
    Przeszkoda stworzPrzeszkoda();


    drawNS::APIGnuPlot3D gnutplotApi;

    Dron dron;
    Przeszkoda przeszkoda;
    //Dron szar, ziel;
    Powierzchnia dno;
    TaflaWody taflaWody; // chwilowo użyj tej samej klasy dla powierzchni
};

#endif // SILNIK_H
