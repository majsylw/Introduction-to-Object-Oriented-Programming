/*
Zdefiniuj klas� Zespolona modeluj�c� liczb� zespolon�. 
Wyposa� j� w konstruktor domy�lny ustawiaj�cy warto�� liczby na zero 
oraz konstruktory przyjmuj�ce jedn� lub dwie liczby zmiennoprzecinkowe 
odpowiadaj�ce cz�ci rzeczywistej i cz�ci urojonej (w razie podania tylko cz�ci rzeczywistej przyjmujemy, 
�e urojona jest r�wna zero) oraz w metody:
- Re zwracaj�c� cz�� rzeczywist� liczby,
- Im zwracaj�c� cz�� urojon� liczby,
- Abs zwracaj�c� modu� liczby,
- Arg zwracaj�c� argument (k�t) liczby w radianach
- Tekst zwracaj�c� napis reprezentuj�cy liczb�, o postaci a+bi (zamiast a i b stosowne wielko�ci)
Wszystkie atrybuty obiekt�w typu Zespolona powinny by� prywatne. Zastan�w si�, czy przechowywanie jako atrybut�w cz�ci rzeczywistej i urojonej jest jedynym sposobem na zrealizowanie powy�szego inferfejsu.

Napisz operator wej�cia akceptuj�cy liczby w formacie a+bi, pami�taj o sprawdzeniu, czy na pewno po cz�ci urojonej wpisano 'i' oraz spr�buj sprawdzi�, czy na pewno pomi�dzy liczbami jest plus lub minus (tu mo�e Ci si� przyda� omawiany ju� na laboratoriach manipulator std::ws z biblioteki iomanip oraz metody strumienia peek albo unget zdefiniowane w klasie std::basic_istream i przy niej udokumentowane).
Napisz operator wyj�cia korzystaj�cy z metody Tekst.

Napisz funkcj� testuj�c� konstruktor i wszystkie metody i funkcje.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cassert>

class Zespolona
{
    double rzeczywista;
    double urojona;

public:
    Zespolona(void)
    {
        rzeczywista = 0.0;
        urojona = 0.0;
    }

    Zespolona(double re,double im = 0)
    {
        rzeczywista = re;
        urojona = im;
    }

    double Re(void) const
    {
        return rzeczywista;
    }

    double Im(void) const
    {
        return urojona;
    }

    double& Im(void)
    {
        return urojona;
    }

    double Abs(void)
    {
        return std::sqrt(rzeczywista*rzeczywista + urojona*urojona);
    }

    double Arg(void)
    {
        if(Abs() != 0)
        {
            return std::acos(rzeczywista/std::sqrt(rzeczywista*rzeczywista + urojona*urojona));
        }

        return 0;
    }

    std::string Tekst(void)
    {
        std::ostringstream strumien;

        strumien << rzeczywista;

        if(urojona >= 0)
        {
            strumien << '+';
        }

        strumien << urojona << 'i';

        return strumien.str();
    }

    bool operator==(Zespolona z)
    {
        return (z.rzeczywista == rzeczywista && z.urojona == urojona);
    }

};

std::istream& operator>>(std::istream& wejscie, Zespolona& z)
{
    double im = 0.0;
    double re = 0.0;
    char c;

    wejscie >> std::ws >> re >> std::ws;
    char znak = wejscie.peek();

    if(znak != '+' && znak != '-')
    {
        wejscie.setstate(std::ios_base::failbit);
    }

    else
    {
        wejscie >> im >> std::ws >> c;

        if(wejscie)
        {
            if(c == 'i')
                z = Zespolona(re,im);
            else
                wejscie.setstate(std::ios_base::failbit);
        }
    }

    return wejscie;
}

std::ostream& operator<<(std::ostream& wyjscie, Zespolona z)
{
    return wyjscie << z.Tekst();
}

void testy(void)
{
    Zespolona z(3,4);
    assert(z == Zespolona(3,4));
    assert(z.Abs()== 5);
    assert(z.Im()== 4);
    assert(z.Re()== 3);
    assert(z.Tekst()=="3+4i");

    Zespolona r(5);
    assert(r == Zespolona(5,0));
    assert(r.Abs()== 5);
    assert(r.Arg()== 0);
    assert(r.Im()== 0);
    assert(r.Re()== 5);
    assert(r.Tekst() == "5+0i");

    Zespolona pusta;
    assert(pusta == Zespolona(0,0));

    std::cerr << "Klasa Zespolona pomyslnie przeszla testy \n";
}

int main(void)
{
    testy();

    Zespolona k;

    std::cout << "Podaj liczbe zespolona: ";
    std::cin >> k;
    std::cout << "\nPodana przez Ciebie liczba to: " << k << std::endl;
    std::cout << "Argument w radianach: " << k.Arg() << "\t Modul liczby: " << k.Abs() << "\n";

    return 0;
}

