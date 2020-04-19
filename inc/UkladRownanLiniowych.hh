#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {

    Macierz mac;
    Wektor wek;

  public:

      void wezmU(Wektor C, int i) //Wczytuje wektor do macierzy wspolczynnikow
    {
        mac.wezW(C, i);
    }

    void wezwU(double z, int p) //Wczytuje liczbe do wektora wyrazow wolnych
    {
         wek[p] = z;
    }

    double dajwU(int b) const //Wydaje konkretne wartosci wektora wyrazow wolnych
    {
       return  wek[b];
    }

    Wektor dajj(int i) const //Wydaje wektor z macierzy wspolczynnikow
    {
        return mac.dajW(i);
    }

    void wywtrans() //Wywoluje transponowanie macierzy wspolczynnikow
    {
        mac.Transpozycja();
    }

    Wektor obliczuklad(); //Metoda obliczajaca uklad rownan

    Wektor wekbl(Wektor zz); //Metoda obliczajaca wektor bledu

};



std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown);
void wyswrozw(Wektor C, Wektor B, double x);

#endif
