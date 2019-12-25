/*
Napisz funkcję, która dla zadanej daty (dnia, miesiąca i roku) wygeneruje jej słowny zapis, 
np. "piątek, 29 marca 2013". Znajdź dzień tygodnia dla danej daty przy pomocy stosownego algorytmu. 
Podziel zadanie na funkcje z pojedynczą odpowiedzialnością. 
Przetestuj każdą z funkcji (tzn. napisz funkcje testujące). 
Pamiętaj o sprawdzaniu warunków wstępnych na argumenty funkcji.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>


std::string jaki_miesiac(int miesiac)
{
    assert(miesiac >= 1);
    assert(miesiac <= 12);

    if(miesiac == 1)
        return "stycznia";
    if(miesiac == 2)
        return "lutego";
    if(miesiac == 3)
        return "marca";
    if(miesiac == 4)
        return "kwietnia";
    if(miesiac == 5)
        return "maja";
    if(miesiac == 6)
        return "czerwca";
    if(miesiac == 7)
        return "lipca";
    if(miesiac == 8)
        return "sierpnia";
    if(miesiac == 9)
        return "wrzesnia";
    if(miesiac == 10)
        return "pazdziernika";
    if(miesiac == 11)
        return "listopada";
    if(miesiac == 12)
        return "grudnia";
}

int Zeller(int dzien,int miesiac,int rok)
{
    assert(miesiac >= 1);
    assert(miesiac <= 12);
    assert(dzien >= 1);
    assert(dzien <= 31);
    assert(rok > 0);
    assert(rok <= 9999);

    int dzien_tygodnia = 0;
    if(miesiac < 3)
        dzien_tygodnia = ((23*miesiac)/9 + dzien + 4 + rok + (rok- 1)/4 - (rok - 1)/100 +(rok - 1)/400)%7;
    else
        dzien_tygodnia = ((23*miesiac)/9 + dzien + 4 + rok + rok/4 - rok/100 +rok/400 - 2)%7;
    return dzien_tygodnia;
}

std::string jaki_dzien(int dzien, int miesiac, int rok)
{
    assert(miesiac >= 1);
    assert(miesiac <= 12);
    assert(dzien >= 1);
    assert(dzien <= 31);
    assert(rok > 0);
    assert(rok <= 9999);

    int pomocnicza = Zeller(dzien, miesiac, rok);

    assert(pomocnicza >= 0);
    assert(pomocnicza <= 6);

    if(pomocnicza == 0)
        return "niedziela";
    if(pomocnicza == 1)
        return "poniedzialek";
    if(pomocnicza == 2)
        return "wtorek";
    if(pomocnicza == 3)
        return "sroda";
    if(pomocnicza == 4)
        return "czwartek";
    if(pomocnicza == 5)
        return "piatek";
    if(pomocnicza == 6)
        return "sobota";
}

std::string data(int dzien, int miesiac, int rok)
{
    assert(miesiac >= 1);
    assert(miesiac <= 12);
    assert(dzien >= 1);
    assert(dzien <= 31);
    assert(rok > 0);
    assert(rok <= 9999);

    std::ostringstream strumien;

    strumien << jaki_dzien(dzien,miesiac,rok) << ", " << dzien << " " << jaki_miesiac(miesiac) << " " << rok << "r.";

    return strumien.str();
}

void testy(void)
{
    assert(Zeller(29, 3, 2014) == 6);
    assert(jaki_dzien(29, 3, 2014) == "sobota");
    assert(jaki_miesiac(3) == "marca");
    assert(data(29, 3, 2014) == "sobota, 29 marca 2014r.");

    std::cout << "Funkcje pomyslnie przeszly testy." << std::endl;
}


int main()
{

    testy();

    int dzien = 0, miesiac = 0, rok = 0;

    std::cout << "Wprowadz dzien: ";
    std::cin >> dzien;
    std::cout << std::endl << "Wprowadz nr miesiaca: ";
    std::cin >> miesiac;
    std::cout << std::endl << "Wprowadz rok: ";
    std::cin >> rok;

    std::cout << std::endl << "Wprowadzona data to:" << std::endl;
    std::cout << data(dzien, miesiac, rok) << std::endl;

    return 0;
}
