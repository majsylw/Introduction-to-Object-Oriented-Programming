/*Napisz funkcje, ktora dla danego podzakresu listy wielkosci typu double,
reprezentujacych oceny szkolne, obliczy sredni¹ z tych ocen z tego podzakresu,
ktore sa pozytywne, tj. wieksze od jedynki. Nie wolno uzywaæ petli ani rekursji,
nale¿y funkcjê zaimplementowaæ przy pomocy algorytmów z biblioteki standardowej
(podpowiedŸ: accumulate oraz count_if).*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include <cassert>

bool WiekszaOdJeden(int i)
{
    return (i > 1);
}

bool MniejszaRownaJeden(int i)
{
    return (i <= 1);
}

double SredniaPozytywnych(std::list<double>::iterator p, std::list<double>::iterator k)
{
    double srednia = 0.0;

    int dzielnik = std::count_if(p, k, WiekszaOdJeden);
    int odejmij = - std::count_if(p, k, MniejszaRownaJeden);
    double dzielna = std::accumulate(p,k,odejmij);

    srednia = dzielna/dzielnik;

    return srednia;
}

void test_SredniaPozytywnych(void)
{
    std::list<double> oceny{1,3,1,2,4,5,1,2};
    double s=SredniaPozytywnych(std::begin(oceny),--(std::end(oceny)))
    ;
    assert(s==3.5); // 3+2+4+5=14; 14.0/4==3.5, ostatnia 2 nie wchodzi
                    //             do œredniej bo podzakres koñczy siê
                    //             na przedostatniej ocenie

    std::cerr << "Program pomyslnie przeszedl testy. \n";
}

int main()
{
    test_SredniaPozytywnych();

    std::list<double> oceny{1,3,1,2,4,5,1,2};

    std::cout << SredniaPozytywnych(std::begin(oceny),std::end(oceny));

    std::cin.get();

    return 0;
}
