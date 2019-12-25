/*Pewna firma prowadzi rekrutacjê na staz na podstawie sredniej z ocen studenta oraz oceny dzialalnoœci pozauczelnianej,
rowniez opisane liczba rzeczywista. Napisz strukture, ktora bedzie przechowywac dane pojedynczego kandydata,
to znaczy powyzsze dwie liczby oraz imie i nazwisko. Wyposaz ja w stosowny konstruktor oraz operator wyjscia.
Napisz funkcje, ktora dla zadanego kandydata, progu na sredni¹ i progu na aktywnosc obliczy, czy kandydat powinien byc przyjety*/

#include <iostream>
#include <cassert>
#include <string>

struct dane_kandydata
{
    double srednia;
    double dzialalnosc_pozauczelniana;
    std::string imie;
    std::string nazwisko;

    dane_kandydata (std::string i, std::string n, double s, double d_p)
    {
        assert(s > 2.00);
        assert(d_p > 0);

        srednia = s;
        dzialalnosc_pozauczelniana = d_p;
        imie = i;
        nazwisko = n;
    }
};

std::ostream& operator<<(std::ostream& wyjscie, dane_kandydata dane)
{
    wyjscie << "Imie i nazwisko studenta: " << dane.imie << " " << dane.nazwisko << std::endl;
    wyjscie << "Srednia z ocen studenta: " << dane.srednia << std::endl;
    wyjscie << "Ocena dzialalnosci pozauczelnianej: " << dane.dzialalnosc_pozauczelniana << std::endl;

    return wyjscie;
}

std::string czy_przyjac(dane_kandydata osoba, double prog_srednia, double prog_dzialalnosc_pozauczelniana)
{
    if(prog_srednia <= osoba.srednia && prog_dzialalnosc_pozauczelniana <= osoba.dzialalnosc_pozauczelniana)
        return "Osoba do przyjecia.";
    else
        return "Osoba odrzucona w procesie rekrytacyjnym.";
}


int main(void)
{
    double prog_s = 4.50;
    double prog_d = 4.00;

    dane_kandydata kandydatka1("Karolina","Majkut",4.84,5.15);
    dane_kandydata kandydat1("Miroslaw","Lubaszenko",3.24,4.15);
    dane_kandydata kandydatka2("Aleksandra","Kubiak",4.84,3.00);
    dane_kandydata kandydat2("Robert","Andrzejewski",3.74,4.00);

    std::cout << kandydatka1;
    std::cout << czy_przyjac(kandydatka1,prog_s,prog_d) << "\n\n";

    std::cout << kandydatka2;
    std::cout << czy_przyjac(kandydatka2,prog_s,prog_d) << "\n\n";

    std::cout << kandydat1;
    std::cout << czy_przyjac(kandydat1,prog_s,prog_d) << "\n\n";

    std::cout << kandydat2;
    std::cout << czy_przyjac(kandydat2,prog_s,prog_d) << "\n\n";

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
