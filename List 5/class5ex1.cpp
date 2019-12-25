/*
Napisz funkcję, która zamieni liczbę całkowitą z zakresu od -999999 do 999999 na polski liczebnik. 
Napisz funkcję, która dla zadanej liczby całkowitej wygeneruje napis składający się 
z liczebnika i właściwej formy słowa "elementy", tak jak np. w "pięć elementów". 
Przemyśl podział problemu na funkcje, i napisz testy do każdej z nich. 
Pamiętaj o sprawdzaniu warunków wstępnych na argumenty funkcji.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

std::string jednosci(int liczba)
{
    assert(liczba >= 0);
    assert(liczba <= 9);

    if( liczba == 0 )
        return "zero";
    if( liczba == 1 )
        return "jeden";
    if( liczba == 2 )
        return "dwa";
    if( liczba == 3 )
        return "trzy";
    if( liczba == 4 )
        return "cztery";
    if( liczba == 5 )
        return "piec";
    if( liczba == 6 )
        return "szesc";
    if( liczba == 7 )
        return "siedem";
    if( liczba == 8 )
        return "osiem";
    if( liczba == 9 )
        return "dziewiec";
}

std::string nastki(int liczba)
{
    assert(liczba >= 0);
    assert(liczba <= 9);

    if( liczba == 0 )
        return "dziesiec";
    if( liczba == 1 )
        return "ascie";
    if( liczba == 2 || liczba == 3 || liczba == 7 || liczba == 8 )
        return "nascie";
    if( liczba == 4 )
        return "czternascie";
    if( liczba == 5 )
        return "pietnascie";
    if( liczba == 6 )
        return "szesnascie";
    if( liczba == 9 )
        return "dziewietnascie";
}

std::string dziesiatki(int liczba)
{
    assert(liczba >= 2);
    assert(liczba <= 9);

    if( liczba == 2 )
        return "dziescia";
    if( liczba == 3 )
        return "dziesci";
    if( liczba == 4 )
        return "czterdziesci";
    if( liczba >= 5 )
        return "dziesiat";
}

std::string setki(int liczba)
{
    assert(liczba >= 1);
    assert(liczba <= 9);

    if( liczba == 1 )
        return "sto";
    if( liczba == 2)
        return "dwiescie";
    if(liczba == 3 || liczba == 4)
        return "sta";
    if(liczba >= 5)
        return "set";

}

std::string elementy(int liczba)
{
    assert(liczba >= 0);
    assert(liczba <= 999999);
    if(liczba == 1)
        return "element";
    if(liczba > 1 && liczba < 5)
        return "elementy";
    if(liczba >= 5 || liczba <= 0)
        return "elementow";
}

std::string tysiace(int liczba)
{
    assert(liczba >= 1);
    assert(liczba <= 999);
    if(liczba == 1)
        return "tysiac";
    if(liczba > 1 && liczba < 5)
        return "tysiace";
    if(liczba >= 5)
        return "tysiecy";
}

std::string trzy_cyfry(int liczba)
{
    assert(liczba >= 0);
    assert(liczba <= 999);

    std::ostringstream tekst;
    int pomocnicza = 0;

    pomocnicza = liczba / 100;
    if(pomocnicza != 0)
    {
        if(pomocnicza != 1 && pomocnicza !=2)
            tekst << jednosci(pomocnicza);
        tekst << setki(pomocnicza) << " ";
    }

    liczba = liczba - pomocnicza*100;

    pomocnicza = liczba / 10;

    if(pomocnicza > 1)
    {
        if(pomocnicza != 4)
            tekst << jednosci(pomocnicza);
        tekst << dziesiatki(pomocnicza) << " ";
    }

    int reszta = liczba - pomocnicza*10;


    if(pomocnicza == 1)
    {

        if(reszta != 0 && reszta != 4 && reszta != 5 && reszta != 6)
        {
            tekst << jednosci(reszta);
        }
        tekst << nastki(reszta);
    }
    else
    {
        if(reszta != 0)
            tekst << jednosci(reszta);
    }

    return tekst.str();
}


std::string zmiana(int liczba)
{
    assert(liczba >= -999999);
    assert(liczba <= 999999);

    if( liczba == 0 )
        return "zero elementow";

    std::ostringstream tekst;

    if(liczba < 0) {
        tekst << "minus ";
        liczba = -liczba;
    }

    if(liczba >= 1000)
    {
        if((liczba - liczba%1000)/1000 != 1)
        {
            tekst << trzy_cyfry((liczba - liczba%1000)/1000) << " ";
        }
        tekst << tysiace((liczba - liczba%1000 )/1000) << " ";
    }

    if((liczba - 1000 * (liczba - liczba%1000 )/1000) != 0)
    {
        tekst << trzy_cyfry(liczba - 1000 * (liczba - liczba%1000 )/1000) << " ";
    }

    tekst << elementy(liczba);

    return tekst.str();
}

void testy(void)
{
    assert(jednosci(1) == "jeden");
    assert(jednosci(3) == "trzy");
    assert(jednosci(4) == "cztery");

    assert(dziesiatki(2) == "dziescia");
    assert(dziesiatki(3) == "dziesci");
    assert(dziesiatki(4) == "czterdziesci");

    assert(nastki(3) == "nascie");
    assert(nastki(5) == "pietnascie");
    assert(nastki(4) == "czternascie");

    assert(setki(1) == "sto");
    assert(setki(2) == "dwiescie");
    assert(setki(3) == "sta");
    assert(setki(5) == "set");

    assert(elementy(0) == "elementow");
    assert(elementy(3) == "elementy");
    assert(elementy(1) == "element");

    assert(tysiace(11) == "tysiecy");
    assert(tysiace(4) == "tysiace");
    assert(tysiace(1) == "tysiac");

    assert(trzy_cyfry(310) == "trzysta dziesiec");
    assert(trzy_cyfry(42) == "czterdziesci dwa");

    assert(zmiana(0) == "zero elementow");
    assert(zmiana(-1) == "minus jeden element");
    assert(zmiana(2) == "dwa elementy");
    assert(zmiana(2251) == "dwa tysiace dwiescie piecdziesiat jeden elementow");
    assert(zmiana(-1000) == "minus tysiac elementow");

    std::cout << "Aplikacja pozytywnie przeszla testy";
}

int main(void)
{

    testy();

    std::cout << std::endl << zmiana(-2001) << std::endl;

    return 0;
}
