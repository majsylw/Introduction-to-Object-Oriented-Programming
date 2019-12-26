/*
Plik ORANGEPL.mst (Ÿród³o: bossa.pl) zawiera kurs akcji spó³ki orange (dawniej tpsa) od pocz¹tku jej pojawienia siê 
na gie³dzie do wczoraj. Plik ten zawiera wiersz nag³ówka, a pod nim, w kolumnach, ró¿ne dane, z których bêdzie nas 
interesowaæ jedynie data notowania oraz cena zamkniêcia (CLOSE).
Daty w tym pliku s¹ zapisane w specyficzny sposób, ale po wczytaniu chcemy do dalszych operacji przekonwertowaæ to, 
co wczytamy z pliku na liczby zmiennopozycyjne, w których czêœæ ca³kowita odpowiada rokowi, a czêœæ u³amkowa odpowiada 
godzinie 24:00:00 danego dnia, czyli np. 1 lutego 2013 bêdzie mia³o wartoœæ 2013 + 32.0/365. W roku przestêpnym, 
oczywiœcie, mianownik bêdzie równy 366. Ignorujemy czas letni, sekundy przestêpne itp.

Celem zadania jest wczytanie tych danych do struktur danych, bibliotecznych lub samodzielnie napisanych, 
obliczenie trendu liniowego metod¹ najmniejszych kwadratów, i wyprodukowanie nowego pliku, z trzema kolumnami 
rozdzielanymi œrednikami, zawieraj¹cymi zmiennopozycyjne daty, cenê zamkniêcia, oraz wartoœæ liniowej funkcji trendu 
obliczon¹ dla danej zmiennopozycyjnej daty, wszystko z co najmniej czterema cyframi po przecinku. Potrzebujemy tak napisaæ 
us³ugê wczytywania, aby poradzi³a sobie równie¿ z plikami z kolejnych dni, gdzie danych bêdzie wiêcej. Po utworzeniu pliku 
nale¿y spróbowaæ zaimportowaæ go np. do LibreOffice.Calc albo Excela i sporz¹dziæ wykres.

Wskazówka: metoda najmniejszych kwadratów polega na tym, ¿e szukamy wspó³czynników a i b funkcji f(x)=a*x+b takich, 
¿e wartoœæ sumy wyra¿eñ (yi - (a*xi +b))2 jest jak najmniejsza, gdzie xi, yi to s¹ punkty pomiarowe, a i przebiega 
od 1 do n=iloœci pomiarów (matematycznie, bo kiedy dane bêd¹ w jakimœ wektorze c++ to oczywiœcie bêd¹ mia³y numery 
od zera do n-1). Taka suma jest funkcj¹ kwadratow¹ zmiennych a i b, i nale¿y znaleŸæ jej minimum poprzez znalezienie 
miejsca, gdzie zeruj¹ siê obie pochodne cz¹stkowe. Oczywiœcie gotowe proste wzory mo¿na znaleŸæ, ale warto policzyæ 
to raz w³asnorêcznie.
*/

#include <iostream>
#include <cassert>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

bool czyPrzestepny(int rok)
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
                if (czyPrzestepny(rok))
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

int ile_dni(int dzien, int miesiac, int rok)
{
    int dni = 0;

    if(miesiac > 1)
        dni += 31;
    if(miesiac > 2)
    {
        if(czyPrzestepny(rok) == 1)
            dni += 29;
        else
            dni += 28;
    }
    if(miesiac > 3)
        dni += 31;
    if(miesiac > 4)
        dni += 30;
    if(miesiac > 5)
        dni += 31;
    if(miesiac > 6)
        dni += 30;
    if(miesiac > 7)
        dni += 31;
    if(miesiac > 8)
        dni += 31;
    if(miesiac > 9)
        dni += 30;
    if(miesiac > 10)
        dni += 31;
    if(miesiac > 11)
        dni += 30;

    dni += dzien;

    return dni;
}

class Notowanie
{
private:
    std::string ticker_;
    double data_;
    double open_;
    double high_;
    double low_;
    double cena_;
    int vol_;
public:

    Notowanie(std::string t = "", double d = 0.0, double o = 0.0, double h = 0.0, double l = 0.0, double c = 0.0, int v = 0)
    :ticker_(t),data_(d),open_(o),high_(h),low_(l),cena_(c),vol_(v)
    {
    }

    std::string Ticker(void) {
        return ticker_;
    }

    double Data(void) const
    {
        return data_;
    }

    double Open(void) const
    {
        return open_;
    }

    double High(void) const
    {
        return high_;
    }

    double Low(void) const
    {
        return low_;
    }

    double Cena(void) const
    {
        return cena_;
    }

    int Vol(void) const
    {
        return vol_;
    }
};

