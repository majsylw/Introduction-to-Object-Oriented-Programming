/*Napisz funkcje, ktora w zadanym napisie znajdzie pierwszy wystepujacy w nim adres mailowy, i zwroci go w postaci napisu.
Jezeli w zadanym napisie nie bedzie zadnego adresu mailowego to funkcja zwroci napis pusty. Przetestuj dzialanie tej funkcji.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

std::string adres_email(std::string napis)
{

    napis = " " + napis + " ";

    unsigned int pozycja = napis.find_first_of('@');

    if(pozycja > napis.size())
        return "";

    std::string poczatek = napis.substr(0,pozycja);

    std::string email = poczatek.substr(poczatek.find_last_of(' ')+1);

    std::string koniec = napis.substr(pozycja);

    int i = 0;

    while(koniec[i] != ' ')
    {
        email += koniec[i];

        ++i;
    }

    return email;
}


void testy(void)
{
    assert(adres_email("rzodkiewa1993@onet.eu") == "rzodkiewa1993@onet.eu");

    assert(adres_email("Przesli mi te dokumenty na adres rzodkiewa1993@onet.eu abym mogla sprawdzic czy moga mi sie przydac.") == "rzodkiewa1993@onet.eu");

    assert(adres_email("Mozesz przeslac mi to na mojego maila bonifacy@gmail.com lub cyprus@onet.fm.") == "bonifacy@gmail.com");

    assert(adres_email("") == "");

    assert(adres_email("Ala ma kota") == "");

    std::cerr << "Funkcja pomyslnie przeszla testy. \n";
}
int main(void)
{
    testy();

    std::cout << adres_email("rzodkiewa1993@onet.eu") << std::endl;

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
