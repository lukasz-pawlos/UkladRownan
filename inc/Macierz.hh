#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>


///Macierz tworzona jest przez 3 Wektory
///3 Wektory POZIOME

class Macierz
{
    Wektor tab[ROZMIAR];


  public:

    Wektor dajW(int i)  //Metoda wydaje wektor z danej komorki
    {
        return tab[i];
    }

    void wezW(Wektor Wek, int i)//Wczytywanie wektora do danej komorki
    {
        tab[i] = Wek;
    }

    void transponuj(Macierz Mac);
    double Wyznacznik();
    Macierz();
    ~Macierz();

};


std::istream& operator >> (std::istream &StrmWyj, Macierz &Mac);


std::ostream& operator << (std::ostream &StrmWej, Macierz &Mac);

const Macierz operator + (const Macierz Mac1, const Macierz Mac2);
const Macierz operator - (const Macierz Mac1, const Macierz Mac2);
Macierz Transpozycja(const Macierz Mac);
const Macierz operator * (const Macierz Mac1, const Macierz Mac2);
Macierz operator * (const Macierz Mac1, double iloczyn);
Macierz operator / (const Macierz Mac1, double dzielnik);
const double Wyznacznik (const Macierz Mac);
bool operator == (const Macierz Mac1, const double dzielnik);
bool operator != (const Macierz Mac1, const double dzielnik);

#endif
