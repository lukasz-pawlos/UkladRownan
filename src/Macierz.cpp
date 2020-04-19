#include "Macierz.hh"


std::ostream& operator << (std::ostream &StrWyj,const Macierz &Mac)
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

Macierz::Macierz(Wektor, Wektor, Wektor)
{

}

///Dodawanie macierzy
Macierz Macierz::operator + (Macierz Mac2)
{

    for (int i=0; i<ROZMIAR; i++)
    {
        Mac2.tab[i] = this->tab[i] + Mac2.tab[i];
    }
    return Mac2;
}

///Odejmowanie macierzy
Macierz Macierz::operator - (Macierz Mac2)
{

    for (int i=0; i<ROZMIAR; i++)
    {
        Mac2.tab[i] = this->tab[i] - Mac2.tab[i];
    }
    return Mac2;
}

///Transpozycja uzyta do mnozenia
void Macierz::Transpozycja()
{
    Wektor C, D;
    Macierz Z;

    for(int i=0; i<ROZMIAR; ++i)
    {
        for(int y=0; y<ROZMIAR; ++y) //Glowna petla ktora, wyciaga wektor z macierzy i wrzuca jego
        {                            //wartosci do wartosci nowo stworzonego wektora
            C = tab[y];
            D[y] = C[i];
        }
        Z.wezW(D, i); //Tutaj ten nowy wektor wchodzi do nowej macierzy
    }

    for(int b = 0; b<ROZMIAR; ++b)
    {
        tab[b] = Z.dajW(b); //Wektory z nowej macierzy wracaja spowrotem do tej oryginalnej
    }
}


///Mnozenie dwoch macierzy
Macierz Macierz::operator * (Macierz Mac2)
{
    Macierz Koniec;
    Mac2.Transpozycja();
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            Koniec.tab[i]=Mac2.tab[i] * this->tab[j];
        }
    }
    return Koniec;
}

Wektor Macierz::operator * (Wektor Wek)
{
    Wektor pom;
    double wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik=this->tab[i]*Wek;
        pom.wez(wynik,i);
    }
    return pom;
}

///Mnozenie macierzy przez luczbe
Macierz Macierz::operator * (double iloczyn)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        this->tab[i] = this->tab[i] * iloczyn;
    }
    return *this;
}

///Dzielenie macierzy przez liczbe
Macierz Macierz::operator / (double dzielnik)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        this->tab[i] = this->tab[i] / dzielnik;
    }
    return *this;
}

///Obliczanie wyznacznika dowolnie wielkiej macierzy
double Macierz::det()
{
    Macierz mac = (*this);
    double elem = 0, wynik = 1;

    for (int i = 0; i<ROZMIAR-1; i++)
    {
        for (int j = i+1; j<ROZMIAR; j++)
        {
            elem = -mac.tab[j][i]/mac.tab[i][i];
            for (int k = i; k<=ROZMIAR; k++)
            {
                mac.tab[j][k]+=(elem*mac.tab[i][k]);
            }
        }
    }

    for (int l = 0; l<ROZMIAR; l++)
    {
        wynik = (mac(l, l) * wynik);

    }
    return wynik;
}


///Rownosc macierzy
bool Macierz::operator == (Macierz Mac2)
{
    int licznik=0;
    for (int i=0; i<ROZMIAR; i++)
    {
        if(this->tab[i] == Mac2[i])
            licznik++;
    }
    if(licznik==ROZMIAR)
        return true;
    else
        return false;
}

///Nierownosc macierzy
bool Macierz::operator != (Macierz Mac2)
{
    int licznik=0;
    for (int i=0; i<ROZMIAR; i++)
    {
    if(this->tab[i] != Mac2[i])
        licznik++;
    }
    if(licznik==ROZMIAR)
        return true;
    else
        return false;
}

