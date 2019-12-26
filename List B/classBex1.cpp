/*
Napisz funkcję, która dla zadanej kolekcji napisów (np. listy nazwisk) wyprodukuje kolekcję, w której znajdą się na powrót 
wszystkie te napisy, ale uporządkowane leksykograficznie (ignorujemy tym razem kwestię polskich znaków diakrytycznych 
i polegamy na takim porządku, jakiego domyślnie dostarcza język c++ dla liter, i, co za tym idzie, dla napisów; 
napisy można porównywać typowymi operatorami porównania i porządek przez nie definiowany jest leksykograficzny, 
czyli zupełny i bardzo porządny, oczywiście o ile litery są z zakresu ASCII). Samodzielnie zaprogramuj algorytm sortowania, 
nie używaj gotowych sortujących funkcji bibliotecznych. Spróbuj sam(a) zastanowić się nad algorytmem zanim sprawdzisz jakie 
są standardowe rozwiązania. Przetestuj i napisz program ilustrujący działanie tej funkcji.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

std::vector<std::string> sortowanie_funkcja(std::vector<std::string> lista)
{
    std::vector<std::string> nowa = lista;

    int n = lista.size();

    do{
        for(int i = 0; i < n - 1; ++i)
        {
            if(nowa[i] > nowa[i+1])
                swap(nowa[i],nowa[i+1]);
        }

        n -= 1;

    } while(n > 1);

    return nowa;
}

void sortowanie_na_biezacej_liscie(std::vector<std::string>& nowa)
{
    int n = nowa.size();

    do{
        for(int i = 0; i < n - 1; ++i)//bedziemy zawsze wyrzucac najwieksza wartosc na koniec
        {
            if(nowa[i] > nowa[i+1]) // sprawdzamy wyrazy stojace obok siebie
                swap(nowa[i],nowa[i+1]);
        }

        n -= 1;

    } while(n > 1);
}

void testy(void)
{
    std::vector<std::string> lista{"Lucjan","Alicja","Barbara","Maciej","Tomasz"};
    std::vector<std::string> uporzadkowana{"Alicja","Barbara","Lucjan","Maciej","Tomasz"};

    std::vector<std::string> nieuporzadkowana = lista;
    std::vector<std::string> nowa = sortowanie_funkcja(lista);

    sortowanie_na_biezacej_liscie(lista);

    assert(lista == uporzadkowana);
    assert(lista == nowa);
    assert(lista != nieuporzadkowana);

    std::cerr << "Program pomyslnie przeszedl testy. \n";
}

int main()
{
    testy();

    std::vector<std::string> im{"Lucjan","Alicja","Barbara","Maciej","Tomasz"};

    std::vector<std::string> imiona;
    imiona = sortowanie_funkcja(im);
    sortowanie_na_biezacej_liscie(im);

    for(unsigned int i = 0; i < im.size(); ++i)
    {
        std::cout << im[i] << std::endl;
    }

    std::cout << "Jeszcze raz to samo inaczej:" << std::endl;


    for(unsigned int i = 0; i < imiona.size(); ++i)
    {
        std::cout << imiona[i] << std::endl;
    }

    return 0;
}
