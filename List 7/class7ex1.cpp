/*Napisz funkcje, ktora dla dwoch obiektow reprezentujacych daty kalendarza gregorianskiego policzy liczbe dni pomiedzy nimi.
Przetestuj i zademonstruj.
(*) Napisz teraz te funkcje tak, aby wynik byl otrzymywany przy pomocy odejmowania,
tzn. jezeli d oraz s sa datami to wyrazenie d - s ma wartosc równa ilosci dni.*/

#include <iostream>
#include <cassert>


bool przestepny(int rok)
{
   return ((rok%4 == 0 && rok%100 != 0) || rok%400 == 0);
}

bool poprawna_data(int dzien, int miesiac, int rok)
{
    if(rok > 1582)
    {
        if (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 12)
        {
            if (dzien > 0 && dzien < 32)
                return true;
        }
        else
        {
            if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11)
            {
                if(dzien > 0 && dzien < 31)
                    return true;
            }
            if (miesiac == 2)
            {
                if (przestepny(rok))
                {
                    if(dzien > 0 && dzien < 30)
                        return true;
                }
                else
                {
                    if(dzien > 0 && dzien < 29)
                        return true;
                }
            }
        }
    }

    return false;
}

struct Data
{
    int rok;
    int miesiac;
    int dzien;

    Data ( int d, int m,int r)
    {
        assert(poprawna_data(d,m,r));
        rok = r;
        miesiac = m;
        dzien = d;
    }
};

int liczba_dni_miesiaca(int miesiac, int rok)
{
    assert(miesiac > 0);
    assert(miesiac < 13);
    assert(rok > 1582);

    if (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 12)
    {
        return 31;
    }
    else
    {
        if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11)
        {
            return 30;
        }
        else
        {
            if (przestepny(rok))
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
    }
}

int odejmowanie_dat(Data d, Data t)
{
    int liczba_dni = 0;
    int r_r = d.rok - t.rok;
    int r_m = d.miesiac - t.miesiac;
    int r_d = d.dzien - t.dzien;

    if(r_r == 0)
    {
        if(r_m == 0)
        {
            if(r_d >= 0)
                liczba_dni = r_d;
            else
                liczba_dni = -r_d;
        }
        else
        {
            if(r_m > 0)
                std::swap(d,t);

            liczba_dni = liczba_dni_miesiaca(d.miesiac,d.rok)-d.dzien;

            for(int i = d.miesiac + 1; i < t.miesiac; ++i)
            {
                liczba_dni += liczba_dni_miesiaca(i,d.rok);
            }

            liczba_dni += t.dzien;
        }
    }
    else
    {
        if(r_r > 0)
            std::swap(d,t);

        liczba_dni = liczba_dni_miesiaca(d.miesiac,d.rok)-d.dzien;

        for(int i = d.miesiac + 1; i < 13; ++i)
        {
            liczba_dni += liczba_dni_miesiaca(i,d.rok);
        }

        for(int j = d.rok + 1; j < t.rok; ++j)
        {
            if(przestepny(j))
                liczba_dni += 366;
            else
                liczba_dni += 365;
        }

        for(int k = 1; k < t.miesiac; ++k)
        {
            liczba_dni += liczba_dni_miesiaca(k,t.rok);
        }

        liczba_dni += t.dzien;

    }
    return liczba_dni;
}

int operator-(Data d, Data t)
{
    return odejmowanie_dat(d,t);
}

void testy(void)
{
    assert(liczba_dni_miesiaca(2,2000) == 29);

    assert(poprawna_data(13,9,1993) == 1);
    assert(poprawna_data(29,2,2001) == 0);

    assert(odejmowanie_dat(Data(13,9,2000),Data(12,1,1993)) == 2801);
    assert(odejmowanie_dat(Data(12,1,1993),Data(13,9,2000)) == 2801);
    assert(odejmowanie_dat(Data(12,1,1993),Data(13,9,2000)) == Data(12,1,1993) - Data(13,9,2000));
    assert(odejmowanie_dat(Data(1,1,2001),Data(1,3,2001)) == 59);
    assert(odejmowanie_dat(Data(18,4,2001),Data(22,4,2001)) == 4);
    assert(odejmowanie_dat(Data(19,10,1993),Data(19,10,1993)) == 0);

    std::cerr << "Program pomyslnie przeszedl testy \n";
}

int main(void)
{
    testy();

    Data data(19,10,1993);
    Data tata(12,4,2014);

    std::cout << odejmowanie_dat(tata, data) << std::endl;
    std::cout << odejmowanie_dat(data, tata) << std::endl;

    std::cout << tata - data << std::endl;
    std::cout << data - tata << std::endl;

    return 0;
}