std::istream& operator>>(std::istream& wejscie, Notowanie& n)
{
    std::istringstream sstr;
    std::string str;

    std::string ticker;
    int dat;
    double open;
    double high;
    double low;
    double cena;
    int vol;

    double data;

    std::getline(wejscie,str);
    for(unsigned int i=0; i<str.size(); ++i) {
        if(str[i] == ',') {
            str[i] = ' ';
        }
    }
    sstr.str(str);
    sstr >> ticker >> dat >> open >> high >> low >> cena >> vol;

    int r = dat/10000;
    int m = (dat - r * 10000)/100;
    int d = dat - r * 10000 - m*100;
    data = r + ile_dni(d,m,r)/(365.0+(czyPrzestepny(r)));

    if(wejscie && sstr)
        n = Notowanie( ticker,data,open,high,low,cena,vol );
    else
        wejscie.setstate(std::ios_base::failbit);

    return wejscie;
}

class SeriaNotowan
{
    std::vector<Notowanie> seria_;

public:

    std::vector<Notowanie> Seria(void) const
    {
        return seria_;
    }

    std::vector<Notowanie>& Seria(void)
    {
        return seria_;
    }

    Notowanie Podaj_Notowanie(int i) const
    {
        assert(i >= 1);

        return seria_[i-1];
    }

    Notowanie& Podaj_Notowanie(int i)
    {
        assert(i >= 1);

        return seria_[i-1];
    }

    Notowanie operator[](int i) const
    {
        return Podaj_Notowanie(i);
    }
};

std::istream& operator>>(std::istream& wejscie, SeriaNotowan& sp)
{
    Notowanie p;
    SeriaNotowan nowa;

    if(wejscie && (wejscie >> std::ws).eof())
    {
        sp = nowa;
        return wejscie;
    }

    std::string str;
    std::getline(wejscie,str);
    if(str != "<TICKER>,<DTYYYYMMDD>,<OPEN>,<HIGH>,<LOW>,<CLOSE>,<VOL>") {
        wejscie.setstate(std::ios_base::failbit);
        return wejscie;
    }

    do
    {
        wejscie >> p >> std::ws;

        if(wejscie)
            nowa.Seria().push_back( p );

    }while(wejscie && !wejscie.eof());

    if(wejscie)
        sp = nowa;

    return wejscie;
}

std::ostream& operator<<(std::ostream& wyjscie, Notowanie n)
{
    wyjscie << n.Ticker() << " ";
    wyjscie << n.Data() << " ";
    wyjscie << n.Open() << " ";
    wyjscie << n.High() << " ";
    wyjscie << n.Low() << " ";
    wyjscie << n.Cena() << " ";
    wyjscie << n.Vol();

    return wyjscie;
}

std::ostream& operator<<(std::ostream& wyjscie, SeriaNotowan sp)
{
    double sumaX = 0.0;
    double sumaY = 0.0;
    double sumaXX = 0.0;
    double sumaXY = 0.0;
    int n = 0;

    n = sp.Seria().size();

    double a = 0.0;
    double b = 0.0;

    double x = 0.0;
    double y = 0.0;
    double trend = 0.0;

    // Metoda najmniejszych kwadratów, na podstawie:
    // http://www.algorytm.org/procedury-numeryczne/metoda-najmniejszych-kwadratow.html
    // ------------------------------------------------------------------

    for(int i = 1; i <= n; ++i) {
        x = sp.Podaj_Notowanie(i).Data();
        y = sp.Podaj_Notowanie(i).Cena();

        sumaX += x;
        sumaY += y;
        sumaXX += x * x;
        sumaXY += x * y;
    }

    a = (sumaX * sumaY - sumaXY * n) / (sumaX * sumaX - sumaXX * n);
    b = (sumaX * sumaXY - sumaXX * sumaY) / (sumaX * sumaX - sumaXX * n);

    std::cout << a << "\t" << b << std::endl;

    // ------------------------------------------------------------------

    for(int i = 1; i <= n; ++i) {
        x = sp.Podaj_Notowanie(i).Data();
        y = sp.Podaj_Notowanie(i).Cena();
        trend = a * x + b;

        wyjscie << std::setprecision(7) << std::fixed;
        wyjscie << x << " ";
        wyjscie << y << " ";
        wyjscie << trend << " ";
        wyjscie << std::endl;
    }

    return wyjscie;
}

void testy(void)
{
    SeriaNotowan sp;

    std::string str = "";
    str.append("<TICKER>,<DTYYYYMMDD>,<OPEN>,<HIGH>,<LOW>,<CLOSE>,<VOL>\n");
    str.append("FIRMA,20140515,10.50,11.00,10.00,10.75,123456789\n");
    str.append("FIRMA,20140516,10.75,12.30,10.20,11.30,123456789\n");
    str.append("FIRMA,20140517,11.30,14.10,11.10,14.05,123456789\n");

    std::istringstream strum;
    strum.str( str );

    strum >> sp;

    assert(strum);
    assert( sp.Seria().size() == 3 );
    assert( sp.Podaj_Notowanie(2).Cena() == 11.30 );

    std::cerr << "Program pomyslnie przeszedl testy. \n";
}

int main()
{
    testy();

    Notowanie p;
    SeriaNotowan sp;

    std::fstream plik;

    plik.open("ORANGEPL.mst.txt", std::ios::in);
    plik >> sp;
    plik.close();

    plik.open("ORANGEPL.out.txt", std::ios::out);
    plik << sp;
    plik.close();


    std::cin.get();
    std::cout << std::endl;
    std::cin.get();

    return 0;
}
