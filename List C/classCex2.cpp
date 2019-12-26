/*
Sito Eratostenesa jest algorytmem pozwalającym znaleźć wszystkie liczby pierwsze z przedziału od 2 do zadanego górnego 
ograniczenia N. Jego działanie zaczyna się od kompletnej listy liczb od 2 do N. W kolejnym kroku znajdujemy pierwszą liczbę 
na liście, której jeszcze nie rozpatrywaliśmy, i usuwamy z listy wszystkie jej wielokrotności z wyjątkiem jej samej 
(wielokrotności 1). Powtarzamy krok aż przekroczymy N/2, wtedy wszystkie liczby, które pozostały na liście są pierwsze. 
Napisz funkcję, która zwróci kolekcję zawierającą kolejne liczby pierwsze od 2 do zadanego ograniczenia N (tzn. k-ta liczba 
w tej obliczonej kolekcji ma być k-tą kolejną liczbą pierwszą, gdzie 2 jest zerową liczbą pierwszą). Napisz funkcję testującą.
*/

#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> Liczby_pierwsze(unsigned int n)
{
    assert(n >= 2);

    std::vector<int> pierwsze;

    for(unsigned int i = 2; i <= n ; ++i)
    {
        pierwsze.push_back(i);
    }

    for(unsigned int j = 0; j < pierwsze.size(); ++j)
    {
        for(unsigned int k = j + 1; k < pierwsze.size(); ++k)
        {
            if(pierwsze[k]%pierwsze[j] == 0)
            {
                pierwsze.erase(pierwsze.begin() + k);
                --k;
            }
        }
    }

    return pierwsze;
}

void test(void)
{
    assert(Liczby_pierwsze(70).size() == 19);

    std::vector<int> p{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

    assert(p == Liczby_pierwsze(100));

    std::cerr << "Program pomyslnie przeszedl testy. \n";
}

int main()
{
    test();

    std::cout << (Liczby_pierwsze(8)).size() << std::endl;

    return 0;
}
