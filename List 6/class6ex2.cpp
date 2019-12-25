/*Napisz funkcje, ktora podejmie bezpieczna probe wczytania liczby calkowitej z konsoli.
W przypadku, kiedy uzytkownik wpisze cos, co nie jest liczba, funkcja poinformuje o niepowodzeniu i ponowi probe.
Kiedy wreszcie uzytkownik poda liczbe, funkcja zwroci jej wartosc.
*/

#include <iostream>
#include <string>
#include <sstream>


bool calkowita(double liczba)
{
    int czesc_calkowita = liczba;
    if((liczba - czesc_calkowita) == 0)
    {
        return true;
    }
    else
        return false;
}

int czy_liczba(void)
{
    std::cout << "Podaj liczbe calkowita: ";

    std::string sprawdzenie;

    std::getline(std::cin,sprawdzenie);

    double liczba = 0.0;

    std::istringstream wejscie(sprawdzenie);

    wejscie >> liczba;

    while ( !wejscie || !calkowita(liczba)) // tak d³ugo, jak wejscie jest rowne false nastepuje b³êdne przypisanie
    {
        std::cout << "\nPodana wartosc nie jest liczba calkowita. \n" << "Podaj liczbe calkowita jeszcze raz: ";

        std::getline(std::cin,sprawdzenie);

        wejscie.clear(); //czyszcze strumien zeby nie nadpisywac

        wejscie.str(sprawdzenie); //wprowadzam nowa wartosc wejscia

        wejscie >> liczba;
    }

    std::cout << "\nWprowadzona przez Ciebie liczba calkowita to: ";

    return liczba;
}

int main(void)
{
    std::cout << czy_liczba();

    return 0;
}
