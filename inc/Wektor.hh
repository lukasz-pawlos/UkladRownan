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
    Wektor(double=0 ,double=0 ,double=0 );


    double  operator [] (unsigned int Ind) const { return tab[Ind]; } //Przeciazenie operatora indeksowania do latwiejszego wczytywania
    double &operator [] (unsigned int Ind)       { return tab[Ind]; } //oraz wydawania wartosci z wektora


    Wektor  operator + (const Wektor  Wek2);
    Wektor  operator - (const Wektor  Wek2);
    double operator * (Wektor Wek2);
    Wektor operator * (double iloczyn);
    Wektor operator / (double dzielnik);
    bool operator == (Wektor Wek2);
    bool operator != (Wektor Wek2);
    double dlugosc ();

};


std::istream& operator >> (std::istream &StrmWyj, Wektor &Wek);

std::ostream& operator << (std::ostream &StrmWej, const Wektor &Wek);





#endif
