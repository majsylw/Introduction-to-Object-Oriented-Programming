/*
Napisz klasę BigInt modelującą liczby całkowite o dowolnej wielkości. Wyposaż ją w:
- Konstruktor z liczb typu int
- Konstruktor z napisów, rozumianych jako zapis liczby w dziesiętnym układzie pozycyjnym
- Operatory arytmetyczne dodawania i odejmowania (zarówno typu += jak i +), unarne + i -, przyrostkowe i przedrostkowe ++ oraz --
- Operatory porównania, w komplecie: <, <=, >, >=, ==, !=
- Operatory >> oraz << pozwalające na wczytanie liczby ze strumienia i zapisanie jej na strumień
Dodatkowy plus za zadanie można dostać za implementację, w której nie będziemy pamiętać napisu, ale ciąg wartości 
32-bitowych, które można rozumieć jako zapis liczby w układzie o podstawie 232. Wartości ujemne można reprezentować 
pamiętając do tego dodatkowo znak. (Cyfry 32-bitowe są dla nas lepsze niż 64-bitowe, bo przy mnożeniu dwóch liczb 
32-bitowych(jednocyfrowych) wynik zmieści się w liczbie 64-bitowej(dwucyfrowej), podobnie przy dzieleniu, 
będziemy potrzebowali dzielić liczby 64-bitowe(dwucyfrowe) przez 32-bitowe(jednocyfrowe).)

Jeszcze jeden dodatkowy plus specjalnej kategorii można dostać za próbę zaprogramowania dzielenia dwóch liczb. 
Stosowny algorytm można znaleźć w książce Donalda E. Knutha Sztuka programowania (The Art Of Computer Programming), 
tom 2, rozdział 4.3.1, algorytm D.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <iomanip>

bool czy_liczba(std::string napis)
{
    if(napis[0] == '-' || napis[0] == '+')
    {
        napis.erase(0);
    }

    if(napis[0] == 0 && napis.size() > 1)
    {
        return false;
    }

    for(unsigned int i = 0; i < napis.size(); ++i)
    {
        if(napis[i] < '0' || napis[i] > '9')
            return false;
    }

    return true;
}

int konw(std::string a)
{
    std::istringstream str(a);

    int x = 0;
    str >> x;

    return x;
}

int konw(char a)
{
    assert(a >= '0');
    assert(a <= '9');

    if(a == '0')
        return 0;
    if(a == '1')
        return 1;
    if(a == '2')
        return 2;
    if(a == '3')
        return 3;
    if(a == '4')
        return 4;
    if(a == '5')
        return 5;
    if(a == '6')
        return 6;
    if(a == '7')
        return 7;
    if(a == '8')
        return 8;
    else
        return 9;
}

class BigInt;

bool operator<(const BigInt, const BigInt);
bool operator==(const BigInt, const BigInt);
bool operator!=(const BigInt, const BigInt);
bool operator>=(const BigInt, const BigInt);

class BigInt
{
private:
    bool dodatnia;
    std::vector<int> duza_liczba;

public:

    BigInt(std::string liczba = "")
    {
        assert(czy_liczba(liczba));

        if(liczba.empty())
        {
            duza_liczba = {0};
            dodatnia = true;
        }
        else
        {

            if(liczba[0] == '-')
            {
                dodatnia = false;
                liczba.erase(liczba.begin());
                if(liczba[0] == '0')
                {
                    dodatnia = true;
                }
            }
            else
            {
                dodatnia = true;
                if(liczba[0] == '+')
                    liczba.erase(liczba.begin());
            }

            int pocz = liczba.size()%9;
            if(pocz != 0)
                duza_liczba.push_back(konw(liczba.substr(0,pocz)));

            for(unsigned int i = 0; i < (liczba.size()/9); ++i)
            {
                duza_liczba.push_back(konw(liczba.substr(pocz,9)));
                pocz += 9;
            }
        }
    }

    BigInt(std::vector<int> liczba)
    {
        if(liczba.size() > 1)
        {
            assert(liczba[0] != 0);
        }

        if(liczba[0] < 0)
        {
            dodatnia = false;
            liczba[0] *= -1;
        }
        else
        {
            dodatnia = true;
        }

        int pomocnicza = 0;

        for(int i = 1; i <= liczba.size(); ++i)
        {
            if(liczba[liczba.size() - i] > 999999999)
            {
                pomocnicza = liczba[liczba.size() - i];
                liczba[liczba.size() - i] = liczba[liczba.size() - i]%1000000000;

                if(liczba.size() != i)
                {
                    liczba[liczba.size() - i - 1] += pomocnicza/1000000000;
                }
                else
                {
                    liczba.insert(liczba.begin(),(pomocnicza/1000000000));
                }
            }
        }

        duza_liczba = liczba;
    }

    bool Czy_dodatnia(void) const
    {
        return dodatnia;
    }

    std::vector<int> Liczba(void) const
    {
        return duza_liczba;
    }

    int ile_elementow(void) const
    {
        return duza_liczba.size();
    }

    int operator[](int indeks) const
    {
        assert(indeks > -1);
        assert(indeks < ile_elementow());

        return duza_liczba[indeks];
    }

    int& operator[](int indeks)
    {
        assert(indeks > -1);
        assert(indeks < ile_elementow());

        return duza_liczba[indeks];
    }

    BigInt operator-(void) const
    {
        BigInt w(duza_liczba);
        w.dodatnia = (!dodatnia);
        return w;
    }

    BigInt operator+(void) const
    {
        return *this;
    }

    BigInt& operator+=(const BigInt& t)
    {
        BigInt p2 = t;
        BigInt p1 = (*this);

        if(p1.dodatnia == p2.dodatnia)
        {
            while(p1.ile_elementow() < p2.ile_elementow())
            {
                p1.duza_liczba.insert(p1.duza_liczba.begin(),0);

            }

            while(p1.ile_elementow() > p2.ile_elementow())
            {
                p2.duza_liczba.insert(p2.duza_liczba.begin(),0);
            }

            for(int i = 1; i <= p2.ile_elementow(); ++i)
            {
                p1.duza_liczba[p1.ile_elementow() - i] += p2[p2.ile_elementow() - i];

                if(p1.duza_liczba[p1.ile_elementow() - i] >= 1000000000)
                {
                    p1.duza_liczba[p1.ile_elementow() - i] = p1.duza_liczba[p1.ile_elementow() - i]%1000000000;

                    if((p1.ile_elementow() - i) != 0)
                    {
                        p1.duza_liczba[p1.ile_elementow() - i - 1] += 1;
                    }
                    else
                    {
                        p1.duza_liczba.insert(p1.duza_liczba.begin(),1);
                    }
                }
            }
        }
        else
        {
            if(ile_elementow() < t.ile_elementow())
            {
                p1 = t;
                p2 = (*this);
            }

            if(ile_elementow() == t.ile_elementow())
            {
                for(int i = 0; i < ile_elementow(); ++i)
                {
                    if(duza_liczba[i] > t[i])
                    {
                        break;
                    }
                    if(duza_liczba[i] < t[i])
                    {
                        p1 = t;
                        p2 = (*this);
                        break;
                    }
                }
            }

            while(p1.ile_elementow() < p2.ile_elementow())
            {
                p1.duza_liczba.insert(p1.duza_liczba.begin(),0);
            }

            while(p1.ile_elementow() > p2.ile_elementow())
            {
                p2.duza_liczba.insert(p2.duza_liczba.begin(),0);
            }

            for(int i = 1; i <= p1.ile_elementow(); ++i)
            {
                p1[p1.ile_elementow() - i] -= p2[p2.ile_elementow() - i];

                if(p1[p1.ile_elementow() - i] < 0)
                {
                    p1[p1.ile_elementow() - i - 1] -= 1;
                    p1[p1.ile_elementow() - i] += 1000000000;
                }
            }

            while(p1[0] == 0)
            {
                if(p1.ile_elementow() == 1)
                {
                    p1.dodatnia = true;
                    break;
                }

                (p1.duza_liczba).erase((p1.duza_liczba).begin());
            }
        }

        (*this) = p1;

        return *this;
    }

    BigInt& operator+=(const int& t)
    {
        BigInt kopia_t((std::vector<int>){t});
        (*this) += kopia_t;

        return *this;
    }

    BigInt& operator-=(const BigInt& t)
    {
        BigInt kopia_t(-t);
        (*this) += kopia_t;

        return *this;
    }

    BigInt& operator-=(const int& t)
    {
        BigInt kopia_t((std::vector<int>){t});
        (*this) -= kopia_t;

        return *this;
    }

    BigInt& operator/=(const BigInt& t)
    {
        assert(t != BigInt("0"));

        BigInt d1 = (*this);
        BigInt d2 = t;

        if(d1.dodatnia == false)
        {
            d1.dodatnia = true;
        }

        if(d2.dodatnia == false)
        {
            d2.dodatnia = true;
        }

        if(d1 < d2)
        {
            d1 = BigInt{"0"};
        }
        else if(d1 == d2)
        {
            d1 = BigInt("1");
        }
        else
        {
            BigInt iloraz("0");
            do
            {
                d1 -= d2;
                ++iloraz;
            }
            while(d1 >= d2);

            d1 = iloraz;
        }

        if(dodatnia != t.dodatnia && d1 != BigInt("0"))
        {
            d1.dodatnia = false;
        }

        (*this) = d1;

        return *this;
    }

    BigInt& operator++(void)//++(BigInt)
    {
        (*this) += BigInt("1");

        return *this;
    }

    BigInt operator++(int)//(BigInt)++
    {
        BigInt b = (*this);
        (*this) += 1;
        return b;
    }

    BigInt& operator--(void) //--(BigInt)
    {
        (*this) -= 1;

        return *this;
    }

    BigInt operator--(int) //(BigInt)--
    {
        BigInt b = (*this);
        (*this) -= BigInt("1");
        return b;
    }
};

BigInt operator+(const BigInt& t1, const BigInt& t2)
{
    BigInt w(t1);
    return w += t2;
}

BigInt operator+(const BigInt& t1, const int& t2)
{
    BigInt w(t1);
    return w += t2;
}

BigInt operator+(const int& t1, const BigInt& t2)
{
    BigInt w(std::vector<int>{t1});
    return w += t2;
}
BigInt operator-(const BigInt& t1, const BigInt& t2)
{
    BigInt w(t1);
    return w -= t2;
}

BigInt operator-(const BigInt& t1, const int& t2)
{
    BigInt w(t1);
    return w -= t2;
}

BigInt operator-(const int& t1, const BigInt& t2)
{
    BigInt w(std::vector<int>{t1});
    return w -= t2;
}

BigInt operator/(const BigInt& t1, const BigInt& t2)
{
    BigInt w(t1);
    return w /= t2;
}

bool operator<(const BigInt t1, const BigInt t2)
{
    if(t1.Czy_dodatnia() != t2.Czy_dodatnia())
    {
        if(!t1.Czy_dodatnia())
            return true;
        else
            return false;
    }
    if(t1.Czy_dodatnia() == true && t2.Czy_dodatnia() == true)
    {
        if(t1.ile_elementow() != t2.ile_elementow())
        {
            if(t1.ile_elementow() < t2.ile_elementow())
                return true;
            else
                return false;
        }
        else
        {
            for(int i = 0; i < t1.ile_elementow(); ++i)
            {
                if(t1[i] != t2[i])
                {
                    if(t1[i] < t2[i])
                        return true;
                    else
                        return false;
                }
            }
            return false;
        }
    }
    if(t1.Czy_dodatnia() == false && t2.Czy_dodatnia() == false)
    {
        if(t1.ile_elementow() != t2.ile_elementow())
        {
            if(t1.ile_elementow() < t2.ile_elementow())
                return false;
            else
                return true;
        }
        else
        {
            for(int i = 0; i < t1.ile_elementow(); ++i)
            {
                if(t1[i] != t2[i])
                {
                    if(t1[i] < t2[i])
                        return false;
                    else
                        return true;
                }
            }
            return false;
        }
    }
    return false;
}

bool operator>=(const BigInt t1, const BigInt t2)
{
	return !(t1 < t2);
}

bool operator==(const BigInt t1, const BigInt t2)
{
	return !(t1 < t2) && !(t2 < t1);
}

bool operator<=(const BigInt t1, const BigInt t2)
{
	return (t1 < t2) || (!(t2 < t1) && !(t1 < t2));
}

bool operator!=(const BigInt t1, const BigInt t2)
{
	return !(!(t1 < t2) && !(t2 < t1));
}

bool operator>(const BigInt t1, const BigInt t2)
{
	return !(t1 < t2) && !(!(t1 < t2) && !(t2 < t1));
}

std::istream& operator>>(std::istream& wejscie, BigInt& b)
{
    std::string liczba = "";

    wejscie >> liczba;

    if(czy_liczba(liczba))
    {
        b = BigInt(liczba);
    }
    else
    {
        wejscie.setstate(std::ios_base::failbit);
    }

    return wejscie;
}

std::ostream& operator<<(std::ostream& wyjscie, BigInt b)
{
    if(!b.Czy_dodatnia())
    {
        wyjscie << '-';
    }

    wyjscie << b[0];

    for(int i = 1; i < b.ile_elementow(); ++i)
    {
        wyjscie << std::setfill('0') << std::setw(9) << b[i];
    }

    return wyjscie;
}

auto test_BigInt(void) -> void
{
    BigInt b1("123456789012345678901234567890");
    BigInt b2("120000011000000000000000000019");
    BigInt u1("-123456789012345678901234567890");
    BigInt u2("-120000011000000000000000000019");
    BigInt k1(std::vector<int>{-1239999999,456789012,345678901,234567890});
    BigInt k2("1239999999456789012345678901234567890");
    assert(k1 == -k2);
    assert(b2 < b1);
    assert(b2 != b1);
    assert(b1 > b2);
    assert(u1 < u2);

    assert(u1 == (-b1));
    u1 = BigInt("-12345678901234567890123456789");
    assert(u1 >= u2);
    BigInt c1=+b1;
    b1+=b2;
    assert(b1==BigInt("243456800012345678901234567909"));

    b1-=b2;
    assert(b1 == BigInt("123456789012345678901234567890"));

    BigInt b3(    "123456789012345678901234567890");
    assert(b3 == c1);
    BigInt b4("9999920000011000000000000000000019");
    assert(b4 >= b3);
    assert((b3+b4)==BigInt("10000043456800012345678901234567909"));

    BigInt c2 = b3+b4;
    ++c2;

    assert(c2 == BigInt("10000043456800012345678901234567910"));
    c2++;
    assert(c2 == BigInt("10000043456800012345678901234567911"));

    --(--c2);

    assert(c2 == BigInt("10000043456800012345678901234567909"));
    BigInt c3("9999999999999999999999999999999999999999");
    c3++;

    assert(c3 == BigInt("10000000000000000000000000000000000000000"));

    c3--;

    assert(c3 == BigInt("9999999999999999999999999999999999999999"));

    std::istringstream we("10000043456800012345678901234567909 -235670989043456879723456788979234567909");
    we >> b1 >> b2;
    assert(we);

    assert((b1 - b2) == BigInt("235680989086913679735802467880469135818"));
    assert((b2/b1) == BigInt("-23566"));
    assert((b2/b2) == BigInt("1"));
    assert((b1/b2) == BigInt("0"));

    std::cerr << "Program pomyslnie przeszedl testy. \n";
}


int main()
{
    test_BigInt();

    BigInt c3("9999999999999999999999999999999999999999");
    c3++;
    std::cout << c3 << std::endl;

    BigInt kotek(std::vector<int>{-1239999999,456789012,345678901,234567890});
    assert(c3 == BigInt("10000000000000000000000000000000000000000"));

    BigInt b1("100000");
    BigInt b2("-23569");
    BigInt b3("100000");
    b1 -= b2;
    b1++;

    std::cout << kotek << std::endl;

    std::cout << (b3++) << "\t";
    std::cout << b3;
    b3 = BigInt("100000");
    std::cout << std::endl << (++b3) << "\t";
    std::cout << b3 << std::endl << std::endl;

    b3 = BigInt("100000");
    std::cout << (b3++) << "\t" << b3;
    b3 = BigInt("100000");
    std::cout << std::endl << (++b3) << "\t" << b3 << std::endl;

    int a = 3;

    std::cout <<std::endl << std::endl << a++ << "\t" << a << std::endl;
    a = 3;
    std::cout << ++a << "\t" << a << std::endl;

    a = 3;
    std::cout <<std::endl << std::endl << (a++) << "\t";
    std::cout << (a) << std::endl;
    a = 3;
    std::cout << (++a) << "\t";
    std::cout << (a) << std::endl;

    BigInt b4("14444444313");
    BigInt b5("123456789");

    b4 /= b5;

    BigInt b6("14444644313");
    BigInt b7("-123456789");

    std::cout << b4 << " " << b6/b7;

    std::cout << std::endl << BigInt("-7") - BigInt("-7") << std::endl;

    BigInt m("-0");

    std::cout << BigInt("-0") + BigInt("0");

    return 0;
}
