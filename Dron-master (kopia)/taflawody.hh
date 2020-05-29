#ifndef TAFLAWODY_HH
#define TAFLAWODY_HH

#include "powierzchnia.hh"

class TaflaWody : public Powierzchnia
{
public:
    // korzystamy z konstruktora z klasy Powierzchnia
    using Powierzchnia::Powierzchnia;

    // Nadpisujemy tę funkcję, ta żeby tafla miał kształ sinusoidy
    double wyznaczZ(double x) const override;
};

#endif // TAFLAWODY_H
