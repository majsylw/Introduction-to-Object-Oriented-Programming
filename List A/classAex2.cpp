/*
W pewnym pliku przechowywane są dane o czasie i położeniu pewnej cząstki, jako pary liczb zmiennoprzecinkowych o składni (czas;położenie), 
dopuszczamy rozdzielanie odstępami w dowolnym miejscu zapisu, przy czym nie mamy gwarancji, że każda para zajmuje 
osobny wiersz, dopuszczamy więcej par w wierszu i dopuszczamy pary, które zajmują więcej wierszy, 
np. ( w jednym, czas; w kolejnym i położenie) w trzecim. Ponadto po ostatniej parze może być jeszcze pewna ilość odstępów.
Napisz klasę Pomiar, która będzie reprezentowała pojedynczy pomiar położenia i czasu. Wyposaż ją w operator>>, 
który posłuży przy wczytywaniu danych z pliku, o którym mowa wyżej.

Napisz klasę SeriaPomiarowa, która będzie reprezentowała dane wczytane ze strumienia. Wyposaż ją w operator>>, 
który podejmie próbę wczytania danych ze strumienia, i w przypadku pomyślnego wczytania punktów i wyczerpania 
zawartości strumienia przypisze wczytane dane na prawostronny argument, a w przeciwnym razie zwróci zepsuty strumień. 
(Na marginesie: tak napisany operator>> będzie poprawnie współpracował ze strumieniami plikowymi i napisowymi, ale nie 
z konsolą, ponieważ w strumieniu konsolowym nie ma naturalnego pojęcia końca strumienia). Napisz ten operator w taki sposób, 
żeby działał z dowolnym strumieniem danych o zadanym formacie, w szczególności, ilość punktów do przeczytania musi wynikać 
z zawartości danych i nie może być wpisana w kod programu.

Wyposaż klasę SeriaPomiarowa w metodę/metody pozwalające na odczytanie przechowywanego punktu pomiarowego 
o zadanym indeksie, oraz o metody obliczające przybliżenie pierwszej pochodnej (prędkości) ze wzoru

pp(i)=(yi+1-yi-1)/(ti+1-ti-1)

i drugiej (przyspieszenia) ze wzoru
dp(i)=2((ti-ti-1)*(yi+1-yi) -(ti+1-ti)*(yi-yi-1))/ (ti+1-ti-1)

Oczywiście te dwie pochodne da się policzyć dla wszystkich punktów poza pierwszym i ostatnim.
Wyposaż swoją kolekcję w możliwość zapisu do pliku w formacie rozdzielanym średnikami, umieszczając w pierwszej 
kolumnie czas, w drugiej położenie, w trzeciej prędkość a w czwartej przyspieszenie, zostawiając puste te miejsca, 
gdzie prędkości i przyspieszenia nie da się policzyć.

Zastanów się jak to wszystko zrobić tak, aby była możliwość testowania wszystkich funkcji z wewnątrz funkcji testującej, 
bez wykorzystania zewnętrznych plików.
*/

#include <iostream>
#include <cassert>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

class Pomiar
{
private:
    double czas_;
    double polozenie_;
public:

    Pomiar(double x = 0.0, double t = 0.0)
    :czas_(t),polozenie_(x)
    {
    }

    double Polozenie(void) const
    {
        return polozenie_;
    }

    double Czas(void) const
    {
        return czas_;
    }
};

std::istream& operator>>(std::istream& wejscie, Pomiar& p)
{
    char nawp, srednik, nawk;
    double x;
    double t;

    if(wejscie)
    {
        wejscie >> std::ws >> nawp >> std::ws >> t >> std::ws >> srednik >> std:: ws >> x >> std::ws >> nawk;

        if(wejscie)
        {
            if(nawp == '(' && nawk == ')' && srednik == ';')
                p = Pomiar(x,t);
            else
                wejscie.setstate(std::ios_base::failbit);
        }

    }

    return wejscie;
}

std::ostream& operator<<(std::ostream& wyjscie, Pomiar p)
{
    wyjscie << '(' << p.Czas() << ';' << p.Polozenie() << ')';
    return wyjscie;
}

class SeriaPomiarowa
{
    std::vector<Pomiar> seria_;

public:

    std::vector<Pomiar> Seria(void) const
    {
        return seria_;
    }

