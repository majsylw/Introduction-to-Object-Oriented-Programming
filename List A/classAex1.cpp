/*
Zdefiniuj klasę Trojmian, która będzie modelować trójmian, to znaczy wielomian co najwyżej drugiego stopnia. 
Wyposaż ją w stosowne konstruktory, między innymi taki, który pozwoli traktować liczby zmiennoprzecinkowe 
jako takie szczególne przypadki trójmianu, w których jedynie współczynnik stały (przy x0) jest niezerowy, 
oraz w metody:
- Wspolczynnik zwracającą wielkość współczynnika przy potędze zadanej parametrem do tej metody,
- operator() obliczającą wartość trójmianu w określonym punkcie przy pomocy algorytmu Hornera,
- operator+= dodającą dwa trójmiany (jako funkcje) zgodnie z logiką działania operatora +=,
- operator-= odejmującą dwa trójmiany (jako funkcje) zgodnie z logiką działania operatora -=,
Napisz wolnostojące dwuargumentowe operatory operator+ oraz operator- realizujące dodawanie 
i odejmowanie trójmianów. Napisz również funkcję MniejWiecej, która sprawdzi, 
czy współczynniki dwóch trójmianów są z dobrym przybliżeniem równe. Napisz operator wejścia dla tej klasy, 
który będzie rozpoznawał trójmian zapisany w formacie "[1.0,2.0,3.0]", gdzie pierwsza liczba 
to współczynnik przy zerowej potędze itd. Możesz dopuścić spacje pomiędzy dowolnymi elementami tego zapisu. 
Przykłady użycia wszystkich opisanych wyżej usług są w testach poniżej. Wszystkie atrybuty klasy powinny być prywatne.
*/

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

class Trojmian
{
    double wspolczynnik0;
    double wspolczynnik1;
    double wspolczynnik2;

public:

    Trojmian(double w0, double w1 = 0.0, double w2 = 0.0)
    : wspolczynnik0(w0),wspolczynnik1(w1),wspolczynnik2(w2)
    {
    }

    Trojmian(void)
    : wspolczynnik0(0.0),wspolczynnik1(0.0),wspolczynnik2(0.0)
    {
    }

    double Wspolczynnik(int indeks) const
    {
        assert(indeks >= 0);
        assert(indeks <= 2);

        if(indeks == 0)
            return wspolczynnik0;
        else if(indeks == 1)
            return wspolczynnik1;
        else
            return wspolczynnik2;
    }

    double operator()(double argument)
    {
        double wynik = argument * (wspolczynnik2 * argument + wspolczynnik1) + wspolczynnik0;
        return wynik;
    }

    Trojmian& operator+=(const Trojmian& t)
    {
        wspolczynnik0 += t.wspolczynnik0;
        wspolczynnik1 += t.wspolczynnik1;
        wspolczynnik2 += t.wspolczynnik2;

        return *this;
    }

    Trojmian& operator-=(const Trojmian& t)
    {
        wspolczynnik0 -= t.wspolczynnik0;
        wspolczynnik1 -= t.wspolczynnik1;
        wspolczynnik2 -= t.wspolczynnik2;

        return *this;
    }

    Trojmian& operator*=(double d)
    {
        wspolczynnik0 *= d;
        wspolczynnik1 *= d;
        wspolczynnik2 *= d;

        return *this;
    }

    int ile_miejsc_zerowych(void)
    {
        if(wspolczynnik1*wspolczynnik1 - 4 * wspolczynnik2 * wspolczynnik0 < 0)
            return 0;
        else if(wspolczynnik1*wspolczynnik1 - 4 * wspolczynnik2 * wspolczynnik0 == 0)
            return 1;
        else
            return 2;
    }

