# Zadania na laboratorium

## Zadanie 1
Napisz funkcję, która sprawdzi, czy podany rok jest przestępny. Sprawdź od kiedy obowiązuje kalendarz gregoriański i które dokładnie lata są w nim przestępne. Możesz skorzystać z operatora koniunkcji: wartosc_logiczna1 && wartosc_logiczna2 jest prawdą wtedy i tylko wtedy gdy obie wartości są prawdą, alternatywy: wartosc_logiczna1 || wartosc_logiczna2 jest prawdą wtedy i tylko wtedy, gdy chociaż jedna z wartości jest prawdą, oraz negacji: !wartosc_logiczna jest prawdą wtedy i tylko wtedy, gdy wartość jest fałszem. Napisz program, który zilustruje działanie tej funkcji.

## Zadanie 2
Napisz funkcję, która dla zadanej liczby naturalnej n≥0 znajdzie największą liczbę naturalną m, taką że m<sup>2</sup> ≤ n.
Wskazówka: funkcja k<sup>2</sup> jest rosnąca, i wiadomo, że m leży gdzieś w przedziale [0,n]. Patrzymy zatem na liczbę naturalną zbliżoną do połowy przedziału [0,n], i jeżeli spełnia nasz warunek, to mamy rozwiązanie, jeżeli jest za duża, to wiemy, że m leży pomiędzy 0 a tą połową, jeżeli zaś jest za mała, to m leży pomiędzy tą połową a n. Jeżeli nie mamy rozwiązania i liczymy dalej, wiemy, że rozwiązanie jest w nowym, krótszym przedziale. Ponownie patrzymy na środek, itd. Postępując w ten sposób zawsze znajdziemy odpowiedź. Zastosuj opisany tu algorytm.

## Zadanie 3
Napisz procedurę (czyli funkcję, która nie oblicza wartości, ale ma interesujący nas efekt uboczny), która wyświetli cyfry zadanej liczby naturalnej w zapisie pozycyjnym o zadanej podstawie, w naturalnej kolejnośći, tzn. np. 25<sub>(10)</sub> w zapisie przy podstawie 8 da 31, bo 25<sub>(10)</sub> = 8<sup>1</sup>\*3+8<sup>0</sup>\*1. Nie obliczaj tych cyfr wewnątrz tej procedury, skorzystaj z funkcji z jednej z poprzednich list. Napisz program, który zapyta użytkownika o liczbę naturalną, wywoła tę procedurę, a następnie zapyta użytkownika, czy chce podać jeszcze jedną liczbę (przy pomocy wpisania 0 lub 1). Jeżeli odpowiedź użytkownika będzie na tak, program przejdzie znów cały cykl wprowadzenie danej-wypisanie wyniku-pytanie o kontynuację. Jeżeli odpowiedź będzie na nie to program podziękuje i skończy pracę.
UWAGA (dopisane 13.03): interesują nas w tym i następnym zadaniu wyłącznie układy pozycyjne o podstawach od 2 do 10 włącznie.

## Zadanie 4
Napisz program, który przy pomocy zagnieżdżonych pętli wypisze na ekran tabliczkę mnożenia w układzie pozycyjnym o zadanej podstawie, z zachowaniem układu kolumn. Np. dla podstawy 8:
<pre>
    1  2  3  4  5  6  7  10 
 1  1  2  3  4  5  6  7  10 
 2  2  4  6 10 12 14 16  20 
 3  3  6 11 14 17 22 25  30 
 4  4 10 14 20 24 30 34  40 
 5  5 12 17 24 31 36 43  50 
 6  6 14 22 30 36 44 52  60 
 7  7 16 25 34 43 52 61  70 
10 10 20 30 40 50 60 70 100
</pre>