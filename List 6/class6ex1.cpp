/*Napisz funkcjê, ktora dla napisu zawieraj¹cego imiona i/lub inicjaly oraz nazwisko zwroci napis zawieraj¹cy stosowne inicjaly i
nazwisko, np. dla "Jan J. Kowalski" zwroci "J. J. Kowalski", dla "Jan Maciej Karol Wscieklica" zwroci "J. M. K. Wscieklica",
a dla "A. Babacki" zwroci "A. Babacki". Zacznij od napisania funkcji testuj¹cej. 
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

std::string inicialy(std::string imiona_nazwisko)
{
    if(imiona_nazwisko.empty()) // Sprawdza czy cokolwiek znajduje siê w imiona_nazwisko
    {
        return imiona_nazwisko;
    }

    while(imiona_nazwisko[0] == ' ')
    {
        imiona_nazwisko = imiona_nazwisko.substr(1);
    }

    if(imiona_nazwisko.size() != 0)
    {
        while(imiona_nazwisko[imiona_nazwisko.size() - 1] == ' ')
        {
            imiona_nazwisko = imiona_nazwisko.substr(0,imiona_nazwisko.size() - 1);
        }
    }

    std::ostringstream strumien;

    unsigned int ostatnia_spacja = imiona_nazwisko.find_last_of(" ");//Znajduje ostatnia spacje w zadanym stringu (find_last_of)

    if(ostatnia_spacja < imiona_nazwisko.size()) // Co jesli brak jakiejkolwiek spacji???
    {
        std::string nazwisko =  imiona_nazwisko.substr(ostatnia_spacja + 1); // Tworzy podnapis od znalezionego indeksu + 1 do konca wyrazu

        imiona_nazwisko =  imiona_nazwisko.substr(0,ostatnia_spacja); // Tworzy podnapis od poczatku do indeksu przed znalezionym



        strumien << imiona_nazwisko[0] << ". ";

        for(unsigned int i=1; i < imiona_nazwisko.size(); ++i)
        {
            if(imiona_nazwisko[i - 1] == ' ')
            strumien << imiona_nazwisko[i] << ". ";
        }

        strumien << nazwisko;
    }
    else
        strumien << imiona_nazwisko;

    return strumien.str();
}

void testy(void)
{
    assert(inicialy("jghjgjbhjfhgf       ") == "jghjgjbhjfhgf");

    assert(inicialy("") == "");

    assert(inicialy("               ") == "");

    assert(inicialy("         A. Babacki") == "A. Babacki");

    assert(inicialy("Jan Maria Karol Wscieklica") == "J. M. K. Wscieklica");

    assert(inicialy("A. Babacki") == "A. Babacki");

    assert(inicialy("Jan J. Kowalski") == "J. J. Kowalski");


    std::cout << "Funkcja pomyslnie przeszla testy." << std::endl;
}

int main(void)
{
    testy();

    std::string dane = "Jan Maciej Wscieklica ";

    std::cout << inicialy(dane) << std::endl;


    std::cin.get();
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
