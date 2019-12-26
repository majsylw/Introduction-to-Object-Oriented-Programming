/*
Znajdź w sieci informacje o cyfrze kontrolnej i kodowaniu płci w numerze PESEL. 
Napisz funkcję, która sprawdzi, czy data urodzenia zawarta w numerze przekazanym jako napis jest sensowna, 
i która zwróci stosowną wartość logiczną. Napisz drugą funkcję, która sprawdzi, 
czy cyfra kontrolna zawarta w numerze również przekazanym jako napis jest poprawna, 
i która zwróci stosowną wartość logiczną.

Zdefiniuj klasę PESEL reprezentującą numery PESEL. Wyposaż ją w konstruktor przyjmujący napis. 
Upewnij się w konstruktorze, że data zawarta w przekazanym napisie jest sensowna, 
natomiast nie wymagaj poprawnej cyfry kontrolnej.

Wyposaż obiekty tej klasy w metody:

Numer zwracającą cały numer jako napis
-DataUrodzenia zwracającą datę urodzenia zakodowaną w numerze
-CzyKobieta zwracającą wartość logiczną odpowiadającą na zadane pytanie
- CzyPoprawny zwracającą wartość logiczną informującą czy cyfra kontrolna jest poprawna
Napisz operator wyjścia oraz operator wejścia dla obiektów tej klasy. 
Spróbuj napisać operator wejścia w taki sposób, aby jako poprawne wejście odczytywać kolejne 11 cyfr 
(tzn. ciąg cyfr krótszy powinien być rozumiany jako niewłaściwy, a w przypadku dłuższego operator 
powinien zdjąć ze strumienia pierwszych 11 cyfr a pozostałe zostawić i pozwolić ewentualnej 
kolejnej operacji wczytywania z tego samego strumienia na ich interpretację).

Napisz funkcję, która zapyta użytkownika konsoli o PESEL, podejmie próbę wczytania go, 
i w przypadku niepowodzenia (złe litery lub zła data) ponowi próbę, a w przypadku złej cyfry kontrolnej zapyta, 
czy użytkownik na pewno taki ma przydzielony, i pozwoli mu albo na potwierdzenie albo na ponowienie próby.

Napisz testy wszystkich funkcji, które do testów się nadają.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

bool przestepny(int rok)
{
    return ((rok%4 == 0 && rok%100 != 0) || rok%400 == 0);
}

bool poprawna_data(int dzien, int miesiac, int rok)
{
    if(rok > 1899)
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


bool poprawna_data_w_PESEL(std::string pesel)
{
    for(int i = 0; i < 10; ++i)
    {
        if(pesel[i] < '0' || pesel[i] > '9')
            return false;
    }

    std::string rok = pesel.substr(0,2);
    std::istringstream przypis_roku(rok);
    int rok_liczba = 0;
    przypis_roku >> rok_liczba;

    std::string miesiac = pesel.substr(2,2);

    std::string dzien = pesel.substr(4,2);
    std::istringstream strumien_dnia(dzien);
    int dzien_liczba = 0;
    strumien_dnia >> dzien_liczba;

    if(miesiac[0] == '0' || miesiac[0] == '1')
        rok_liczba += 1900;
    if(miesiac[0] == '2' || miesiac[0] == '3')
        rok_liczba += 2000;
    if(miesiac[0] == '4' || miesiac[0] == '5')
        rok_liczba += 2100;
    if(miesiac[0] == '6' || miesiac[0] == '7')
        rok_liczba += 2200;
    if(miesiac[0] == '8' || miesiac[0] == '9')
        rok_liczba += 2300;

    if(miesiac[0]%2 == 0)
        miesiac[0] = '0';
    else
        miesiac[0] = '1';

    std::istringstream strumien_miesiaca(miesiac);
    int miesiac_liczba = 0;
    strumien_miesiaca >> miesiac_liczba;

    return(poprawna_data(dzien_liczba,miesiac_liczba,rok_liczba));
}

bool poprawna_cyfra_kontrolna(std::string pesel)
{
    int suma = pesel[0]+3*pesel[1]+7*pesel[2]+9*pesel[3]+pesel[4]+3*pesel[5]+7*pesel[6]+9*pesel[7]+pesel[8]+3*pesel[9]+pesel[10];
    return (suma%10 == 0);
}

struct Data
{
    int rok;
    int miesiac;
    int dzien;

    Data (void)
    {
        rok = 1582;
        miesiac = 1;
        dzien = 1;
    }

    Data (int r, int m,int d)
    {
        assert(poprawna_data(d,m,r));
        rok = r;
        miesiac = m;
        dzien = d;
    }

};

std::istream& operator>>(std::istream& wejscie, Data& d)
{
    int ro = 0;
    int mi = 0;
    int dz = 0;

    wejscie >> ro >> mi >> dz;

    if(wejscie)
    {
        if(poprawna_data(ro,mi,dz))
            d = Data(ro,mi,dz);
        else
            wejscie.setstate(std::ios_base::failbit);
    }

    return wejscie;
}

std::ostream& operator<<(std::ostream& wyjscie, Data d)
{
    return wyjscie << d.rok << "." << d.miesiac << "." << d.dzien;
}

bool operator==(Data d, Data t)
{
	return (t.dzien == d.dzien && t.miesiac == d.miesiac && t.rok == d.rok);
}

Data NrPesel(std::string pesel)
{
    Data data_urodzenia(1999,1,1);

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

class PESEL
{
    std::string nr_pesel;

public:
    PESEL(std::string pesel)
    {
        assert(poprawna_data_w_PESEL(pesel));

        nr_pesel = pesel;
    }

    std::string Numer(void) const
    {
        return nr_pesel;
    }

    std::string DataUrodzenia(void)
    {
        std::string rok = nr_pesel.substr(0,2);

        std::string miesiac = nr_pesel.substr(2,2);

        std::string dzien = nr_pesel.substr(4,2);

        if(miesiac[0] == '0' || miesiac[0] == '1')
            rok =  "19" + rok;
        if(miesiac[0] == '2' || miesiac[0] == '3')
            rok = "20" + rok;
        if(miesiac[0] == '4' || miesiac[0] == '5')
            rok = "21" + rok;
        if(miesiac[0] == '6' || miesiac[0] == '7')
            rok = "22" + rok;
        if(miesiac[0] == '8' || miesiac[0] == '9')
            rok = "23" + rok;

        if(miesiac[0]%2 == 0)
            miesiac[0] = '0';
        else
            miesiac[0] = '1';

        std::ostringstream data;
        data << dzien << '.' << miesiac << '.' << rok << "r.";
        return data.str();
    }

    Data Data_ur(void)
    {
        return NrPesel(nr_pesel);
    }


    bool CzyKobieta(void)
    {
        int cyfra = nr_pesel[9];
        return (cyfra%2 == 0);
    }

    bool CzyPoprawny(void)
    {
        return poprawna_cyfra_kontrolna(nr_pesel);
    }

};

std::istream& operator>>(std::istream& wejscie, PESEL& p)
{
    std::string pesel;

    wejscie >> pesel;

    if(wejscie)
    {
        if(pesel.size() >= 11)
        {
            pesel = pesel.substr(0,11);

            if(poprawna_data_w_PESEL(pesel))
                p = PESEL(pesel);
            else
                wejscie.setstate(std::ios_base::failbit);
        }
        else
            wejscie.setstate(std::ios_base::failbit);
    }

    return wejscie;
}

std::ostream& operator<<(std::ostream& wyjscie, PESEL p)
{
    return wyjscie << "Podany nr PESEL: " << p.Numer();
}

PESEL Podaj_Pesel(void)
{
    std::string sprawdzenie;
    PESEL pes("");
    bool odpowiedz = false;
    bool odp = false;

    std::cout << "Podaj Pesel: ";

    do
    {
        odpowiedz = true;
        std::getline(std::cin,sprawdzenie);
        std::istringstream wejscie(sprawdzenie);

        wejscie >> pes;

        odpowiedz = wejscie;

        if(!wejscie)
        {
           std::cout << "\nPopelniono blad. Podaj ponownie pesel: ";
        }
        else
        {
            if(pes.CzyPoprawny() == false)
            {
                std::cout << "\nPodany pesel ma zla cyfre kontrolna. Jestes pewien, ze dobrze go wprowdzailes? (Wpisz 0-nie lub 1-tak)\n";
                std::cin >> odp;
                if(odp == false)
                {
                    odpowiedz = odp;
                }
            }
        }
    }
    while(odpowiedz == false);

    return pes;
}

void testy(void)
{
    PESEL g("71312502431");
    PESEL s("98091991938");

    assert(poprawna_data_w_PESEL("71312502481") == true);
    assert(poprawna_data_w_PESEL("71022902481") == false);

    assert(poprawna_cyfra_kontrolna("98091991938") == true);
    assert(poprawna_cyfra_kontrolna("71312502481") == false);

    assert(g.CzyPoprawny() == false);
    assert(s.CzyPoprawny() == true);

    assert(g.CzyKobieta() == false);
    assert(s.CzyKobieta() == true);

    assert(s.DataUrodzenia() == "19.09.1998r.");
    assert(g.DataUrodzenia() == "25.11.2071r.");

    assert(s.Data_ur() == Data(1998,9,19));
    assert(g.Data_ur() == Data(2071,11,25));

    assert(g.Numer() == "71312502431");
    assert(s.Numer() == "98091991938");

    std::cerr << "Program pomyslnie przeszedl testy. \n";
}

int main(void)
{
    testy();
    PESEL s("71112502481");
    PESEL g("98091991938");
    PESEL n("65123076430");

    std::cout << s.CzyKobieta() << std::endl;

    std::cout << g.Data_ur() << std::endl;

    std::cout << Podaj_Pesel();

    std::cin.get();
    std::cout << std::endl;
    std::cin.get();
    return 0;
}
