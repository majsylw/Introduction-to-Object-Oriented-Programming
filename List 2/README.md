# Zadania na laboratorium
We wszytkich zadaniach można i należy skorzystać z operatora dzielenia całkowitoliczbowego ``/``. Jego działanie dla liczb nieujemnych jest intuicyjne: ``5 / 2`` daje wartość ``2``, podobnie jak działanie poznanego już operatora reszty z dzielenia ``%``: obliczenie ``5 % 2`` daje wartość ``1``.

## Zadanie 1
Napisz program, który przy pomocy zagnieżdżonych pętli wypisze na ekran tabliczkę mnożenia dla liczb 1,2,3: <br>
<pre>
  1 2 3
1 1 2 3
2 2 4 6
3 3 6 9
</pre>

## Zadanie 2
Liczby Catalana C<sub>n</sub> to ważny ciąg w kombinatoryce i teorii grup wolnych. Jednym ze sposobów ich obliczania jest wzór C<sub>n</sub>=(2n)!/((n+1)!n!). Opracuj algorytm i napisz funkcję, która obliczy n-tą liczbę Catalana. Jeżeli potrzeba, możesz przyjąć, że n>=1. Napisz, skompiluj i uruchom program, który zilustruje jej działanie. Zastanów się nad algorytmem i pośrednimi wynikami obliczeń w kontekście ograniczeń na wielkość liczb całkowitych. Dla jakiego największego argumentu n wynik jest jeszcze poprawny? Czy da się to polepszyć?

## Zadanie 3
Opracuj algorytm i napisz funkcję, która dla zadanej liczby całkowitej bez znaku obliczy przy jakiej największej potędze dwójki w dwójkowym zapisie tej liczby stoi jedynka. Np. dla 17<sub>(10)</sub>=00000000000000000000000000010001<sub>(2)</sub> (zapisanej tu w 32-bitowej reprezentacji dwójkowej) najstarsza jedynka stoi przy 2<sup>4</sup>.
Zmień teraz typ argumentu z ``unsigned int`` na ``unsigned long``, i spróbuj skompilować i uruchomić swój program zarówno na 32-bitowym jak i na 64-bitowym komputerze przy pomocy gcc, np. na Windows i na Linux. W obliczeniu użyj liczby 9223372036854775808 (to jest 2<sup>63</sup>). Jakie wyniki otrzymałaś? Jeżeli nie masz dostępu do komputera z innym systemem, zapytaj kolegi/koleżanki, lub sprawdź w instytucie.

## Zadanie 4
Opracuj algorytm i napisz funkcję, która dla zadanej liczby całkowitej bez znaku, podstawy układu liczenia oraz wykładnika zwróci stosowny współczynnik w zapisie wartości tej liczby w układzie pozycyjnym o zadanej podstawie. Np. dla liczby 17, podstawy 10 i wykładnika 1 odpowiedzią jest oczywiście 1. Dla liczby 254, podstawy 16 i wykładnika 0 odpowiedzią jest 14, ponieważ 254=15\*16<sup>1</sup>+14\*16<sup>0</sup>.