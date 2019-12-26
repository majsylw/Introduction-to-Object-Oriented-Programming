# Zadania na laboratorium

## Zadanie 1
Zdefiniuj klasę Trojmian, która będzie modelować trójmian, to znaczy wielomian co najwyżej drugiego stopnia. 
Wyposaż ją w stosowne konstruktory, między innymi taki, który pozwoli traktować liczby zmiennoprzecinkowe 
jako takie szczególne przypadki trójmianu, w których jedynie współczynnik stały (przy x<sup>0</sup>) jest niezerowy, 
oraz w metody:
- ```Wspolczynnik``` zwracającą wielkość współczynnika przy potędze zadanej parametrem do tej metody,
- ```operator()``` obliczającą wartość trójmianu w określonym punkcie przy pomocy algorytmu Hornera,
- ```operator+=``` dodającą dwa trójmiany (jako funkcje) zgodnie z logiką działania operatora ```+=```,
- ```operator-=``` odejmującą dwa trójmiany (jako funkcje) zgodnie z logiką działania operatora ```-=```,

Napisz wolnostojące dwuargumentowe operatory ```operator+``` oraz ```operator-``` realizujące 
dodawanie i odejmowanie trójmianów. Napisz również funkcję MniejWiecej, która sprawdzi, 
czy współczynniki dwóch trójmianów są z dobrym przybliżeniem równe. Napisz operator wejścia 
dla tej klasy, który będzie rozpoznawał trójmian zapisany w formacie ```"[1.0,2.0,3.0]"```, 
gdzie pierwsza liczba to współczynnik przy zerowej potędze itd. 
Możesz dopuścić spacje pomiędzy dowolnymi elementami tego zapisu. 
Przykłady użycia wszystkich opisanych wyżej usług są w testach poniżej. 
Wszystkie atrybuty klasy powinny być prywatne. Klasa powinna przejść następujące testy:

<pre>
auto test_Trojmian(void) -> void
  {
  Trojmian t1(1.0,2.0,3.0);
  assert(t1.Wspolczynnik(0)==1.0);
  assert(t1.Wspolczynnik(1)==2.0);
  assert(t1.Wspolczynnik(2)==3.0);
  assert(t1(0)==1.0);
  assert(t1(1)==6.0);
  Trojmian t1a;
  t1a=t1+Trojmian(2.0,3.0,4.0);
  assert(t1a.Wspolczynnik(0)==3.0);
  assert(t1a.Wspolczynnik(1)==5.0);
  assert(t1a.Wspolczynnik(2)==7.0);
  assert(MniejWiecej(t1,t1a-Trojmian(2.0,3.0,4.0)));
  Trojmian t1b=t1a;
  t1b-=Trojmian(2.0,3.0,4.0);
  assert(MniejWiecej(t1,t1b));
  t1+=Trojmian(2.0,3.0,4.0);
  assert(t1.Wspolczynnik(0)==3.0);
  assert(t1.Wspolczynnik(1)==5.0);
  assert(t1.Wspolczynnik(2)==7.0);
  assert(t1(0)==3.0);
  assert(t1(1)==15.0);
  assert(MniejWiecej(t1,Trojmian(3.0,5.0,7.0)));
  assert(!(MniejWiecej(t1,Trojmian(3.5,5.5,7.5))));
  Trojmian t2;
  t2=5.0;
  assert(t2.Wspolczynnik(0)==5.0);
  assert(t2.Wspolczynnik(1)==0.0);
  assert(t2.Wspolczynnik(2)==0.0);
  std::istringstream we("[1.0,2.0,3.0][3.5,4.5,-5.5]");
  we >> t1 >> t2;
  assert(we);
  assert(MniejWiecej(t1,Trojmian(1.0,2.0,3.0)));
  assert(MniejWiecej(t2,Trojmian(3.5,4.5,-5.5)));
  std::cerr << "test_Trojmian ok\n";
  }
</pre>

## Zadanie 2
Zdefiniuj klasę Wymierna modelującą liczbę wymierną. 
Wyposaż ją w stosowne konstruktory (nie zapominając o możliwości użycia liczb całkowitych w miejscach, 
gdzie oczekiwane są wymierne) oraz w metody:
- ```Licznik``` zwracającą skrócony licznik,
- ```Mianownik``` zwracającą skrócony mianownik,
- ```operator+=``` dodającą dwie liczby,
- ```operator-=``` odejmującą dwie liczby,
- ```operator*=``` mnożącą dwie liczby,
- ```operator/=``` dzielącą dwie liczby,

Skrócony mianownik powinien być dodatni, a znak liczby przetwarzany jako znak licznika. 
Napisz funkcję ```operator==```, która porówna dwie liczby wymierne (liczby a nie ich konkretne zapisy, 
zapis 2/4 jest inny niż 1/2, ale to jest ta sama liczba). Napisz operator wejścia, który będzie 
akceptował napisy postaci ```2/4```, ```3/-7``` ale wymagając, aby pomiędzy liczbą licznika a znakiem ```'/'``` 
i między znakiem ```'/'``` a liczbą mianownika nie było spacji. Napisz wolnostojące operatory dodawania, 
odejmowania, mnożenia i dzielenia. Wszystkie atrybuty klasy powinny być prywatne. Uzupełnij poniższe 
testy o testowanie wolnostojących operatorów arytmetycznych.

<pre>
auto test_Wymierna(void) -> void
  {
  Wymierna w1(2,-4);
  assert(w1.Licznik()==-1);
  assert(w1.Mianownik()==2);

  Wymierna w2;
  assert(w2.Licznik()==0);
  assert(w2.Mianownik()==1);

  Wymierna w3(2);
  assert(w3.Licznik()==2);
  assert(w3.Mianownik()==1);

  w1+=w3;
  assert(w1.Licznik()==3);
  assert(w1.Mianownik()==2);

  w1+=w3+=Wymierna(4,8);
  assert(w3.Licznik()==5);
  assert(w3.Mianownik()==2);
  assert(w1.Licznik()==4);
  assert(w1.Mianownik()==1);

  w1-=Wymierna(4,8);
  assert(w1.Licznik()==7);
  assert(w1.Mianownik()==2);

  w1=Wymierna(9,4);
  w1*=Wymierna(16,15);  // 9/4 * 16/15 = 3/1 * 4/5 = 12/5 = 144/60
  assert(w1.Licznik()==12);
  assert(w1.Mianownik()==5);

  w1/=Wymierna(16,15);
  assert(w1.Licznik()==9);
  assert(w1.Mianownik()==4);

  w1=3;
  assert(w1.Licznik()==3);
  assert(w1.Mianownik()==1);

  assert(w1==3);

  std::istringstream we("-6/8 10/-14");
  we >> w1 >> w2;
  assert(we);
  assert(w1==Wymierna(-3,4));
  assert(w2==Wymierna(-5,7));

  std::istringstream we2("-6 /8");
  we >> w1;
  assert(!we);
  }
</pre>