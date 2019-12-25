# Zadania na laboratorium

Uzupełnienie: Zamiana wartosci na napis

Żeby zamienić wartość typu int czy double:
<pre>
int x{17};
</pre>
na odpowiadający jej napis należy użyć biblioteki sstream (umieszczając #include <sstream> na początku pliku), oraz utworzyć zmienną typu std::ostringstream np. w następujący sposób:

<pre>
std::ostringstream strumien;    // std::ostringstream to typ zmiennej, strumien to wybrana przez nas nazwa
strumien << x;                  // zmienna typu strumieniowego ma takie same operacje jak std::cout
std::string napis = strumien.str();  // strumien.str() to wyrażenie o wartości napisowej zawierające 
                                     // to, co wysłaliśmy do strumienia. napis to zmienna typu napisowego
</pre>
Typ napisowy std::string może być używany w każdym kontekście, również jako typ argumentu funkcji jak i typ wyniku obliczanego przez funkcję (do jego użycia potrzebne jest wpisanie #include <string> na początku pliku). Wyrażenia o wartości napisowej można również wypisywać na strumienie, np. zachowując znaczenie zmiennych z powyższego przykładu

<pre>
std::cout << napis;
</pre>

wypisujemy zawartość zmiennej napis na konsolę.

## Zadanie 1
Napisz funkcję, która zamieni liczbę całkowitą z zakresu od -999999 do 999999 na polski liczebnik. Napisz funkcję, która dla zadanej liczby całkowitej wygeneruje napis składający się z liczebnika i właściwej formy słowa "elementy", tak jak np. w "pięć elementów". Przemyśl podział problemu na funkcje, i napisz testy do każdej z nich. Pamiętaj o sprawdzaniu warunków wstępnych na argumenty funkcji.

## Zadanie 2
Napisz funkcję, która dla zadanej daty (dnia, miesiąca i roku) wygeneruje jej słowny zapis, np. "piątek, 29 marca 2013". Znajdź dzień tygodnia dla danej daty przy pomocy stosownego algorytmu. Podziel zadanie na funkcje z pojedynczą odpowiedzialnością. Przetestuj każdą z funkcji (tzn. napisz funkcje testujące). Pamiętaj o sprawdzaniu warunków wstępnych na argumenty funkcji.

## Zadanie 3
Napisz funkcję, która dla podanej płci, kwoty zadłużenia, imienia, nazwiska, adresu i daty sporządzenia wygeneruje tekst spersonalizowanego listu do dłużnika ze zobowiązaniem do natychmiastowej zapłaty. Wyraź kwotę zadłużenia słownie jako np. "pięć złotych i czterdzieści siedem groszy" (pamiętaj, że 1 złoty, 2 złote a 5 złotych, z groszami podobnie). Spróbuj maksymalnie wykorzystać funkcje z poprzednich dwóch zadań, możesz je nawet na tym etapie przerobić tak, aby były tak uniwersalne, że będzie można z nich skorzystać w obu kontekstach. Pamiętaj o sprawdzaniu warunków wstępnych na argumenty funkcji. Przetestuj i zademonstruj działanie tej funkcji.

## Zadanie 4
Napisz funkcję, która zadaną liczbę całkowitą (być może ujemną) zamieni na jej zapis w systemie pozycyjnym o zadanej podstawie większej niż 2 i nie większej niż 36 (użyj w zapisie do 10 cyfr i 26 liter). Nie używaj bibliotecznych usług, które to zadanie rozwiązują, sam/sama przeprowadź rachunki. Napisz funkcję testującą. Pamiętaj o sprawdzaniu warunków wstępnych na argumenty funkcji. Przykład: dla 254 w układzie szesnastkowym oczekujemy wyjścia FE lub fe (możesz zdecydować czy używasz wielkich czy małych liter).