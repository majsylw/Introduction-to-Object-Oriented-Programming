/*
Dopisz procedurê Sprzezenie, której argumentem bêdzie wskaŸnik do liczby zespolonej, i która zmodyfikuje wskazywan¹ liczbê 
zmieniaj¹c j¹ na jej sprzê¿enie. Je¿eli wskaŸnik nie wskazuje na ¿adn¹ liczbê, procedura niczego nie zrobi.
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

void Sprzezenie(Zespolona *z)
{
    if(z != nullptr)
    {
        z->Im() = -z->Im();
    }
}

auto test_Sprzezenie(void) -> void
  {
  Zespolona z(1.0,2.0);
  Sprzezenie(&z);
  assert(z.Re()==1.0);
  assert(z.Im()==-2.0);
  Sprzezenie(nullptr);  // nic nie robi, ale nie powinno powodowaæ bledu wykonania
  std::cerr << "test_Sprzezenie ok\n";
  }


int main(void)
{
    test_Sprzezenie();
    testy();

    Zespolona k;

    std::cout << "Podaj liczbe zespolona: ";
    std::cin >> k;
    std::cout << "\nPodana przez Ciebie liczba to: " << k << std::endl;
    std::cout << "Argument w radianach: " << k.Arg() << "\t Modul liczby: " << k.Abs() << "\n";

    return 0;
}

