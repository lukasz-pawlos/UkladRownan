#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"



using namespace std;



int main()
{
  UkladRownanLiniowych B;
  Wektor C, D;
  double x;

  cin >> B;

  C = B.obliczuklad(); //Obliczenie wektora wynikow
  B.wywtrans(); //Ztransponowanie macierzy

  cout << B;

  D = B.wekbl(C); //Obliczenie wektora bledu
  x = D.dlugosc(); //Obliczenie dlugosci wektora bledu
  wyswrozw(C, D, x); // Wyswietlenie rozwiazan
}
