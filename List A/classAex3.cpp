/*
Napisz klasę Macierz8, która będzie reprezentowała macierze 8x8. Wyposaż ją w konstruktory swojego pomysłu, 
oraz w operator[], który będzie przyjmował obiekt zawierający dwie liczby całkowite, rozumiane jako współrzędne 
ze zbioru {1,...,8}, i zwracał współczynnik macierzy o zadanych współrzędnych. Wyposaż swoje macierze w dodawanie, 
mnożenie i ewentualnie inne operacje, które mogą być potrzebne do zrealizowania powyższych i/lub do demonstracji 
i testowania.
Napisz klasę Wektor8, która będzie reprezentowała wektory (w sensie matematycznym) długości 8. 
Wyposaż ją w stosowne konstruktory i w operator[], który będzie przyjmował jedną liczbę całkowitą, 
rozumianą jako współrzędna ze zbioru {1,...,8}, i zwracał współczynnik wektora o tej współrzędnej. 
Wyposaż swoje wektory w dodawanie i ewentualnie inne operacje, które mogą być potrzebne do zrealizowania 
powyższych i/lub do demonstracji i testowania.

Uzupełnij swój program o mnożenie macierzy przez wektor. Postaraj się tak napisać całość, 
aby zmiana rozmiaru 8 na inny nie pociągała za sobą konieczności zrobienia dużych zmian w kodzie.
*/

#include <iostream>
#include <vector>
#include <cassert>

class Wektor8
{
    unsigned int rozmiar = 8;
    std::vector<double> wektor;

public:

    Wektor8(std::vector<double> argumenty)
    {
        assert(argumenty.size() <= rozmiar);

        for(unsigned int i = 0; i < argumenty.size(); ++i)
        {
            wektor.push_back(argumenty[i]);
        }

        for(unsigned int i = argumenty.size(); i < rozmiar; ++i)
        {
            wektor.push_back(0.0);
        }
    }

    Wektor8()
    {
        for(unsigned int i = 0; i < rozmiar; ++i)
        {
            wektor.push_back(0.0);
        }
    }

    unsigned int Rozmiar_Wektora() const
    {
        return rozmiar;
    }

    double operator[](unsigned int indeks) const
    {
        assert(indeks > 0);
        assert(indeks <= rozmiar);

        return wektor[indeks - 1];
    }

    double & operator[](unsigned int indeks)
    {
        assert(indeks > 0);
        assert(indeks <= rozmiar);

        return wektor[indeks - 1];
    }

    void ustaw_wartosc(unsigned int i, double wartosc)
    {
        wektor[i - 1] = wartosc;
    }

    Wektor8& operator+=(const Wektor8& w)
    {
        for(unsigned int i = 0; i < rozmiar; ++i)
        {
            wektor[i] += w.wektor[i];
        }

        return *this;
    }

    Wektor8& operator-=(const Wektor8& w)
    {
        for(unsigned int i = 0; i < rozmiar; ++i)
        {
            wektor[i] -= w.wektor[i];
        }

        return *this;
    }

};

Wektor8 operator+(const Wektor8& v1, const Wektor8& v2)
{
    Wektor8 w(v1);
    return w += v2;
}

Wektor8 operator-(const Wektor8& v1, const Wektor8& v2)
{
    Wektor8 w(v1);
    return w -= v2;
}

double iloczyn_skalarny(const Wektor8 v1, const Wektor8 v2)
{
    assert(v1.Rozmiar_Wektora() == v2.Rozmiar_Wektora());

    double skalar = 0.0;

    for(unsigned int i = 1; i <= v1.Rozmiar_Wektora(); ++i)
    {
        skalar += v1[i] * v2[i];
    }

    return skalar;
}

bool operator==(const Wektor8 v1, const Wektor8 v2)
{
    assert(v1.Rozmiar_Wektora() == v2.Rozmiar_Wektora());

    for(unsigned int i = 1; i <= v1.Rozmiar_Wektora(); ++i)
    {
        if(v1[i] != v2[i])
            return false;
    }
	return true;
}

class Macierz8
{
    std::vector<Wektor8> macierz;
    unsigned int rozmiar = 8;

public:

    Macierz8(std::vector<Wektor8> kolumny)
    {
        assert(kolumny.size() <= rozmiar);
        assert(rozmiar == kolumny[0].Rozmiar_Wektora());

        for(unsigned int i = 0; i < kolumny.size(); ++i)
        {
            macierz.push_back(kolumny[i]);
        }

        for(unsigned int i = kolumny.size(); i < rozmiar; ++i)
        {
            std::vector<double> kolumny_puste(rozmiar,0.0);
            macierz.push_back(kolumny_puste);
        }

    }

