#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

///Wektor zapisywany jest w tablicy poziomej

class Wektor {

    double tab[ROZMIAR];

  public:

    double daj(int b) const
    {
        return tab[b];
    }
    void wez(double z, int p)
    {
        tab[p]=z;
    }
    double dlugosc(const Wektor Wek1)const;
    Wektor();
    ~Wektor();
};


std::istream& operator >> (std::istream &StrmWyj, Wektor &Wek);

std::ostream& operator << (std::ostream &StrmWej, const Wektor &Wek);

const Wektor operator + (const Wektor Wek1, const Wektor Wek2);
const Wektor operator - (const Wektor Wek1, const Wektor Wek2);
double operator * (const  Wektor Wek1, const Wektor Wek2);
const Wektor operator * (const Wektor Wek1, const double Wek2);
const Wektor operator / (const Wektor Wek1, const double Wek2);
bool operator == (const Wektor Wek1, const Wektor Wek2);
bool operator != (const Wektor Wek1, const Wektor Wek2);



#endif