    std::vector<double> miejsca_zerowe(void)
    {
        std::vector<double> msc_zerowe;

        if(ile_miejsc_zerowych() == 1)
            msc_zerowe.push_back(-wspolczynnik1/(2*wspolczynnik2));
        else if(ile_miejsc_zerowych() == 2)
        {
            msc_zerowe.push_back((2*wspolczynnik0)/(-wspolczynnik1-std::sqrt(wspolczynnik1*wspolczynnik1 - 4 * wspolczynnik2 * wspolczynnik0)));
            msc_zerowe.push_back((2*wspolczynnik0)/(-wspolczynnik1+std::sqrt(wspolczynnik1*wspolczynnik1 - 4 * wspolczynnik2 * wspolczynnik0)));
        }
        else
        {
            std::cout << "Brak rzeczywistych miejsc zerowych. \n";
        }

        return msc_zerowe;
    }
};

Trojmian operator+(const Trojmian& t1, const Trojmian& t2)
{
    Trojmian w(t1);
    return w += t2;
}

Trojmian operator-(const Trojmian& t1, const Trojmian& t2)
{
    Trojmian w(t1);
    return w -= t2;
}

Trojmian operator*(const Trojmian& t1, double d)
{
    Trojmian w(t1);
    return w *= d;
}

Trojmian operator*(double d, const Trojmian& t1)
{
    Trojmian w(t1);
    return w *= d;
}

Trojmian operator-(const Trojmian& t1)
{
    Trojmian w(t1);
    return w *= -1;
}

Trojmian operator+(const Trojmian& t1)
{
    Trojmian w(t1);
    return w *= +1;
}

std::istream& operator>>(std::istream& wejscie, Trojmian& t)
{
    char pocz,p1,p2,kon;
    double w0;
    double w1;
    double w2;

    wejscie >> pocz >> w0 >> p1 >> w1 >> p2 >> w2 >> kon;

    if(wejscie)
    {
        if(pocz == '[' && kon == ']' && p1 == ',' && p2 == ',')
        {
            t = Trojmian(w0,w1,w2);
        }
        else
            wejscie.setstate(std::ios_base::failbit);
    }

    return wejscie;
}

bool MniejWiecej(Trojmian t1, Trojmian t2)
{
    double eps = 0.001;

    if ((t1.Wspolczynnik(0) <= t2.Wspolczynnik(0) + eps && t1.Wspolczynnik(0)>= t2.Wspolczynnik(0) - eps)
        && (t1.Wspolczynnik(1) <= t2.Wspolczynnik(1) + eps && t1.Wspolczynnik(1)>= t2.Wspolczynnik(1) - eps)
        && (t1.Wspolczynnik(2) <= t2.Wspolczynnik(2) + eps && t1.Wspolczynnik(2)>= t2.Wspolczynnik(2) - eps))
            return true;

    return false;
}

bool operator<(const Trojmian t1, const Trojmian t2)
{
	for(int i=0; i<2; ++i)
    {
		if(t1.Wspolczynnik(2-i) < t2.Wspolczynnik(2-i))
			return true;
		else if(t1.Wspolczynnik(2-i) > t2.Wspolczynnik(2-i))
			return false;
	}

	return false;
}

bool operator>=(const Trojmian t1, const Trojmian t2)
{
	return !(t1 < t2);
}

bool operator==(const Trojmian t1, const Trojmian t2)
{
	return !(t1 < t2) && !(t2 < t1);
}

bool operator<=(const Trojmian t1, const Trojmian t2)
{
	return (t1 < t2) || (!(t2 < t1) && !(t1 < t2));
}

bool operator!=(const Trojmian t1, const Trojmian t2)
{
	return !(!(t1 < t2) && !(t2 < t1));
}

bool operator>(const Trojmian t1, const Trojmian t2)
{
	return !(t1 < t2) && !(!(t1 < t2) && !(t2 < t1));
}