    Macierz8(void)
    {
        std::vector<double> kolumny_puste(rozmiar,0.0);

        for(unsigned int i = 0; i < rozmiar; ++i)
        {
            macierz.push_back(kolumny_puste);
        }
    }

    unsigned int Rozmiar_Macierzy() const
    {
        return rozmiar;
    }

    double operator[](std::vector<unsigned int> para_indeksow) const
    {
        assert(para_indeksow[0] > 0);
        assert(para_indeksow[0] <= rozmiar);
        assert(para_indeksow[1] > 0);
        assert(para_indeksow[1] <= rozmiar);

        Wektor8 kolumna_j =  macierz[para_indeksow[1] - 1];

        return kolumna_j[para_indeksow[0]];
    }

    Wektor8 Kolumna_j(unsigned int j) const
    {
        assert(j > 0);
        assert(j <= rozmiar);

        return macierz[j-1];
    }

    Wektor8 & Kolumna_j(unsigned int j)
    {
        assert(j > 0);
        assert(j <= rozmiar);

        return macierz[j-1];
    }

    Wektor8 Wiersz_i(unsigned int i) const
    {
        assert(i > 0);
        assert(i <= rozmiar);

        Wektor8 wiersz;
        Wektor8 kolumna;

        for(unsigned int k = 1; k <= rozmiar; ++k)
        {
            kolumna = macierz[k - 1];
            wiersz.ustaw_wartosc(k,kolumna[i]);
            //wiersz[k] = kolumna[i];
        }

        return wiersz;
    }

    Macierz8& operator+=(const Macierz8& m)
    {
        for(unsigned int i = 0; i < rozmiar; ++i)
        {
            macierz[i] += m.macierz[i];
        }

        return *this;
    }

    Macierz8& operator-=(const Macierz8& m)
    {
        for(unsigned int i = 0; i < rozmiar; ++i)
        {
                macierz[i] -= m.macierz[i];
        }

        return *this;
    }

};

Macierz8 operator+(const Macierz8& m1, const Macierz8& m2)
{
    Macierz8 m(m1);
    return m += m2;
}

Macierz8 operator-(const Macierz8& m1, const Macierz8& m2)
{
    Macierz8 m(m1);
    return m -= m2;
}

Macierz8 operator*(const Macierz8& m1, const Macierz8& m2)
{
    Macierz8 iloczyn;
    Wektor8 kol;

    for(unsigned int i = 1; i <= m1.Rozmiar_Macierzy(); ++i)
    {
        for(unsigned int j = 1; j <= m2.Rozmiar_Macierzy(); ++j)
        {
            kol.ustaw_wartosc(j, iloczyn_skalarny(m1.Wiersz_i(j), m2.Kolumna_j(i)));
        }

        iloczyn.Kolumna_j(i) = kol;
    }

    return iloczyn;
}

bool operator==(const Macierz8 m1, const Macierz8 m2)
{
    assert(m1.Rozmiar_Macierzy() == m2.Rozmiar_Macierzy());

    for(unsigned int i = 1; i <= m1.Rozmiar_Macierzy(); ++i)
    {
        for(unsigned int j = 1; j <= m1.Rozmiar_Macierzy(); ++j)
        {
            if(m1[{i,j}] != m2[{i,j}])
                return false;
        }

    }
	return true;
}

Wektor8 operator*(const Macierz8& m, const Wektor8& v)
{
    assert(m.Rozmiar_Macierzy() == v.Rozmiar_Wektora());

    Wektor8 kol;

    for(unsigned int i = 1; i <= m.Rozmiar_Macierzy(); ++i)
    {
        kol.ustaw_wartosc(i, iloczyn_skalarny(m.Wiersz_i(i), v));
    }

    return kol;
}

