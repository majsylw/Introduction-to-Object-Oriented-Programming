/*
Napisz funkcję, która dla podanej płci, kwoty zadłużenia, imienia, nazwiska, 
adresu i daty sporządzenia wygeneruje tekst spersonalizowanego listu do dłużnika 
ze zobowiązaniem do natychmiastowej zapłaty. Wyraź kwotę zadłużenia słownie jako 
np. "pięć złotych i czterdzieści siedem groszy" (pamiętaj, że 1 złoty, 2 złote a 5 złotych, z groszami podobnie). 
Spróbuj maksymalnie wykorzystać funkcje z poprzednich dwóch zadań, 
możesz je nawet na tym etapie przerobić tak, aby były tak uniwersalne, 
że będzie można z nich skorzystać w obu kontekstach. Pamiętaj o sprawdzaniu warunków wstępnych na argumenty funkcji. 
Przetestuj i zademonstruj działanie tej funkcji.
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
    if( liczba == 2 )
        return "dwiescie";
    if( liczba == 3 || liczba == 4 )
        return "sta";
    if( liczba >= 5 )
        return "set";

}

std::string zloty(int liczba)
{
    assert(liczba >= 0);
    assert(liczba <= 999999);

    if( liczba == 1 )
        return " zloty";
    if( liczba > 1 && liczba < 5 )
        return " zlote";
    if( liczba >= 5 || liczba == 0 )
        return " zlotych";
}

std::string grosze(int liczba)
{
    assert(liczba >= 0);
    assert(liczba <= 999999);

    if( liczba == 1 )
        return " grosz";
    if( liczba > 1 && liczba < 5 )
        return " grosze";
    if( liczba >= 5 || liczba == 0 )
        return " groszy";
}

std::string tysiace(int liczba)
{
    assert(liczba >= 0);
    assert(liczba <= 999);

    if( liczba == 1 )
        return " tysiac ";
    if( liczba > 1 && liczba < 5 )
        return " tysiace ";
    if( liczba >= 5)
        return " tysiecy ";
}

std::string trzy_cyfry(int liczba)
{
    assert(liczba >= 0);
    assert(liczba <= 999);

    std::ostringstream tekst;
    int pomocnicza;

    pomocnicza = liczba / 100;
    if( pomocnicza != 0 )
    {
        if( pomocnicza != 1 && pomocnicza !=2 )
            tekst << jednosci( pomocnicza );
        tekst << setki( pomocnicza ) << " ";
    }

    liczba = liczba - pomocnicza*100;

    pomocnicza = liczba / 10;

    if( pomocnicza > 1 )
    {
        if( pomocnicza != 4 )
            tekst << jednosci( pomocnicza );
        tekst << dziesiatki( pomocnicza ) << " ";
    }

    int reszta = liczba - pomocnicza*10;


    if(pomocnicza == 1)
    {

        if( reszta != 0 && reszta != 4 && reszta != 5 && reszta != 6 )
        {
            tekst << jednosci( reszta );
        }
        tekst << nastki( reszta );
    }
    else
    {
        if( reszta != 0 )
            tekst << jednosci( reszta );
    }

    return tekst.str();
}


std::string zmiana(int liczba)
{
    assert(liczba >= 0);
    assert(liczba <= 999999);

    if( liczba == 0 )
        return "zero";

    std::ostringstream tekst;

    if( liczba >= 1000 )
    {
        tekst << trzy_cyfry( (liczba - liczba%1000 )/1000 );
        tekst << tysiace( (liczba - liczba%1000 )/1000 );
    }

    tekst << trzy_cyfry( liczba - 1000 * (liczba - liczba%1000 )/1000 );

    return tekst.str();
}

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
    if(miesiac = 9)
        return "wrzesnia";
    if(miesiac == 10)
        return "pazdziernika";
    if(miesiac == 11)
        return "listopada";
    if(miesiac == 12)
        return "grudnia";
}

std::string data(int dzien, int miesiac, int rok)
{
    assert(miesiac >= 1);
    assert(miesiac <= 12);
    assert(dzien >= 1);
    assert(dzien <= 31);
    assert(rok > 0);

    std::ostringstream strumien;

    strumien << dzien << " " << jaki_miesiac(miesiac) << " " << rok << "r.";

    return strumien.str();
}

std::string jaka_plec(std::string p)
{
    assert(p == "kobieta" || p == "mezczyzna");

    if(p == "kobieta")
        return "Pania";
    if(p == "mezczyzna")
        return "Pana";
}

std::string list(std::string imie, std::string nazwisko, std::string plec, std::string kod, std::string miejscowosc, std::string ulica, int nr_bloku, int nr_mieszkania, int dzien_umowy, int miesiac_umowy, int rok_umowy, double kwota)
{
    assert(kwota >= 0.01);
    assert(kwota <= 999999);
    assert(miesiac_umowy >= 1);
    assert(miesiac_umowy <= 12);
    assert(dzien_umowy >= 1);
    assert(dzien_umowy <= 31);
    assert(rok_umowy > 0);
    assert(plec == "kobieta" || plec == "mezczyzna");

    std::ostringstream strumien;

    int dzien = 0, miesiac = 0, rok = 0;
    std::cout << "Podaj obecna date (dzien, miesiac, rok odzielone spacja): ";
    std::cin >> dzien >> miesiac >> rok;

    assert(miesiac >= 1);
    assert(miesiac <= 12);
    assert(dzien >= 1);
    assert(dzien <= 31);
    assert(rok > 0);

    int kwota_calkowita = kwota;
    int reszta = (kwota - kwota_calkowita) * 100;

    strumien << "                                                  Wroclaw, dnia " << data(dzien, miesiac, rok) << std::endl;
    strumien << std::endl;
    strumien << "Janusz Kowalski" << std::endl;
    strumien << "Ul. Chrobrego 59/12" << std::endl;
    strumien << "65-865 Brzeczyszkowice" << std::endl<<std::endl;
    strumien << "                                                       " << imie << " " << nazwisko << std::endl;
    strumien << "                                                       " << "Ul. " << ulica << " " << nr_bloku << "/" << nr_mieszkania << std::endl;
    strumien << "                                                       " << kod << " " << miejscowosc << std::endl << std::endl << std::endl;

    strumien << "\t WEZWANIE DO ZAPLATY" << std::endl << std::endl;

    strumien << "Na podstawie art. 476 kodeksu cywilnego (Dz. U. z 1964r. Nr 16, poz. 93 ze zm.) ";
    strumien << "wzywam " << jaka_plec(plec) <<" do natychmiastowej zaplaty naleznej mi z tytulu umowy o pozyczke ";
    strumien << "zawartej dnia " << data(dzien_umowy, miesiac_umowy, rok_umowy) << " kwoty w wysokosci " << kwota << "zl ";
    strumien << "(slownie " << zmiana(kwota_calkowita) << zloty(kwota_calkowita) << " " << zmiana(reszta) << grosze(reszta) <<") ";
    strumien << "wraz z ustawowymi lub umownymi odsetkami za zwloke. Wymieniona sume nalezy ";
    strumien << "przekazac w ciagu 14 dni od daty otrzymania niniejszego wezwania na rachunek bankowy nr 12 5634 5698 9012 0000 0012 1365.";

    strumien << std::endl << std::endl;
    strumien << "Janusz Kowalski" << std::endl;
    strumien << "Ul. Chrobrego 59/12" << std::endl;
    strumien << "65-865 Brzeczyszkowice" << std::endl<<std::endl;

    return strumien.str();
}


int main()
{
    int nr_bloku = 0, nr_mieszkania = 0;
    std::string imie, nazwisko, plec, kod, miejscowosc, ulica;
    std::cout << std::endl << "Wprowadz dane dluznika (imie, nazwisko, plec): ";
    std::cin >> imie >> nazwisko >> plec;
    std::cout << std::endl << "Wprowadz adres dluznika (nazwa ulicy, nr bloku, nr mieszkania): ";
    std::cin >> ulica >> nr_bloku >> nr_mieszkania;
    std::cout << std::endl << "Wprowadz kod pocztowy (5 cyfr z myslnikiem) i miejscowosc miejsca zamiszkania dluznika: ";
    std::cin >> kod >> miejscowosc;

    int dzien_umowy = 0, miesiac_umowy = 0, rok_umowy = 0;
    std::cout << std::endl << "Podaj date zawarcia umowy (dzien, miesiac, rok): ";
    std::cin >> dzien_umowy >> miesiac_umowy >> rok_umowy;

    double kwota = 0.0;
    std::cout << std::endl << "Podaj kwote zadluzenia: ";
    std::cin >> kwota;

    std::cout << std::endl << std::endl << list(imie, nazwisko, plec, kod, miejscowosc, ulica, nr_bloku, nr_mieszkania, dzien_umowy, miesiac_umowy, rok_umowy, kwota);

    return 0;
}
