#include "Wektor.hh"
#include <cmath>


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


 ///Wczytywanie wartosci pod atrybuty danego obiektu typu "Wektor"
std::ostream& operator << (std::ostream& StrWyj, Wektor Wek)
{
    for(int i; i<ROZMIAR; i++)
    {
        StrWyj << Wek.daj(i) << "  ";
    }
    return StrWyj;
}


///Wyswietlanie obiektu typu "Wektor"
std::istream& operator >> (std::istream& StrWej, Wektor& Wek)
{
    double tmp;
    for(int i=0; i<ROZMIAR; i++)
    {
        StrWej >> tmp;
        Wek.wez(tmp,i);
    }
    return StrWej;
}


///Dodawanie wektorow
const Wektor operator + (Wektor Wek1, Wektor Wek2)
{
    Wektor lacznik;
    double wynik;
    for (int i=0; i<ROZMIAR; i++) //Petla dodajaca dodajaca elementy wektorow
    {
        wynik = Wek1.daj(i) + Wek2.daj(i); //Metody zwracajace atrybuty klasy 'Wektor'
        lacznik.wez(wynik,i); // Wprowadzanie wyniku do obiektu
    }
    return lacznik;
}


///Odejmowanie wektorow
const Wektor operator - (Wektor Wek1, Wektor Wek2)
{
    Wektor lacznik;
    double wynik;
    for (int i=0; i<ROZMIAR; i++) //Petla dodajaca dodajaca elementy wektorow
    {
        wynik = Wek1.daj(i) - Wek2.daj(i); //Metody zwracajace atrybuty klasy 'Wektor'
        lacznik.wez(wynik,i); // Wprowadzanie wyniku do obiektu
    }
    return lacznik;
}

///Mnozenie skalarne
double operator * (Wektor Wek1, Wektor Wek2)
{
    double wynik, iloczyn;


    for (int i=0; i<ROZMIAR; i++)
    {
        iloczyn = Wek1.daj(i) * Wek2.daj(i);
        wynik = wynik + iloczyn;
    }
    return wynik;
}

///Mnozenie wektora przez liczbe
const Wektor operator * (Wektor Wek1, double iloczyn)
{
    Wektor lacznik;
    double wynik;
    for (int i=0; i<ROZMIAR; ++i) //Petla mnozaca kazdy skladnik wektora przez wprowadzona liczbe
    {
        wynik = Wek1.daj(i) * iloczyn;
        lacznik.wez(wynik, i); // Wprowadzanie wyniku mnozenia do klasy

    }
    return lacznik;

}

///Dzielenie wektora przez liczbe
const Wektor operator / (Wektor Wek1, double dzielnik)
{
    Wektor lacznik;
    double wynik;
    for (int i=0; i<ROZMIAR; ++i)
    {
        wynik = Wek1.daj(i) / dzielnik;
        lacznik.wez(wynik, i);

    }
    return lacznik;
}


///Rownosc dwoch wektorow
bool operator == (Wektor Wek1, Wektor Wek2)
{
    int licznik;
    for (int i=0; i<ROZMIAR; i++)
    {
        if (Wek1.daj(i) == Wek2.daj(i))
        licznik++;
    }
    if (licznik==ROZMIAR)
        return true;
    else
        return false;
}

///Nierownosc dwoch wektorow
bool operator != (Wektor Wek1, Wektor Wek2)
{
    int licznik;
    for (int i=0; i<ROZMIAR; i++)
    {
        if (Wek1.daj(i) != Wek2.daj(i))
        licznik++;
    }
    if (licznik==ROZMIAR)
        return true;
    else
        return false;
}

///Dlugosc wektora
double dlugosc (Wektor Wek1)
{
    double Wynik=0;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik = Wynik + Wek1.daj(i) * Wek1.daj(i);
    }
    Wynik=sqrt(Wynik);
    return Wynik;
}