auto test_Trojmian(void) -> void
{
    Trojmian t1(1.0,2.0,3.0);

    assert(t1.Wspolczynnik(0)==1.0);
    assert(t1.Wspolczynnik(1)==2.0);
    assert(t1.Wspolczynnik(2)==3.0);
    assert(t1(0)==1.0);
    assert(t1(1)==6.0);
    assert(t1.ile_miejsc_zerowych() == 0);
    std::vector<double> nic;
    assert((t1.miejsca_zerowe() == nic));

    Trojmian t1a;
    t1a=t1+Trojmian(2.0,3.0,4.0);
    assert(t1a.Wspolczynnik(0)==3.0);
    assert(t1a.Wspolczynnik(1)==5.0);
    assert(t1a.Wspolczynnik(2)==7.0);
    assert(MniejWiecej(t1,t1a-Trojmian(2.0,3.0,4.0)));
    assert(t1a.ile_miejsc_zerowych() == 0);

    Trojmian t1b=t1a;
    t1b-=Trojmian(2.0,3.0,4.0);
    assert(MniejWiecej(t1,t1b));
    t1+=Trojmian(2.0,3.0,4.0);
    assert(t1.Wspolczynnik(0)==3.0);
    assert(t1.Wspolczynnik(1)==5.0);
    assert(t1.Wspolczynnik(2)==7.0);
    assert(t1(0)==3.0);
    assert(t1(1)==15.0);
    assert(MniejWiecej(t1,Trojmian(3.0,5.0,7.0)));
    assert(!(MniejWiecej(t1,Trojmian(3.5,5.5,7.5))));

    Trojmian t2;
    t2=5.0;
    assert(t2.Wspolczynnik(0)==5.0);
    assert(t2.Wspolczynnik(1)==0.0);
    assert(t2.Wspolczynnik(2)==0.0);
    std::istringstream we("[1.0,2.0,3.0][3.5,4.5,-5.5]");
    we >> t1 >> t2;
    assert(we);
    assert(MniejWiecej(t1,Trojmian(1.0,2.0,3.0)));
    assert(MniejWiecej(t2,Trojmian(3.5,4.5,-5.5)));

    Trojmian t3(1.0,2.0,3.0);
    Trojmian t3a;
    t3 *= 5;
    t3a = t3 * 2;
    assert(t3.Wspolczynnik(2) == 15.0);
    assert(t3.Wspolczynnik(1) == 10.0);
    assert(t3.Wspolczynnik(0) == 5.0);
    assert(t3a.Wspolczynnik(2) == 30.0);
    assert(t3a.Wspolczynnik(1) == 20.0);
    assert(t3a.Wspolczynnik(0) == 10.0);
    t3a = 0.5 * t3a;
    assert(t3a.Wspolczynnik(2) == 15.0);
    assert(t3a.Wspolczynnik(1) == 10.0);
    assert(t3a.Wspolczynnik(0) == 5.0);

    Trojmian t4(-t3);
    assert(t4.Wspolczynnik(2) == -15.0);
    assert(t4.Wspolczynnik(1) == -10.0);
    assert(t4.Wspolczynnik(0) == -5.0);

    t4 = +t3;
    assert(t4.Wspolczynnik(2) == 15.0);
    assert(t4.Wspolczynnik(1) == 10.0);
    assert(t4.Wspolczynnik(0) == 5.0);

    assert(-t4 < t3);
    assert(-t4 <= t3);
    assert(t4 <= t3);
    assert(t4 > -t3);
    assert(t4 >= -t3);
    assert(t4 <= t3);
    assert(t4 == t3);
    assert(t4 != -t3);

    Trojmian t5(1.0,2.0,1.0);
    assert(t5.ile_miejsc_zerowych() == 1);
    std::vector<double> zero{-1};
    assert(t5.miejsca_zerowe() == zero);

    Trojmian t6(6.0,-1.0,-1.0);
    assert(t6.ile_miejsc_zerowych() == 2);
    assert((t6.miejsca_zerowe().at(0) == -3));
    assert((t6.miejsca_zerowe().at(1) == 2));

    std::cerr << "test_Trojmian ok\n";
}

int main(void)
{
    test_Trojmian();

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();

    return 0;
}
