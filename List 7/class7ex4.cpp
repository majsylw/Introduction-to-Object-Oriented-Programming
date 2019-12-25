/*
O numerze PESEL wiadomo, że:
     Nasz pesel składa się z 11 cyfr. Sześć pierwszych to data 
urodzenia, natomiast pozostała kombinacja pięciu cyfr oznacza m.in. 
naszą płeć. Pesel urodzonych 1 stycznia 1900 roku zaczyna się od cyfr 00 
01 01. Czy istnieje zatem - choćby teoretyczna - możliwość, że urodzeni 
w pierwszy dzień 2000 roku będą mieć taki sam pesel jak osoby urodzone 
wiek wcześniej? - Taka sytuacja jest możliwa - twierdzi naczelnik 
Benczyński. - Dlatego osobom urodzonym w następnym stuleciu cyfrę z 
pierwszego "okienka" oznaczającego miesiąc urodzenia będziemy sumować z 
cyfrą 2, w kolejnym stuleciu z cyfrą 4 itd. 

     Pesel urodzonych 1 stycznia 2000 roku zaczynać się będzie od cyfr 
00 21 01, 31 grudnia 2000 roku - 00 32 31, 1 stycznia 2100 roku - 00 41 
01, 31 grudnia 2100 roku - 00 52 31 i analogicznie 1 stycznia 2300 - 00 
81 01, 31 grudnia 2399 roku - 99 92 31. 

     Do tego czasu nasi potomkowie będą mieć niepowtarzalny pesel. Co 
się stanie w 2400 roku? - O to niech się martwią następne pokolenia - 
mówią w ministerstwie.
Napisz funkcję, która dla zadanego numeru PESEL wyprodukuje obiekt typu Data 
reprezentujący datę urodzenia z niego odczytaną. Wyposaż klasę Data 
w operator wyjścia, który pozwoli wypisać datę w formacie "28 czerwca 2010". 
Przetestuj na powyższych przykładach.
*/


#include <iostream>
#include <cassert>
#include <string>
#include <sstream>

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
    if(miesiac == 9)
        return "wrzesnia";
    if(miesiac == 10)
        return "pazdziernika";
    if(miesiac == 11)
        return "listopada";
    else
        return "grudnia";
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

std::ostream& operator<<(std::ostream& wyjscie, Data d)
{
    wyjscie << d.dzien << " " << jaki_miesiac(d.miesiac) << " " << d.rok;
    return wyjscie;
}

Data nr_pesel(std::string pesel)
{
    assert(pesel.size() == 11);

    Data data_urodzenia(1,1,1970);

    std::string rok = pesel.substr(0,2);
    std::istringstream przypis_roku(rok);

    int rok_liczba = 0;
    przypis_roku >> rok_liczba;

    if(przypis_roku)
    {
        data_urodzenia.rok = rok_liczba;
    }

    switch(pesel[2])
    {
        case '0':
            data_urodzenia.rok += 1900;
            break;
        case '1':
            data_urodzenia.rok += 1900;
            break;
        case '2':
            data_urodzenia.rok += 2000;
            break;
        case '3':
            data_urodzenia.rok += 2000;
            break;
        case '4':
            data_urodzenia.rok += 2100;
            break;
        case '5':
            data_urodzenia.rok += 2100;
            break;
        case '6':
            data_urodzenia.rok += 2200;
            break;
        case '7':
            data_urodzenia.rok += 2200;
            break;
        case '8':
            data_urodzenia.rok += 2300;
            break;
        case '9':
            data_urodzenia.rok += 2300;
            break;
        default:
            std::cout << "Podano bledny pesel!" << std::endl;
            break;

    }

    std::string miesiac = pesel.substr(2,2);
    if(miesiac[0]%2 == 0)
    {
        miesiac[0] = '0';
    }
    else
    {
        miesiac[0] = '1';
    }

    std::istringstream przypis_miesiaca(miesiac);

    int miesiac_liczba = 0;
    przypis_miesiaca >> miesiac_liczba;

    if(przypis_miesiaca)
    {
        data_urodzenia.miesiac = miesiac_liczba;
    }

    std::string dzien = pesel.substr(4,2);
    std::istringstream przypis_dnia(dzien);

    int dzien_liczba = 0;
    przypis_dnia >> dzien_liczba;

    if(przypis_dnia)
    {
        data_urodzenia.dzien = dzien_liczba;
    }

    return data_urodzenia;
}

bool operator==(Data d, Data t)
{
	return (t.dzien == d.dzien && t.miesiac == d.miesiac && t.rok == d.rok);
}

void testy2(void)
{
    assert(nr_pesel("00210176549") == Data(1,1,2000));
    assert(nr_pesel("00323100254") == Data(31,12,2000));
    assert(nr_pesel("00410102117") == Data(1,1,2100));
    assert(nr_pesel("00523132353") == Data(31,12,2100));
    assert(nr_pesel("00810176309") == Data(1,1,2300));
    assert(nr_pesel("99923104101") == Data(31,12,2399));

    std::cerr << "Kolejne testy wykonaly sie poprawnie. \n";
}

void testy1(void)
{
    std::ostringstream data;
    data.str("");
    data << nr_pesel("00210176549");
    assert(data.str() == "1 stycznia 2000");
    data.str("");
    data << nr_pesel("00323100254");
    assert(data.str() == "31 grudnia 2000");
    data.str("");
    data << nr_pesel("00410102117");
    assert(data.str() == "1 stycznia 2100");
    data.str("");
    data << nr_pesel("00523132353");
    assert(data.str() == "31 grudnia 2100");
    data.str("");
    data << nr_pesel("00810176309");
    assert(data.str() == "1 stycznia 2300");
    data.str("");
    data << nr_pesel("99923104101");
    assert(data.str() == "31 grudnia 2399");

    std::cerr << "Pierwsze testy wykonaly sie poprawnie. \n";
}

int main(void)
{
    testy1();
    testy2();

    Data d(5,12,2013);
    std::cout << d << std::endl;

    std::cout << nr_pesel("94021991124") << std::endl;

    return 0;
}
