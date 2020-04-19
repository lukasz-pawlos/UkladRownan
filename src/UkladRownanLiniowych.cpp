#include "UkladRownanLiniowych.hh"


///Wczytywanie ukladu rownan w postaci transponowanej
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Wektor wek;
    double liczba;
    for(int i=0; i<ROZMIAR; ++i) //Wczytanie macierzy wspolczynnikow
    {
        Strm >> wek;
        UklRown.wezmU(wek, i);
    }

    for(int i=0; i<ROZMIAR; ++i) //Wczytanie wektora wyrazow wolnych
    {
        Strm >> liczba;
        UklRown.wezwU(liczba, i);

    }

    return Strm;
}

///Wyswietlenie ukladu rownan
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{
    Macierz W;
    Strm << std::endl << "Uklad rownan do rozwiazania: " << std::endl << std::endl;
    for(int i=0; i<ROZMIAR; ++i) // Petla wyswietlajaca uklad rownan
    {
        Strm << "|  " << UklRown.dajj(i) <<  "| | x_" << i+1 << " |";
        if((i==ROZMIAR/2)) //Wyswietlaj znak '=' wraz z ramka macierzy przy przejsciu przez polowe dlugosci ukladu
        {
            Strm << " = | " << UklRown.dajwU(i) << " |" << std::endl;
        }
        else
        {
            Strm << "   | " << UklRown.dajwU(i) << " |" << std::endl; //W przeciwnym wypadku ramke macierzy bez '='
        }

    }
    Strm << std::endl << std::endl;
    return Strm;
}

///Metoda obliczajaca uklad rownana metoda Cramera
Wektor UkladRownanLiniowych::obliczuklad ()
{
    double x, y;
    Wektor wynik, tmpglowny;
    Macierz X;

    X = mac; //zrobienie kopii pomocniczej
    y = X.det(); //obliczenie wyznacznika glownego
    for (int i = 0; i<ROZMIAR; ++i)
    {
        tmpglowny = mac.dajW(i); //pobranie wektora z macierzy wspolczynnikow jako kopii
        mac.wezW(wek, i); //wlozenie na jego miejsce wektora wyrazow wolnych
        X = mac; //zaktualizowanie kopii
        x = X.det(); //obliczenie wyznacznika na kopii z uwagi zniszczenie struktury macierzy metoda gaussa
        wynik.wez(x/y, i); //wlozenie do wektora z wynikami obliczonej wartosci podzielonej, z uwagi na wzor cramera
        mac.wezW(tmpglowny, i); //odlozenie spowrotem na miejsce wektora wczesniej zabranego
    }

    return wynik; //Zwrocenie wektora z wynikiem
}

///Oblicza wartosc wektora bledu, przyjmuje wektor rozwiazan
Wektor UkladRownanLiniowych::wekbl(Wektor zz)
{
    zz=mac*zz;
    return zz - wek;
}

///Wyswietla wyniki na std.
void wyswrozw(Wektor C, Wektor B, double x)
{
  std::cout << "Wektor rozwiazan:" << std::endl  << std::endl << "\t     " << C << std::endl << std::endl;
  std::cout << "Wektor bledu:" << std::endl << std::endl << "\tAx-b  =  (  " << B << ")" << std::endl << std::endl;
  std::cout << "Dlugosc wektora bledu:" << std::endl << std::endl << "\t||Ax-b||  =  " << x << std::endl << std::endl;
}

