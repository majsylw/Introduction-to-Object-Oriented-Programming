/*
Zdefiniuj klasę Wymierna modelującą liczbę wymierną. Wyposaż ją w stosowne konstruktory 
(nie zapominając o możliwości użycia liczb całkowitych w miejscach, gdzie oczekiwane są wymierne) oraz w metody:
Licznik zwracającą skrócony licznik,
Mianownik zwracającą skrócony mianownik,
operator+= dodającą dwie liczby,
operator-= odejmującą dwie liczby,
operator*= mnożącą dwie liczby,
operator/= dzielącą dwie liczby,
Skrócony mianownik powinien być dodatni, a znak liczby przetwarzany jako znak licznika. 
Napisz funkcję operator==, która porówna dwie liczby wymierne (liczby a nie ich konkretne zapisy, 
zapis 2/4 jest inny niż 1/2, ale to jest ta sama liczba). Napisz operator wejścia, 
który będzie akceptował napisy postaci "2/4", "3/-7" ale wymagając, aby pomiędzy liczbą licznika a znakiem '/' 
i między znakiem '/' a liczbą mianownika nie było spacji. Napisz wolnostojące operatory dodawania, 
odejmowania, mnożenia i dzielenia. Wszystkie atrybuty klasy powinny być prywatne.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cassert>
#include <cmath>

class Wymierna
{
    int licznik;
    int mianownik;

public:

    Wymierna(int l, int m = 1)
    {
        assert(m != 0);

        licznik = l;
        mianownik = m;
    }

    Wymierna(void)
    : licznik(0),mianownik(1)
    {
    }

    void skracanie(int l, int m)
    {
        int najm = 0;
        int znak = 1;

        if(l < 0 || m < 0)
        {
            l = std::abs(l);
            m = std::abs(m);
            znak = -1;
        }

        if(m >= l)
            najm = l;
        else
            najm = m;

        for(int i = najm; i >= 1; --i)
        {
            if(l%i == 0 && m%i == 0)
            {
                l /= i;
                m /= i;
            }
        }

        licznik = l * znak;
        mianownik = m;
    }

    int Licznik(void)
    {
        skracanie(licznik, mianownik);
        return licznik;
    }

    int Mianownik(void)
    {
        skracanie(licznik, mianownik);
        return mianownik;
    }

    Wymierna &operator+=(const Wymierna& w)
    {
        if(mianownik == w.mianownik)
        {
            licznik += w.licznik;
        }
        else
        {
            licznik *= w.mianownik;
            licznik += w.licznik * mianownik;
            mianownik *= w.mianownik;
        }

        skracanie(licznik, mianownik);

        return *this;
    }

    Wymierna &operator-=(const Wymierna& w)
    {
        if(mianownik == w.mianownik)
        {
            licznik -= w.licznik;
        }
        else
        {
            licznik *= w.mianownik;
            licznik -= w.licznik * mianownik;
            mianownik *= w.mianownik;
        }

        skracanie(licznik,mianownik);

        return *this;
    }

    Wymierna &operator*=(const Wymierna& w)
    {
        licznik *= w.licznik;
        mianownik *= w.mianownik;

        skracanie(licznik, mianownik);

        return *this;
    }

    Wymierna &operator/=(const Wymierna& w)
    {
        licznik *= w.mianownik;
        mianownik *= w.licznik;

        skracanie(licznik, mianownik);

        return *this;
    }

};

Wymierna operator+(const Wymierna& w1, const Wymierna& w2)
{
    Wymierna q(w1);
    return q+=w2;
}

Wymierna operator-(const Wymierna& w1, const Wymierna& w2)
{
    Wymierna q(w1);
    return q-=w2;
}

Wymierna operator*(const Wymierna& w1, const Wymierna& w2)
{
    Wymierna q(w1);
    return q*=w2;
}

Wymierna operator/(const Wymierna& w1, const Wymierna& w2)
{
    Wymierna q(w1);
    return q/=w2;
}

bool operator==(Wymierna w1, Wymierna w2)
{
    return(w1.Licznik() == w2.Licznik() && w2.Mianownik() == w1.Mianownik());
}

std::istream& operator>>(std::istream& wejscie, Wymierna& q)
{
    int licznik;
    int mianownik;
    char separator;

    wejscie >> std::ws >> licznik >> separator >> mianownik >> std::ws;

    if(wejscie)
    {
        if(separator == '/')
        {
            if(mianownik != 0)
            {
                q = Wymierna(licznik,mianownik);
            }
            else
                wejscie.setstate(std::ios_base::failbit);
        }
        else
            wejscie.setstate(std::ios_base::failbit);
    }

    return wejscie;
}

auto test_Wymierna(void) -> void
{
    Wymierna w1(2,-4);
    assert(w1.Licznik()==-1);
    assert(w1.Mianownik()==2);

    Wymierna w2;
    assert(w2.Licznik()==0);
    assert(w2.Mianownik()==1);

    Wymierna w3(2);
    assert(w3.Licznik()==2);
    assert(w3.Mianownik()==1);

    Wymierna q1 = w1 + w3;
    w1+=w3;
    assert(w1.Licznik()==3);
    assert(w1.Mianownik()==2);
    assert(q1.Licznik()==3);
    assert(q1.Mianownik()==2);

    w1+=w3+=Wymierna(4,8);
    assert(w3.Licznik()==5);
    assert(w3.Mianownik()==2);
    assert(w1.Licznik()==4);
    assert(w1.Mianownik()==1);

    Wymierna q2 = w1 - Wymierna(4,8);
    w1-=Wymierna(4,8);
    assert(w1.Licznik()==7);
    assert(w1.Mianownik()==2);
    assert(q2.Licznik()==7);
    assert(q2.Mianownik()==2);

    w1=Wymierna(9,4);
    Wymierna q3 = w1 * Wymierna(16,15);
    w1*=Wymierna(16,15);  // 9/4 * 16/15 = 3/1 * 4/5 = 12/5 = 144/60
    assert(w1.Licznik()==12);
    assert(w1.Mianownik()==5);
    assert(q3.Licznik()==12);
    assert(q3.Mianownik()==5);

    Wymierna q4 = w1/Wymierna(16,15);
    w1/=Wymierna(16,15);
    assert(w1.Licznik()==9);
    assert(w1.Mianownik()==4);
    assert(q4.Licznik()==9);
    assert(q4.Mianownik()==4);

    w1=3;
    assert(w1.Licznik()==3);
    assert(w1.Mianownik()==1);

    assert(w1==3);

    std::istringstream we("-6/8 10/-14");
    we >> w1 >> w2;
    assert(we);
    assert(w1==Wymierna(-3,4));
    assert(w2==Wymierna(-5,7));

    std::istringstream we2("-6 /8");
    we >> w1;
    assert(!we);
    std::cerr << "Program pomyslnie przeszedl testy. \n";
}

int main(void)
{
    test_Wymierna();

    return 0;
}
