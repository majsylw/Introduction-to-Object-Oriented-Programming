/*Napisz funkcje, ktora zwroci napis zmodyfikowany w taki sposob, ze kazda kropka stojaca pomiedzy dwiema cyframi
zostanie zamieniona na przecinek (pozostale kropki pozostaja bez zmian), np. dla napisu "Liczba pi ma wartosc 3.14."
zwroci"Liczba pi ma wartosc 3,14.", a dla napisu "Liczba pi ma wartosc 3.14. Liczba Eulera e ma natomiast wartosc 2.71,
obie w przyblizeniu..." zwroci "Liczba pi ma wartosc 3,14. Liczba Eulera e ma natomiast wartosc 2,71, obie w przyblizeniu...".
Przetestuj dzialanie tej funkcji.*/

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

std::string zamiana_przecinkiem(std::string napis)
{
    unsigned int kropka = napis.find('.');
    if( kropka == std::string::npos )
    {
        return napis;
    }

    do
    {
        if(napis[kropka - 1] >= '0' && napis[kropka - 1] <= '9')
        {
            if(kropka + 1 >= napis.size())
            {
                return napis;
            }
            if(napis[kropka + 1] >= '0' && napis[kropka + 1] <= '9')
            {
                napis[kropka] = ',';
            }
        }
        kropka = napis.find( '.', kropka + 1 );

    } while( kropka != std::string::npos );

    return napis;
}

void testy(void)
{
    assert(zamiana_przecinkiem("") == "");

    assert(zamiana_przecinkiem("Brak jakiejkolwiek kropki") == "Brak jakiejkolwiek kropki");

    assert(zamiana_przecinkiem("Brak jakiejkolwiek kropki do zamiany.") == "Brak jakiejkolwiek kropki do zamiany.");

    assert(zamiana_przecinkiem("Liczba pi ma wartosc 3.14.") == "Liczba pi ma wartosc 3,14.");

    assert(zamiana_przecinkiem("Liczba pi ma wartosc 3.14. Liczba Eulera e ma natomiast wartosc 2.71, obie w przyblizeniu...") == "Liczba pi ma wartosc 3,14. Liczba Eulera e ma natomiast wartosc 2,71, obie w przyblizeniu...");

    std::cout << "Funkcja pomyslnie przeszla testy." << std::endl;
}

int main(void)
{
    testy();

    std::cout << zamiana_przecinkiem("Liczba pi ma wartosc 3.14. Liczba Eulera e ma natomiast wartosc 2.71, obie w przyblizeniu...") << std::endl;

    return 0;
}
