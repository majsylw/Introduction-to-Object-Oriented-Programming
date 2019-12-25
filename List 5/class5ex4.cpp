/*
Napisz funkcję, która zadaną liczbę całkowitą (być może ujemną) zamieni na jej zapis 
w systemie pozycyjnym o zadanej podstawie większej niż 2 i nie większej niż 36 
(użyj w zapisie do 10 cyfr i 26 liter). Nie używaj bibliotecznych usług, 
które to zadanie rozwiązują, sam/sama przeprowadź rachunki. Napisz funkcję testującą. 
Pamiętaj o sprawdzaniu warunków wstępnych na argumenty funkcji. 
Przykład: dla 254 w układzie szesnastkowym oczekujemy wyjścia FE lub fe 
(możesz zdecydować czy używasz wielkich czy małych liter).
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

int logarytm(int liczba, int podstawa)
{
    int i=0;
    while (liczba>podstawa-1)
    {
      liczba=liczba/podstawa;
      i++;
    } ;
    return i;
}

int pozycyjny(int liczba,int podstawa,int wykladnik)
{
    int reszta=0,i=-1;
    do
    {
        reszta=liczba%podstawa;
        liczba=liczba/podstawa;
        i++;
    } while(i!=wykladnik);
    return reszta;
}


std::string zapis(int liczba,int podstawa)
{
    assert(podstawa > 2);
    assert(podstawa <= 36);

    std::ostringstream strumien;
    int pomocnicza = 0;
    if(liczba < 0)
    {
        strumien << "-";
        liczba = -1*liczba;
    }
    int wykladnik = logarytm(liczba,podstawa);
    while(wykladnik!=-1)
    {
        pomocnicza = pozycyjny(liczba,podstawa,wykladnik);
        if(pomocnicza < 10)
            strumien << pomocnicza;
        else
        {
            if(pomocnicza == 10)
                strumien << "A";
            if(pomocnicza == 11)
                strumien << "B";
            if(pomocnicza == 12)
                strumien << "C";
            if(pomocnicza == 13)
                strumien << "D";
            if(pomocnicza == 14)
                strumien << "E";
            if(pomocnicza == 15)
                strumien << "F";
            if(pomocnicza == 16)
                strumien << "G";
            if(pomocnicza == 17)
                strumien << "H";
            if(pomocnicza == 18)
                strumien << "I";
            if(pomocnicza == 19)
                strumien << "J";
            if(pomocnicza == 20)
                strumien << "K";
            if(pomocnicza == 21)
                strumien << "L";
            if(pomocnicza == 22)
                strumien << "M";
            if(pomocnicza == 23)
                strumien << "N";
            if(pomocnicza == 24)
                strumien << "O";
            if(pomocnicza == 25)
                strumien << "P";
            if(pomocnicza == 26)
                strumien << "R";
        }

        wykladnik = wykladnik-1;

    }
    return strumien.str();
}

void testy(void)
{
    assert(zapis(254,16) == "FE");
    assert(zapis(-254,16) == "-FE");

    std::cout << "Program przeszedl pomyslnie testy." << std::endl;
}

int main(void)
{
    testy();

    std::cout << "Podaj liczbe w systemie dziesietnym: ";
    int liczba = 0;
    std::cin >> liczba;
    std::cout << std::endl << "Podaj podstawe systemu pozycyjnego: ";
    int podstawa;
    std::cin >> podstawa;

    std::cout << liczba << " = ";
    std::cout << zapis(liczba,podstawa);

    return 0;
}