void testy(void)
{
    Wektor8 v1({2.1,1.2,3.4,6.7,8.9,6.8,9.0,6.4});
    Wektor8 v2({2.1,3.4,6.7,8.9,6.8,9.0,6.4});
    Wektor8 v3({2.1,1.2,3.4,6.7,8.9,6.8,9.0,6.4});
    Wektor8 v4({2.1,1.2,3.12,6.0,8.9,-1.8,9.0,6.4});
    Wektor8 v5({2.1,1.2,3.4,4.7,8.9,6.8,6.4});
    Wektor8 v6({2.1,11.2,3.4,6.7,8.9,6.8,1.3,9.0});
    Wektor8 v7({2.1,1.2,3.4,6.7,8.9,2.8,9.0,6.4});
    Wektor8 v8({2.1,1.2,3.7,8.9,6.8,-9.0,6.4});
    std::vector<double> j(8,1.0);
    Macierz8 m1({v1,v2,v3,v4,v5,v6,v7});
    Macierz8 m2({j,j,j,j,j,j,j,j});

    assert(v1[1] == 2.1);
    assert(v2[8] == 0.0);
    assert(iloczyn_skalarny(v2,v3) == 270.22);

    assert((m1[{6,2}] == 9.0));
    assert((m1[{8,2}] == 0.0));
    assert(m1.Kolumna_j(3) == v3);
    assert(m1.Wiersz_i(3) == Wektor8({3.4,6.7,3.4,3.12,3.4,3.4,3.4,0.0}));

    Wektor8 v9 = v1 + v2;
    v1 += v2;
    assert(v1[1] == 4.2);
    assert(v1 == v9);

    v9 = v1 - v2;
    v1 -= v2;
    assert(v1[1] == 2.1);
    assert(v1 == v9);

    Macierz8 m = m1 + m2;

    Wektor8 w1({3.1,2.2,4.4,7.7,9.9,7.8,10.0,7.4});
    Wektor8 w2({3.1,4.4,7.7,9.9,7.8,10.0,7.4,1.0});
    Wektor8 w3({3.1,2.2,4.4,7.7,9.9,7.8,10.0,7.4});
    Wektor8 w4({3.1,2.2,4.12,7.0,9.9,-0.8,10.0,7.4});
    Wektor8 w5({3.1,2.2,4.4,5.7,9.9,7.8,7.4,1.0});
    Wektor8 w6({3.1,12.2,4.4,7.7,9.9,7.8,2.3,10.0});
    Wektor8 w7({3.1,2.2,4.4,7.7,9.9,3.8,10.0,7.4});
    Wektor8 w8({3.1,2.2,4.7,9.9,7.8,-8.0,7.4,1.0});

    Macierz8 m3({w1,w2,w3,w4,w5,w6,w7,j});
    m2+=m1;

    assert(m == m3);
    assert(m == m2);

    m2 -= m1;
    assert(m3 - m1 == m2);

    Wektor8 a1({  1.0,  2.0,  4.0,  7.0,  9.0,  7.0, 10.0,  7.0 });
    Wektor8 a2({  2.0,  1.0,  7.0,  9.0,  7.0, 10.0,  7.0,  1.0 });
    Wektor8 a3({  9.0,  2.0,  4.0,  7.0,  0.0,  7.0, 10.0,  7.0 });
    Wektor8 a4({  2.0,  5.0,  2.0,  7.0, -9.0, -8.0, 10.0,  7.0 });
    Wektor8 a5({  3.0,  2.0,  4.0,  3.0,  9.0,  6.0,  7.0,  4.0 });
    Wektor8 a6({  7.0,  1.0,  5.0,  7.0, -2.0,  7.0,  2.0, 10.0 });
    Wektor8 a7({  3.0,  2.0,  1.0,  7.0,  7.0,  3.0, 10.0,  7.0 });
    Wektor8 a8({  2.0,  5.0,  4.0,  9.0,  8.0, -8.0,  7.0,  1.0 });

    Wektor8 b1({  3.0,  2.0,  4.0, -7.0,  9.0,  7.0, 10.0,  7.0 });
    Wektor8 b2({  3.0,  4.0,  7.0,  9.0,  7.0, 10.0,  7.0,  1.0 });
    Wektor8 b3({ -3.0,  2.0,  4.0,  7.0,  9.0,  7.0, 10.0,  7.0 });
    Wektor8 b4({  3.0,  2.0,  4.0,  0.0,  9.0, -0.0, 10.0,  7.0 });
    Wektor8 b5({  3.0, -2.0, -4.0,  4.0,  9.0,  7.0,  7.0,  4.0 });
    Wektor8 b6({  3.0,  1.0,  4.0,  7.0,  9.0,  7.0,  2.0, 10.0 });
    Wektor8 b7({ -3.0,  2.0,  4.0,  7.0,  9.0,  3.0, 10.0,  7.0 });
    Wektor8 b8({  3.0,  2.0, -4.0,  9.0,  7.0, -8.0,  7.0,  1.0 });


    Wektor8 c1({ 149,  61, 137, 227, 297, 202, 240, 185 });
    Wektor8 c2({ 206, 112, 175, 318,  74, 163, 364, 315 });
    Wektor8 c3({ 171, 119, 141, 283, 117,  48, 320, 241 });
    Wektor8 c4({ 114,  89, 116, 227, 248,  97, 296, 164 });
    Wektor8 c5({  76,  75,  84, 164, 125,  33, 191, 178 });
    Wektor8 c6({ 157, 129, 162, 287, 132,  32, 314, 229 });
    Wektor8 c7({ 143, 115, 121, 255, 125,  20, 312, 201 });
    Wektor8 c8({ -23,  70,  27,  97,  96, -60, 204,  56 });

/*
    Wektor8 c1({ 149, 206, 171, 114,  76, 157, 143, -23 });
    Wektor8 c2({  61, 112, 119,  89,  75, 129, 115,  70 });
    Wektor8 c3({ 137, 175, 141, 116,  84, 162, 121,  27 });
    Wektor8 c4({ 227, 318, 283, 227, 164, 287, 255,  97 });
    Wektor8 c5({ 297,  74, 117, 248, 125, 132, 125,  96 });
    Wektor8 c6({ 202, 163,  48,  97,  33,  32,  20, -60 });
    Wektor8 c7({ 240, 364, 320, 296, 191, 314, 312, 204 });
    Wektor8 c8({ 185, 315, 241, 164, 178, 229, 201,  56 });
    */

    Wektor8 ckol1({ 149, 61, 137, 227,  297, 202, 240, 185});

    Macierz8 a({a1,a2,a3,a4,a5,a6,a7,a8});
    Macierz8 b({b1,b2,b3,b4,b5,b6,b7,b8});
    Macierz8 c({c1,c2,c3,c4,c5,c6,c7,c8});

    assert(a * b1 == ckol1);
    assert(a * b == c);

    std::cerr << "Program pomyslnie przeszedl testy. \n" << std::endl;
}

