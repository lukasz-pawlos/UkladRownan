#include "Wektor.hh"
#include <cmath>


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */



///Wyswietlanie obiektu typu "Wektor"
std::ostream& operator << (std::ostream& StrWyj, const Wektor& Wek)
{
    for(int i=0; i<ROZMIAR; i++)
    {
        StrWyj << Wek.daj(i) << "  ";
    }
    return StrWyj;
}



///Wczytywanie wartosci pod atrybuty danego obiektu typu "Wektor"
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

Wektor::Wektor (double , double , double )
{

}


///Dodawanie wektorow
Wektor Wektor::operator + (const Wektor Wek2)
{
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++) //Petla dodajaca dodajaca elementy wektorow
    {
        Wynik.tab[i] = this->tab[i] + Wek2.tab[i]; //Metody zwracajace atrybuty klasy 'Wektor'
    }
    return Wek2;
}


///Odejmowanie wektorow
Wektor Wektor::operator - (const Wektor Wek2)
{
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++) //Petla dodajaca dodajaca elementy wektorow
    {
        Wynik.tab[i] = this->tab[i] - Wek2.tab[i]; //Metody zwracajace atrybuty klasy 'Wektor'
    }
    return Wek2;
}

///Mnozenie skalarne
double Wektor::operator * (const Wektor Wek2)
{
    double wynik, iloczyn;


    for (int i=0; i<ROZMIAR; i++)
    {
        iloczyn = this->tab[i] * Wek2.tab[i];
        wynik = wynik + iloczyn;
    }
    return wynik;
}

///Mnozenie wektora przez liczbe
Wektor Wektor::operator * (const double iloczyn)
{
    for (int i=0; i<ROZMIAR; ++i) //Petla mnozaca kazdy skladnik wektora przez wprowadzona liczbe
    {
        this->tab[i] = this->tab[i]*iloczyn;
    }
    return *this;

}

///Dzielenie wektora przez liczbe
Wektor Wektor::operator / (const double dzielnik)
{
    if(dzielnik!=0)
   {

    for (int i=0; i<ROZMIAR; ++i)
    {
       this->tab[i] = this->tab[i] / dzielnik;
    }
    return *this;
    }
    else
        std::cerr << "Nie dzielimy przez zero";
}


///Rownosc dwoch wektorow
bool Wektor::operator == (const Wektor Wek2)
{
    int licznik;
    for (int i=0; i<ROZMIAR; i++)
    {
        if (this->tab[i] - Wek2.tab[i] >=0 )
        licznik++;
    }
    if (licznik==ROZMIAR)
        return true;
    else
        return false;
}

///Nierownosc dwoch wektorow
bool Wektor::operator != (const Wektor Wek2)
{
    int licznik;
    for (int i=0; i<ROZMIAR; i++)
    {
        if (this->tab[i] - Wek2.tab[i] >=0)
        licznik++;
    }
    if (licznik==ROZMIAR)
        return false;
    else
        return true;
}

///Dlugosc wektora
double Wektor::dlugosc ()
{
    double Wynik=0;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik = Wynik + this->tab[i] * this->tab[i];
    }
    Wynik=sqrt(Wynik);
    return Wynik;
}













