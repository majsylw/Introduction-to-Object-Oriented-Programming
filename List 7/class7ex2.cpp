/*Zdefiniuj strukture Zespolona modelujaca liczbe zespolona. Wyposaz ja w konstruktor przyjmujacy dwie liczby zmiennoprzecinkowe
 odpowiadajace czesci rzeczywistej i czesci urojonej, w operator wyjscia, ktory liczbe wypisze w postaci 3.14-2.71i,
 oraz w operator wejscia, ktory bedzie akceptowal napisy tej samej postaci (pamietaj o literze 'i' za czescia urojona).
*/

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstring>
#include <sstream>


struct Zespolona
{
    double rzeczywista;
    double urojona;

    Zespolona(double re, double im)
    {
        rzeczywista = re;
        urojona = im;
    }
};

std::istream& operator>>(std::istream& wejscie, Zespolona& z)
{
    std::string liczba_zespolona;

    std::cout << "Podaj liczbe zespolona: \n";
    wejscie >> liczba_zespolona;
    std::cout << std::endl;

    unsigned int poz_i = liczba_zespolona.find_first_of('i');

    while(poz_i != std::string::npos)
    {
        std::string poczatek = liczba_zespolona.substr(0, poz_i);

        unsigned int poz_p = poczatek.find_last_of('+');
        unsigned int poz_m = poczatek.find_last_of('-');

        if(poz_p >= poczatek.size() - 1)
            poz_p = 0;
        if(poz_m >= poczatek.size() - 1)
            poz_m = 0;

        if(poz_m > poz_p)
        {
            poczatek = poczatek.substr(poz_m);
            liczba_zespolona.erase(poz_m,poz_i-poz_m+1);
        }
        else if(poz_p > poz_m)
        {
            poczatek = poczatek.substr(poz_p);
            liczba_zespolona.erase(poz_p,poz_i-poz_p+1);
        }
        else // else { nie znalezlismy znaku + i -, wiec poczatek == liczba }
        {
            liczba_zespolona.erase(0,poz_i+1);
        }

        std::istringstream przypis(poczatek);
        double urojona = 0.0;
        przypis >> urojona;
        if(przypis)
        {
            z.urojona +=urojona;
        }
        poz_i = liczba_zespolona.find_first_of('i');
    }

    while(liczba_zespolona.size() > 0)
    {
        std::string L_RE;
        int poz_m = liczba_zespolona.find_last_of('-');
        int poz_p = liczba_zespolona.find_last_of('+');

        if(poz_m > poz_p)
        {
            L_RE = liczba_zespolona.substr(poz_m);
            liczba_zespolona.erase(poz_m);
        }
        else if(poz_p > poz_m)
        {
            L_RE = liczba_zespolona.substr(poz_p);
            liczba_zespolona.erase(poz_p);
        }
        else
        {
            L_RE = liczba_zespolona;
            liczba_zespolona.erase(0);
        }

        std::istringstream przypis(L_RE);
        double rzeczywista = 0.0;
        przypis >> rzeczywista;
        if(przypis)
        {
            z.rzeczywista += rzeczywista;
        }
    }

    return wejscie;
}

std::ostream& operator<<(std::ostream& wyjscie, Zespolona z)
{
    wyjscie << z.rzeczywista;
    if(z.urojona >= 0)
        wyjscie << " + " << z.urojona << "i";
    else
        wyjscie << " - " << std::abs(z.urojona) << "i";

    return wyjscie;
}


int main(void)
{
    Zespolona z(0,0);
    std::cin >> z;
    std::cout << z << std::endl;

    return 0;
}
