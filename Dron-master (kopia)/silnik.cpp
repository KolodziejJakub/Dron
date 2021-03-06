#include "silnik.hh"

static const int LICZBA_KROKOW_DLA_ANIMACJI = 15; // każdy ruch jest dzielony na 15 mniejszych ruchów, tak żeby animacja była płynna
static const int CZAS_TRWANIA_POJEDYNCZEGO_KROKU = 50;  // w ms, więc kazda animacja będzie trwać 0,75s

static const int minX = -10;
static const int maxX = 10;
static const int minY = minX;
static const int maxY = maxX;
static const int minZ = minX;
static const int maxZ = maxX;

Silnik::Silnik()
    : gnutplotApi(minX,maxX,minY,maxY,minZ,maxZ,-1), // ustaw change_ref_time_ms na -1, tak żeby mieć większą kontrolę nad tym kiedy widok jest odświeżany
      dron(stworzDrona()),
      przeszkoda(stworzPrzeszkoda()),
      dno(&gnutplotApi, minZ + 1, minX, maxX, minY, maxY),
      taflaWody(&gnutplotApi, maxZ - 3, minX, maxX, minY, maxY)
{
    dno.ustawKolor("grey");
    taflaWody.ustawKolor("blue");

    gnutplotApi.redraw();
}

void Silnik::obrocDrona(double kat)
{
    double katKrok = kat / LICZBA_KROKOW_DLA_ANIMACJI;

    for (int i = 0; i < LICZBA_KROKOW_DLA_ANIMACJI; ++i) {
        dron.rotacja(katKrok);
        gnutplotApi.redraw();
        std::this_thread::sleep_for(std::chrono::milliseconds(CZAS_TRWANIA_POJEDYNCZEGO_KROKU));
    }
}

void Silnik::wykonajRuchDrona(double kat, double odleglosc)
{
    double odlKrok = odleglosc / LICZBA_KROKOW_DLA_ANIMACJI;

    double przesuniecieZ = odleglosc * sin(kat * M_PI/180);
    bool czyWDol = przesuniecieZ < -0.000001;

    for (int i = 0; i < LICZBA_KROKOW_DLA_ANIMACJI; ++i) {
        dron.wykonajRuch(kat, odlKrok);
        if (czyWDol) {
            // sprawdzamy tylko jeśli poruszamy sie "w dół"
            if (dno.pobierzZ() > dron.minZ()) {
                std::cout << "Osiągnięto dno! Ruch drona został przerwany" << endl;
                // teraz musimy zaktualizować wartość Z dla drona, żeby nie był poniżej dna
                dron.zmienZDlaDolnejPodstawyOWartosc(dno.pobierzZ() - dron.minZ());
                gnutplotApi.redraw();
                break;
            }
        } else {
            double zDlaTaflyWody = taflaWody.wyznaczZ(dron.srodek()[0]);
            // pozwalamy się wyburzyć, tak żeby środek podstawy nie wystawał ponad tafle wody
            if (zDlaTaflyWody < dron.zDlaDolnejPodstawy()) {
                dron.zmienZDlaDolnejPodstawyOWartosc(zDlaTaflyWody - dron.zDlaDolnejPodstawy());
            }
        }

        gnutplotApi.redraw();
        std::this_thread::sleep_for(std::chrono::milliseconds(CZAS_TRWANIA_POJEDYNCZEGO_KROKU));
    }
}

void Silnik::resetDoDomyslnegoPolozenia()
{
    dron.usunZGnuPlota();
    dron = stworzDrona();
    gnutplotApi.redraw();
}

Dron Silnik::stworzDrona()
{
    Dron dron(&gnutplotApi, 0, 0, 0, 3, 2, 2);
    dron.ustawKolor("red");
    return dron;
}

Przeszkoda Silnik::stworzPrzeszkoda()
{
    Przeszkoda przeszkoda(&gnutplotApi, 3, 3, 0, 2, 2, 2);
    przeszkoda.ustawKolor("green");
    return przeszkoda;
}
