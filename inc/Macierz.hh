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

    Wektor dajW(int i) const  //Metoda wydaje wektor z danej komorki
    {
        return tab[i];
    }

    void wezW(Wektor Wek, int i)//Wczytywanie wektora do danej komorki
    {
        tab[i] = Wek;
    }

    Wektor  operator [] (unsigned int Ind) const { return tab[Ind]; } //Przeciazenie operatora indeksowania do latwiejszego wczytywania
    Wektor &operator [] (unsigned int Ind)       { return tab[Ind]; } //oraz wydawania wartosci z wektora

    double  operator () (unsigned int Ind, unsigned int j) const { return tab[Ind][j]; } //Przeciazenie operatora indeksowania do latwiejszego
    double &operator () (unsigned int Ind, unsigned int j)       { return tab[Ind][j]; } //wczytywania oraz wydawania wektorow



    Macierz(Wektor=0 ,Wektor=0 ,Wektor=0);
    void Transpozycja();
    double det();

    Macierz operator + (Macierz Mac2);
    Macierz operator - (Macierz Mac2);
    Macierz operator * (Macierz Mac2);
    Macierz operator * (double iloczyn);
    Wektor operator * (Wektor Wek);
    Macierz operator / (double dzielnik);
    bool operator == (Macierz Mac2);
    bool operator != (Macierz Mac2);


};


std::istream& operator >> (std::istream &StrmWyj, Macierz &Mac);


std::ostream& operator << (std::ostream &StrmWej,const Macierz &Mac);



#endif
