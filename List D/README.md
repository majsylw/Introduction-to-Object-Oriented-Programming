# Zadania na laboratorium

## Zadanie 1
Napisz procedurę ```Sprzezenie```, której argumentem będzie wskaźnik do liczby zespolonej, i która zmodyfikuje wskazywaną liczbę zmieniając ją na jej sprzężenie. Jeżeli wskaźnik nie wskazuje na żadną liczbę, procedura niczego nie zrobi. Przykładowy test:
<pre>
auto test_Sprzezenie(void) -> void
  {
  Zespolona z(1.0,2.0);
  Sprzezenie(&z);
  assert(z.Re()==1.0);
  assert(z.Im()==-2.0);
  Sprzezenie(nullptr);  // nic nie robi, ale nie powinno powodować błędu wykonania
  std::cerr << "test_Sprzezenie ok\n";
  }
</pre>

## Zadanie 2

Funkcje, które mają operować na kolejnych elementach tablicy można w łatwy sposób napisać tak, że będą również działać na "podtablicach", to znaczy na kolejnych elementach tablicy ale z pominięciem pewnej ilości elementów na początku i na końcu. W tym celu wystarczy napisać taką funkcję w taki sposób, że zamiast wskaźnika do elementu o indeksie zero i rozmiaru, podajemy jej wskaźnik do pierwszego elementu, który ma być brany pod uwagę, i wskaźnik do pierwszego, który operacji już nie podlega. Ponieważ legalny jest wskaźnik do "elementu pierwszego po ostatnim" w całej tablicy, pozwala to na przetwarzanie całej tablicy. Ponadto, przekazanie dwóch wskaźników na ten sam element sygnalizuje, że nie powinna być podejmowana żadna akcja.

Napisz procedurę ```RazyDwa```, której parametrami będą trzy wskaźniki do ```int```. Pierwsze dwa będą określały zakres danych, w zgodzie z powyższym akapitem: pierwszy będzie wskaźnikiem do pierwszej liczby podlegającej obliczeniom, a drugi będzie wskaźnikiem do pierwszej liczby, która już nie będzie podlegać obliczeniom. Trzeci wskaźnik będzie wskaźnikiem do tablicy docelowej, dokąd mają trafiać kolejne wyniki. Obliczenia mają polegać na pomnożeniu wskazywanej liczby przez dwa i zapisaniu wyniku na kolejnych miejscach tablicy docelowej. Można (i trzeba) założyć, że przekazane wskaźniki nie są nullptr (można to sprawdzać assertem), oraz że w tablicy docelowej jest dosyć miejsca na wszystkie wyniki (to trzeba założyć, bo nie ma jak sprawdzić). Przykładowe testy:

<pre>
auto test_RazyDwa(void) -> void
  {
  int r[] ={1,2,3,4,5,6,7};
  int t[] ={1,2,3,4,5,6,7};
  int w1[]={0,0,0,0,0,0,0};
  int w2[]={0,0,0};
  int w3[]={0,0,0,0,0};

  RazyDwa(t,t+7,w1);      // obliczenia dla całego t, wyniki do w1 od początku
  for(int i=0; i<7; ++i)
    {
    assert( r[i]==t[i]);
    assert(w1[i]==t[i]*2);
    }

  RazyDwa(t+2,t+5,w2);    // obliczenia dla podciągu o indeksach 2,3,4
                          // wyniki do w2 od początku
  for(int i=2; i<5; ++i)
    {
      assert( r[i]==t[i]);
    assert(w2[i-2]==t[i]*2);
    }

  RazyDwa(t+2,t+5,w3+1);  // obliczenia dla podciągu o indeksach 2,3,4
                          // wyniki do w3 od indeksu 1, w takim razie
                          // wartości w3[0] i w3[4] niezmieniane
  assert(w3[0]==0);
  assert(w3[4]==0);
  for(int i=2; i<5; ++i)
    {
      assert( r[i]==t[i]);
    assert(w3[i-1]==t[i]*2);
    }

  RazyDwa(t+2,t+5,t+2);   // obliczenia dla podciągu o indeksach 2,3,4
                          // wyniki z powrotem do t na miejsca, skąd były
                          // brane liczby do obliczeń
  assert(t[0]==1);
  assert(t[1]==2);
  assert(t[2]==6);
  assert(t[3]==8);
  assert(t[4]==10);
  assert(t[5]==6);
  assert(t[6]==7);
  }
</pre>

## Zadanie 3

Napisz procedurę Sortuj3Wskazniki, której argumentem będzie tablica wskaźników do napisów (czyli wskaźnik do tablicy wskaźników). Zakładamy, że tych napisów jest dokładnie 3. Procedura zmodyfikuje tę tablicę wskaźników zgodnie z porządkiem leksykograficznym napisów, na które one wskazują (ponieważ do posortowania mamy zawsze trzy i tylko trzy wielkości, algorytm sortujący nie musi być zbyt wyrafinowany). Przykład testów:

<pre>
auto test_Sortuj3Wskazniki(void) -> void
  {
  std::string napisy[]={"Dabacki","Babacki","Abacki"};
  std::string* wskazniki[]={napisy,napisy+1,napisy+2};

  Sortuj3Wskazniki(wskazniki);

  assert(napisy[0]=="Dabacki");
  assert(napisy[1]=="Babacki");
  assert(napisy[2]=="Abacki");

  assert(*(wskazniki[0])=="Abacki");
  assert(*(wskazniki[1])=="Babacki");
  assert(*(wskazniki[2])=="Dabacki");

  std::cerr << "test_Sortuj3Wskazniki ok\n";
  }
</pre>