    std::vector<Pomiar>& Seria(void)
    {
        return seria_;
    }

    Pomiar Podaj_Pomiar(int i) const
    {
        assert(i >= 1);

        return seria_[i-1];
    }

    Pomiar& Podaj_Pomiar(int i)
    {
        assert(i >= 1);

        return seria_[i-1];
    }

    Pomiar operator[](int i) const
    {
        return Podaj_Pomiar(i);
    }

    double predkosc(unsigned int i)
    {
        assert(i > 1);
        assert(i < Seria().size());

        double predkosc = (Podaj_Pomiar(i+1).Polozenie() - Podaj_Pomiar(i-1).Polozenie())/(Podaj_Pomiar(i+1).Czas() - Podaj_Pomiar(i-1).Czas());

        return predkosc;
    }

        double przyspieszenie(unsigned int i)
    {
        assert(i > 1);
        assert(i < Seria().size());

        double przyspieszenie = 2*(((Podaj_Pomiar(i).Czas() - Podaj_Pomiar(i-1).Czas())*(Podaj_Pomiar(i+1).Polozenie() - Podaj_Pomiar(i).Polozenie()))-((Podaj_Pomiar(i+1).Czas() - Podaj_Pomiar(i).Czas())*(Podaj_Pomiar(i).Polozenie() - Podaj_Pomiar(i-1).Polozenie())))/(Podaj_Pomiar(i+1).Czas() - Podaj_Pomiar(i-1).Czas());

        return przyspieszenie;
    }
};

std::istream& operator>>(std::istream& wejscie, SeriaPomiarowa& sp)
{
    Pomiar p;


    while(wejscie)
    {
        wejscie >> p >> std::ws;

        if(wejscie)
            sp.Seria().push_back( p );

    }

    return wejscie;
}

void testy(void)
{
    SeriaPomiarowa sp;

    std::istringstream strum;
    strum.str( "\n(1.0;0.0) (1.0   ;  2.0) \t(2.5; 3.7) (4.1  \n  ; 2.5 )    ( 1.2; 3.4 ) ( 3.4 ; ; 2.2 ) (1.2;2.4)" );
    strum >> sp;
    assert(!strum);
    assert(sp.Seria().size() == 5);

    std::cerr << "Program pomyslnie przeszedl testy. \n";
}

std::ostream& operator<<(std::ostream& wyjscie, SeriaPomiarowa sp)
{
    wyjscie << sp.Podaj_Pomiar(1).Czas() << ';' << sp.Podaj_Pomiar(1).Polozenie() << ';' << std::endl;

    for(unsigned int i = 2; i < sp.Seria().size(); ++i)
    {
        wyjscie << sp.Podaj_Pomiar(i).Czas() << ';' << sp.Podaj_Pomiar(i).Polozenie() << ';' << sp.predkosc(i) << ';' << sp.przyspieszenie(i) << ';' << std::endl;
    }
    if(sp.Seria().size() >= 2)
        wyjscie << sp.Podaj_Pomiar(sp.Seria().size()).Czas() << ';' << sp.Podaj_Pomiar(sp.Seria().size()).Polozenie() << ';' << std::endl;

    return wyjscie;
}

int main()
{
    testy();

    Pomiar p;
    SeriaPomiarowa sp;

    std::fstream plik;
    std::istringstream strum;

    plik.open("dane.txt", std::ios::in);
    plik >> sp;
    plik.close();

    strum.str( "(1.0; 1.0) (2.0; 4.0) (3.0; 9.0) (4.0; 16.0) (5.0; 25.0) (6.0; 41.0) (7.0; 50.0) (8.0; 54.0) (9.0; 55.0) (10.0; 54.0) (11.0; 50.0) (12.0; 46.0) (13.0; 42.0) (14.0; 38.0)" );
    strum >> sp;

    std::cout << p.Polozenie() << " " << p.Czas() << std::endl;

    for( unsigned int i = 0; i < sp.Seria().size(); ++i ) {
        std::cout << sp.Seria()[i].Czas() << " " << sp.Seria()[i].Polozenie() << " <--- " << std::endl;
    }

    plik.open("wynik.txt", std::ios::out);
    plik << sp;

    std::cout << sp;

    return 0;
}
