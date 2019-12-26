# Zadania na laboratorium

## Zadanie 1

Napisz klasę BigInt modelującą liczby całkowite o dowolnej wielkości. Wyposaż ją w:
- Konstruktor z liczb typu ```int```
- Konstruktor z napisów, rozumianych jako zapis liczby w dziesiętnym układzie pozycyjnym
- Operatory arytmetyczne dodawania i odejmowania (zarówno typu ```+=``` jak i ```+```), unarne ```+``` i ```-```, przyrostkowe i przedrostkowe ++ oraz --
- Operatory porównania, w komplecie: ```<```, ```<=```, ```>```, ```>=```, ```==```, ```!=```
- Operatory ```>>``` oraz ```<<``` pozwalające na wczytanie liczby ze strumienia i zapisanie jej na strumień

Dodatkowy plus za zadanie można dostać za implementację, w której nie będziemy pamiętać napisu, ale ciąg wartości 32-bitowych, które można rozumieć jako zapis liczby w układzie o podstawie 232. Wartości ujemne można reprezentować pamiętając do tego dodatkowo znak. (Cyfry 32-bitowe są dla nas lepsze niż 64-bitowe, bo przy mnożeniu dwóch liczb 32-bitowych(jednocyfrowych) wynik zmieści się w liczbie 64-bitowej(dwucyfrowej), podobnie przy dzieleniu, będziemy potrzebowali dzielić liczby 64-bitowe(dwucyfrowe) przez 32-bitowe(jednocyfrowe).)

Jeszcze jeden dodatkowy plus specjalnej kategorii można dostać za próbę zaprogramowania dzielenia dwóch liczb. Stosowny algorytm można znaleźć w książce Donalda E. Knutha Sztuka programowania (The Art Of Computer Programming), tom 2, rozdział 4.3.1, algorytm D.

Przykład użycia w testach, które należy uzupełnić o testowanie pozostałych funkcji:
<pre>
auto test_BigInt(void) -> void
  {
  BigInt b1("123456789012345678901234567890");
  BigInt b2("120000011000000000000000000019");
  b1+=b2;
  assert(b1==BigInt("243456800012345678901234567909"));

  BigInt b3(    "123456789012345678901234567890");
  BigInt b4("9999920000011000000000000000000019");
  assert((b3+b4)==BigInt("10000043456800012345678901234567909"));
  }
</pre>

## Zadanie 2

Sito Eratostenesa jest algorytmem pozwalającym znaleźć wszystkie liczby pierwsze z przedziału od 2 do zadanego górnego ograniczenia N. Jego działanie zaczyna się od kompletnej listy liczb od 2 do N. W kolejnym kroku znajdujemy pierwszą liczbę na liście, której jeszcze nie rozpatrywaliśmy, i usuwamy z listy wszystkie jej wielokrotności z wyjątkiem jej samej (wielokrotności 1). Powtarzamy krok aż przekroczymy N/2, wtedy wszystkie liczby, które pozostały na liście są pierwsze. Napisz funkcję, która zwróci kolekcję zawierającą kolejne liczby pierwsze od 2 do zadanego ograniczenia N (tzn. k-ta liczba w tej obliczonej kolekcji ma być k-tą kolejną liczbą pierwszą, gdzie 2 jest zerową liczbą pierwszą). Napisz funkcję testującą.