int main(void)
{
    testy();

    Wektor8 a1({  1.0,  2.0,  4.0,  7.0,  9.0,  7.0, 10.0,  7.0 });
    Wektor8 a2({  2.0,  1.0,  7.0,  9.0,  7.0, 10.0,  7.0,  1.0 });
    Wektor8 a3({  9.0,  2.0,  4.0,  7.0,  0.0,  7.0, 10.0,  7.0 });
    Wektor8 a4({  2.0,  5.0,  2.0,  7.0, -9.0, -8.0, 10.0,  7.0 });
    Wektor8 a5({  3.0,  2.0,  4.0,  3.0,  9.0,  6.0,  7.0,  4.0 });
    Wektor8 a6({  7.0,  1.0,  5.0,  7.0, -2.0,  7.0,  2.0, 10.0 });
    Wektor8 a7({  3.0,  2.0,  1.0,  7.0,  7.0,  3.0, 10.0,  7.0 });
    Wektor8 a8({  2.0,  5.0,  4.0,  9.0,  8.0, -8.0,  7.0,  1.0 });

    Wektor8 b1({  3.0,  2.0,  4.0, -7.0,  9.0,  7.0, 10.0,  7.0 });
    Wektor8 b2({  3.0,  4.0,  7.0,  9.0,  7.0, 10.0,  7.0,  1.0 });
    Wektor8 b3({ -3.0,  2.0,  4.0,  7.0,  9.0,  7.0, 10.0,  7.0 });
    Wektor8 b4({  3.0,  2.0,  4.0,  0.0,  9.0, -0.0, 10.0,  7.0 });
    Wektor8 b5({  3.0, -2.0, -4.0,  4.0,  9.0,  7.0,  7.0,  4.0 });
    Wektor8 b6({  3.0,  1.0,  4.0,  7.0,  9.0,  7.0,  2.0, 10.0 });
    Wektor8 b7({ -3.0,  2.0,  4.0,  7.0,  9.0,  3.0, 10.0,  7.0 });
    Wektor8 b8({  3.0,  2.0, -4.0,  9.0,  7.0, -8.0,  7.0,  1.0 });

    Macierz8 a({a1,a2,a3,a4,a5,a6,a7,a8});
    Macierz8 b({b1,b2,b3,b4,b5,b6,b7,b8});
    Macierz8 c = a * b;
    Wektor8 kol = a * b1;
    Wektor8 wier = a.Wiersz_i(1);


    for(unsigned int i = 1; i <= 8; ++i)
    {
        std::cout << wier[i] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Teraz wektor: " << std::endl;

    for(int i = 1; i <= 8; ++i)
    {
        std::cout << kol[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Teraz macierz: " << std::endl;

    for(unsigned int i = 1; i <= 8; ++i) {
        for(unsigned int j = 1; j <= 8; ++j) {
            std::cout << c[{i,j}] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
