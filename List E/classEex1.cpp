/*Napisz procedure, która dla danego podzakresu kolekcji deque<int> znajdzie wartosc minimalna,
i zastapi wszystkie wartosci w tym podzakresie róznica danej wartoœci i owej minimalnej.
Nie wolno u¿ywaæ petli ani rekursji, nale¿y funkcjê zaimplementowaæ przy pomocy algorytmów z biblioteki standardowej
(podpowiedz: min_element oraz transform lub for_each).*/

#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>
#include <cassert>

void Odniesienie(std::deque<int>::iterator p, std::deque<int>::iterator k)
{
    std::deque<int>::iterator pos = std::min_element(p,k);
    int val = (*pos);
    std::transform(p, k, p, [&](int x){return x -= val;});
}

void test_Odniesienie(void)
{
    std::deque<int> d {-4, 5, 7,2, 8,-3,-5, 9, 9};
    std::deque<int> dd{1,10,12,7,13,2,0,14,9};
    Odniesienie(std::begin(d),std::end(d)-1);
    assert(d==dd);

    std::cerr << "Program pomyslnie przeszedl testy. \n";
}

int main()
{
    test_Odniesienie();

    std::deque<int> d {-4, 5, 7,2, 8,-3,-5, 9, 9};
    std::deque<int>::iterator pos;

    std::cin.get();

    return 0;
}
