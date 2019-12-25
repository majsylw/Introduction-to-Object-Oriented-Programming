# Zadania na laboratorium

## Zadanie 1
Napisz funkcję, która dla dwóch obiektów reprezentujących daty kalendarza gregoriańskiego policzy ilość dni pomiędzy nimi. Przetestuj i zademonstruj. <br>
(*) Napisz teraz tę funkcję tak, aby wynik był otrzymywany przy pomocy odejmowania, tzn. jeżeli d oraz s są datami to wyrażenie d - s ma wartość równą ilości dni.

## Zadanie 2
Zdefiniuj strukturę Zespolona modelującą liczbę zespoloną. Wyposaż ją w konstruktor przyjmujący dwie liczby zmiennoprzecinkowe odpowiadające części rzeczywistej i części urojonej, w operator wyjścia, który liczbę wypisze w postaci 3.14-2.71i, oraz w operator wejścia, który będzie akceptował napisy tej samej postaci (pamiętaj o literze 'i' za częścią urojoną).

## Zadanie 3
Pewna firma prowadzi rekrutację na staż na podstawie średniej z ocen studenta oraz oceny działalności pozauczelnianej, również opisane liczbą rzeczywistą. Napisz strukturę, która będzie przechowywać dane pojedynczego kandydata, to znaczy powyższe dwie liczby oraz imię i nazwisko. Wyposaż ją w stosowny konstruktor oraz operator wyjścia. Napisz funkcję, która dla zadanego kandydata, progu na średnią i progu na aktywność obliczy, czy kandydat powinien być przyjęty.

## Zadanie 4
O numerze PESEL wiadomo, że:
<pre>
     Nasz pesel składa się z 11 cyfr. Sześć pierwszych to data 
urodzenia, natomiast pozostała kombinacja pięciu cyfr oznacza m.in. 
naszą płeć. Pesel urodzonych 1 stycznia 1900 roku zaczyna się od cyfr 00 
01 01. Czy istnieje zatem - choćby teoretyczna - możliwość, że urodzeni 
w pierwszy dzień 2000 roku będą mieć taki sam pesel jak osoby urodzone 
wiek wcześniej? - Taka sytuacja jest możliwa - twierdzi naczelnik 
Benczyński. - Dlatego osobom urodzonym w następnym stuleciu cyfrę z 
pierwszego "okienka" oznaczającego miesiąc urodzenia będziemy sumować z 
cyfrą 2, w kolejnym stuleciu z cyfrą 4 itd. 

     Pesel urodzonych 1 stycznia 2000 roku zaczynać się będzie od cyfr 
00 21 01, 31 grudnia 2000 roku - 00 32 31, 1 stycznia 2100 roku - 00 41 
01, 31 grudnia 2100 roku - 00 52 31 i analogicznie 1 stycznia 2300 - 00 
81 01, 31 grudnia 2399 roku - 99 92 31. 

     Do tego czasu nasi potomkowie będą mieć niepowtarzalny pesel. Co 
się stanie w 2400 roku? - O to niech się martwią następne pokolenia - 
mówią w ministerstwie.
</pre>

Napisz funkcję, która dla zadanego numeru PESEL wyprodukuje obiekt typu Data reprezentujący datę urodzenia z niego odczytaną. Wyposaż klasę Data w operator wyjścia, który pozwoli wypisać datę w formacie "28 czerwca 2010". Przetestuj na powyższych przykładach.
