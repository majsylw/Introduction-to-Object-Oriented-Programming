/*
Funkcje, które maj¹ operowaæ na kolejnych elementach tablicy mo¿na w ³atwy sposób napisaæ tak, ¿e bêd¹ równie¿ dzia³aæ 
na "podtablicach", to znaczy na kolejnych elementach tablicy ale z pominiêciem pewnej iloœci elementów na pocz¹tku i 
na koñcu. W tym celu wystarczy napisaæ tak¹ funkcjê w taki sposób, ¿e zamiast wskaŸnika do elementu o indeksie zero 
i rozmiaru, podajemy jej wskaŸnik do pierwszego elementu, który ma byæ brany pod uwagê, i wskaŸnik do pierwszego, 
który operacji ju¿ nie podlega. Poniewa¿ legalny jest wskaŸnik do "elementu pierwszego po ostatnim" w ca³ej tablicy, 
pozwala to na przetwarzanie ca³ej tablicy. Ponadto, przekazanie dwóch wskaŸników na ten sam element sygnalizuje, 
¿e nie powinna byæ podejmowana ¿adna akcja.

Napisz procedurê RazyDwa, której parametrami bêd¹ trzy wskaŸniki do int. Pierwsze dwa bêd¹ okreœla³y zakres danych, 
w zgodzie z powy¿szym akapitem: pierwszy bêdzie wskaŸnikiem do pierwszej liczby podlegaj¹cej obliczeniom, 
a drugi bêdzie wskaŸnikiem do pierwszej liczby, która ju¿ nie bêdzie podlegaæ obliczeniom. Trzeci wskaŸnik bêdzie 
wskaŸnikiem do tablicy docelowej, dok¹d maj¹ trafiaæ kolejne wyniki. Obliczenia maj¹ polegaæ na pomno¿eniu wskazywanej 
liczby przez dwa i zapisaniu wyniku na kolejnych miejscach tablicy docelowej. Mo¿na (i trzeba) za³o¿yæ, ¿e przekazane 
wskaŸniki nie s¹ nullptr (mo¿na to sprawdzaæ assertem), oraz ¿e w tablicy docelowej jest dosyæ miejsca na wszystkie wyniki 
(to trzeba za³o¿yæ, bo nie ma jak sprawdziæ).
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
                          // wyniki do w2 od pocz¹tku
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
