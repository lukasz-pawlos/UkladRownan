#include "Macierz.hh"


std::ostream& operator << (std::ostream &StrWyj, Macierz &Mac)
{
    StrWyj << std::endl;
    for(int i = 0; i<ROZMIAR; i++)
    {
        StrWyj << Mac.dajW(i) << std::endl;
    }
    return StrWyj;
}

std::istream& operator >> (std::istream &StrWej, Macierz &Mac)
{
    Wektor tmp;
    for(int i = 0; i<ROZMIAR; ++i)
    {
        StrWej >> tmp;
        Mac.wezW(tmp,i);
    }
    return StrWej;
}


///Dodawanie macierzy
const Macierz operator + (Macierz Mac1, Macierz Mac2)
{
    Macierz lacznik;
    Wektor wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik = Mac1.dajW(i) + Mac2.dajW(i);
        lacznik.wezW(wynik,i);
    }
    return lacznik;
}

///Odejmowanie macierzy
const Macierz operator - (Macierz Mac1, Macierz Mac2)
{
    Macierz lacznik;
    Wektor wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik = Mac1.dajW(i) - Mac2.dajW(i);
        lacznik.wezW(wynik,i);
    }
    return lacznik;
}

///Transpozycja uzyta do mnozenia
Macierz Transpozycja (Macierz Mac)
{
    Macierz MacT;
    Wektor A,tab[ROZMIAR];

    for (int i=0; i<ROZMIAR; i++)
    {
        A = Mac.dajW(i);
        for(int j=0; j<ROZMIAR; j++)
        {
            tab[j]=A;
        }
    }
    for (int i=0; i<ROZMIAR; i++)
    {
        MacT.wezW(tab[i],i);
    }
    return MacT;
}

///Mnozenie dwoch macierzy
const Macierz operator * (Macierz Mac1, Macierz Mac2)
{
    Macierz lacznik;
    Wektor wynik,A;
    Transpozycja(Mac2);
    for (int i=0; i<ROZMIAR; i++)
    {
        A=Mac1.dajW(i);
        for (int j=0; j<ROZMIAR; j++)
        {
            wynik.daj(i) = Mac2.dajW(i)*A;
        }
        lacznik.wezW(wynik,i);

    }
    return lacznik;
}

///Mnozenie macierzy przez luczbe
Macierz operator * (Macierz Mac1, double iloczyn)
{
    Macierz lacznik;
    Wektor wynik;

    for (int i=0; i<ROZMIAR; i++)
    {
        wynik = Mac1.dajW(i)*iloczyn;
        lacznik.wezW(wynik,i);
    }
    return lacznik;
}

///Dzielenie macierzy przez liczbe
Macierz operator / (Macierz Mac1, double dzielnik)
{
    Macierz lacznik;
    Wektor wynik;

    for (int i=0; i<ROZMIAR; i++)
    {
        wynik = Mac1.dajW(i)/dzielnik;
        lacznik.wezW(wynik,i);
    }
    return lacznik;
}

///Wyznacznik liczony metoda LaPlaca
const double Wyznacznik (Macierz Mac)
{
    Wektor Wek[ROZMIAR];
    double A,B,C, wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wek[i] = Mac.dajW(i);
    }
    A = Wek[0].daj(0)*(Wek[1].daj(1)*Wek[2].daj(2) - Wek[1].daj(2)*Wek[2].daj(1));
    B = (-1)*Wek[0].daj(1)*(Wek[1].daj(0)*Wek[2].daj(2) - Wek[1].daj(2)*Wek[2].daj(0));
    C = Wek[0].daj(2)*(Wek[1].daj(0)*Wek[2].daj(1) - Wek[1].daj(1)*Wek[2].daj(0));
    wynik = A+B+C;
    return wynik;
}

///Rownosc macierzy
bool operator == (Macierz Mac1, Macierz Mac2)
{
    int licznik=0;
    for (int i=0; i<ROZMIAR; i++)
    {
    if(Mac1.dajW(i) == Mac2.dajW(i))
        licznik++;
    }
    if(licznik==ROZMIAR)
        return true;
    else
        return false;
}

///Nierownosc macierzy
bool operator != (Macierz Mac1, Macierz Mac2)
{
    int licznik=0;
    for (int i=0; i<ROZMIAR; i++)
    {
    if(Mac1.dajW(i) != Mac2.dajW(i))
        licznik++;
    }
    if(licznik==ROZMIAR)
        return true;
    else
        return false;
}


