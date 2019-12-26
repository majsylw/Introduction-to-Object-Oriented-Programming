/*
Zdefiniuj klasę Osoba, która będzie modelować informacje o imionach, nazwisku i dacie urodzenia danej osoby. 
Wyposaż ją w konstruktory przyjmujące datę urodzenia pod postacią obiektu stosownego typu oraz trzy napisy, 
nazwisko i jeden lub dwa reprezentujące imiona (przyjmujemy, że jeżeli argument odpowiadający drugiemu imieniu 
jest napisem pustym, to oznacza to brak drugiego imienia). Wszystkie atrybuty obiektów klasy powinny być prywatne. 
Wyposaż klasę w metody:
-IleImion zwracającą 1 lub 2 w zależności od ilości imion,
-Imie zwracającą napis zawierający pierwsze imię,
-Imiona zwracającą napis zawierający imiona, lub tylko pierwsze imię, jeżeli nie ma drugiego,
-Nazwisko zwracającą napis zawierający nazwisko
-ImionaINazwisko zwracającą napis zawierający pełne imiona i nazwisko
-InicjalyINazwisko zwracającą napis zawierający inicjały (inicjał) i nazwisko
-DataUrodzenia zwracającą datę urodzenia
-Wiek zwracającą wiek osoby w dniu określonym datą przekazaną w parametrze.
Klasa powinna przejść następujące testy:
void test_Osoba(void)
  {
  Osoba jkw(Data(1922,2,24), "Wscieklica", "Jan", "Karol");
  assert(jkw.IleImion()==2);
  assert(jkw.Imie()=="Jan");
  assert(jkw.Imiona()=="Jan Karol");
  assert(jkw.Nazwisko()=="Wscieklica");
  assert(jkw.ImionaINazwisko()=="Jan Karol Wscieklica");
  assert(jkw.InicjalyINazwisko()=="J. K. Wscieklica");
  assert(jkw.DataUrodzenia()==Data(1922,2,24));
  assert(jkw.Wiek(Data(2014,4,16))==92);

  const Osoba aa(Data(2013,4,16), "Abacki", "Adam");
  assert(aa.IleImion()==1);
  assert(aa.Imie()=="Adam");
  assert(aa.Imiona()=="Adam");
  assert(aa.Nazwisko()=="Abacki");
  assert(aa.ImionaINazwisko()=="Adam Abacki");
  assert(aa.InicjalyINazwisko()=="A. Abacki");
  assert(aa.DataUrodzenia()==Data(2013,4,16));
  assert(aa.Wiek(Data(2013,12,31))==0);
  assert(aa.Wiek(Data(2014,4,16))==1);
  }
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>


bool przestepny(int rok)
{
    //assert(rok >= 1582);

    return ((rok%4 == 0 && rok%100 != 0) || rok%400 == 0);
}

bool poprawna_data(int rok, int miesiac, int dzien)
{
    /*assert(rok >= 1582);
    assert(miesiac > 0);
    assert(miesiac < 13);
    assert(dzien > 0);
    assert(dzien <= 31);*/


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

    return false;
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
        assert(poprawna_data(r,m,d));
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

class Osoba
{
    Data data_urodzenia_;
    std::string nazwisko_;
    std::string pierwsze_imie_;
    std::string drugie_imie_;

    public:

    Osoba (Data data_urodzenia, std::string nazwisko, std::string pierwsze_imie, std::string drugie_imie = "")
    {
        data_urodzenia_ = data_urodzenia;

        pierwsze_imie_ = pierwsze_imie;

        drugie_imie_ = drugie_imie;

        nazwisko_ = nazwisko;
    }

    int IleImion(void) const
    {
        if(drugie_imie_.size() != 0)
            return 2;
        else
            return 1;
    }

    std::string Imie(void) const
    {
        return pierwsze_imie_;
    }

    std::string Imiona(void) const
    {
        if(drugie_imie_.size() != 0)
        {
            return pierwsze_imie_ + ' ' + drugie_imie_;
        }
        else
            return pierwsze_imie_;
    }

    std::string Nazwisko(void) const
    {
        return nazwisko_;
    }

    std::string ImionaINazwisko(void) const
    {
        std::string dane = pierwsze_imie_ + ' ';

        if(drugie_imie_ != "")
            dane += drugie_imie_ + ' ';

        dane += nazwisko_;

        return dane;
    }

    std::string InicjalyINazwisko(void) const
    {
        std::ostringstream napis;
        napis << pierwsze_imie_[0] << ". ";

        if(drugie_imie_ != "")
            napis << drugie_imie_[0] << ". ";

        napis << nazwisko_;

        return napis.str();
    }

    Data DataUrodzenia(void) const
    {
        return data_urodzenia_;
    }

    int Wiek(Data d) const
    {
        return d.rok - data_urodzenia_.rok;
    }

};


void test_Osoba(void)
{
  Osoba jkw(Data(1922,2,24), "Wscieklica", "Jan", "Karol");
  assert(jkw.IleImion()==2);
  assert(jkw.Imie()=="Jan");
  assert(jkw.Imiona()=="Jan Karol");
  assert(jkw.Nazwisko()=="Wscieklica");
  assert(jkw.ImionaINazwisko()=="Jan Karol Wscieklica");
  assert(jkw.InicjalyINazwisko()=="J. K. Wscieklica");
  assert(jkw.DataUrodzenia()==Data(1922,2,24));
  assert(jkw.Wiek(Data(2014,4,16))==92);

  const Osoba aa(Data(2013,4,16), "Abacki", "Adam");
  assert(aa.IleImion()==1);
  assert(aa.Imie()=="Adam");
  assert(aa.Imiona()=="Adam");
  assert(aa.Nazwisko()=="Abacki");
  assert(aa.ImionaINazwisko()=="Adam Abacki");
  assert(aa.InicjalyINazwisko()=="A. Abacki");
  assert(aa.DataUrodzenia()==Data(2013,4,16));
  assert(aa.Wiek(Data(2013,12,31))==0);
  assert(aa.Wiek(Data(2014,4,16))==1);

  std::cerr << "Program pomyslnie przeszedl testy. \n";
}

int main()
{
    test_Osoba();

    Osoba ja(Data(1993,10,19), "Majchrowska", "Sylwia");

    std::cout << "Dane osobowe \n";
    std::cout << "Pierwsze imie: " << ja.Imie() << "\nWszystkie imiona: " << ja.Imiona() << "\nNazwisko: " << ja.Nazwisko() << "\n";
    std::cout << "Lacznie: " << ja.ImionaINazwisko() << "\nInicialy: " << ja.InicjalyINazwisko() << "\n";
    std::cout << "Data urodzenia: " << ja.DataUrodzenia() << std::endl;
    std::cout << "Wiek: " << ja.Wiek(Data(2014,5,1));

    return 0;
}
