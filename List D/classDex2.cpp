/*
Funkcje, kt�re maj� operowa� na kolejnych elementach tablicy mo�na w �atwy spos�b napisa� tak, �e b�d� r�wnie� dzia�a� 
na "podtablicach", to znaczy na kolejnych elementach tablicy ale z pomini�ciem pewnej ilo�ci element�w na pocz�tku i 
na ko�cu. W tym celu wystarczy napisa� tak� funkcj� w taki spos�b, �e zamiast wska�nika do elementu o indeksie zero 
i rozmiaru, podajemy jej wska�nik do pierwszego elementu, kt�ry ma by� brany pod uwag�, i wska�nik do pierwszego, 
kt�ry operacji ju� nie podlega. Poniewa� legalny jest wska�nik do "elementu pierwszego po ostatnim" w ca�ej tablicy, 
pozwala to na przetwarzanie ca�ej tablicy. Ponadto, przekazanie dw�ch wska�nik�w na ten sam element sygnalizuje, 
�e nie powinna by� podejmowana �adna akcja.

Napisz procedur� RazyDwa, kt�rej parametrami b�d� trzy wska�niki do int. Pierwsze dwa b�d� okre�la�y zakres danych, 
w zgodzie z powy�szym akapitem: pierwszy b�dzie wska�nikiem do pierwszej liczby podlegaj�cej obliczeniom, 
a drugi b�dzie wska�nikiem do pierwszej liczby, kt�ra ju� nie b�dzie podlega� obliczeniom. Trzeci wska�nik b�dzie 
wska�nikiem do tablicy docelowej, dok�d maj� trafia� kolejne wyniki. Obliczenia maj� polega� na pomno�eniu wskazywanej 
liczby przez dwa i zapisaniu wyniku na kolejnych miejscach tablicy docelowej. Mo�na (i trzeba) za�o�y�, �e przekazane 
wska�niki nie s� nullptr (mo�na to sprawdza� assertem), oraz �e w tablicy docelowej jest dosy� miejsca na wszystkie wyniki 
(to trzeba za�o�y�, bo nie ma jak sprawdzi�).
*/

#include <iostream>
#include <cassert>

void RazyDwa(int* poczatkowa, int* koncowa, int* tab)
{
    assert(poczatkowa != nullptr);
    assert(koncowa != nullptr);
    assert(tab != nullptr);
    int j = 0;

    while((poczatkowa + j) < koncowa)
    {
        *(tab + j) = *(poczatkowa + j) * 2;
        ++j;
    }
}

auto test_RazyDwa(void) -> void
{
    int r[] ={1,2,3,4,5,6,7};
    int t[] ={1,2,3,4,5,6,7};
    int w1[]={0,0,0,0,0,0,0};
    int w2[]={0,0,0};
    int w3[]={0,0,0,0,0};

    RazyDwa(t,t+7,w1);      // obliczenia dla calego t, wyniki do w1 od poczatku
    for(int i=0; i<7; ++i)
    {
        assert(r[i]==t[i]);
        assert(w1[i]==t[i]*2);
    }

    RazyDwa(t+2,t+5,w2);    // obliczenia dla podciagu o indeksach 2,3,4
                          // wyniki do w2 od pocz�tku
    for(int i=2; i<5; ++i)
    {
        assert( r[i]==t[i]);
        assert(w2[i-2]==t[i]*2);
    }

    RazyDwa(t+2,t+5,w3+1);  // obliczenia dla podciagu o indeksach 2,3,4
                          // wyniki do w3 od indeksu 1, w takim razie
                          // wartosci w3[0] i w3[4] niezmieniane
    assert(w3[0]==0);
    assert(w3[4]==0);
    for(int i=2; i<5; ++i)
    {
        assert( r[i]==t[i]);
        assert(w3[i-1]==t[i]*2);
    }

    RazyDwa(t+2,t+5,t+2);   // obliczenia dla podciagu o indeksach 2,3,4
                          // wyniki z powrotem do t na miejsca, skad byly
                          // brane liczby do obliczen
    assert(t[0]==1);
    assert(t[1]==2);
    assert(t[2]==6);
    assert(t[3]==8);
    assert(t[4]==10);
    assert(t[5]==6);
    assert(t[6]==7);

    std::cerr << "Program pomyslnie przeszedl testy. \n";
}

int main()
{
    test_RazyDwa();

    std::cin.get();

    return 0;
}
