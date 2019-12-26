## Uzupełnienie wykładu

Na wykładzie powiedziałem, że jeżeli nie określimy sami stosownej sekcji ```private:``` albo ```public:```, to w strukturze (tzn. nowym typie definiowanym przy pomocy słowa kluczowego ```struct```) będzie tak, jakby na początku stało ```public:```

Nowy typ danych można definiować również używając słowa kluczowego class zamiast struct, jedyna różnica polega na tym, że jeżeli nie określimy sami stosownej sekcji ```private:``` albo ```public:```, to w klasie będzie tak, jakby na początku stało ```private:```

Skoro jedno i drugie słowo kluczowe ma w istocie takie samo działanie, decydująca przy wyborze jest utarta praktyka. Najczęściej przy pomocy ```struct``` definiuje się proste typy danych bez kontroli niezmiennika i z publicznymi atrybutami, a przy pomocy ```class``` wszelkie inne bardziej skomplikowane przypadki.

# Zadania na laboratorium

## Zadanie 1
Zdefiniuj klasę Osoba, która będzie modelować informacje o imionach, nazwisku i dacie urodzenia danej osoby. Wyposaż ją w konstruktory przyjmujące datę urodzenia pod postacią obiektu stosownego typu oraz trzy napisy, nazwisko i jeden lub dwa reprezentujące imiona (przyjmujemy, że jeżeli argument odpowiadający drugiemu imieniu jest napisem pustym, to oznacza to brak drugiego imienia). Wszystkie atrybuty obiektów klasy powinny być prywatne. Wyposaż klasę w metody:
- ```IleImion``` zwracającą 1 lub 2 w zależności od ilości imion,
- ```Imie``` zwracającą napis zawierający pierwsze imię,
- ```Imiona``` zwracającą napis zawierający imiona, lub tylko pierwsze imię, jeżeli nie ma drugiego,
- ```Nazwisko``` zwracającą napis zawierający nazwisko,
- ```ImionaINazwisko``` zwracającą napis zawierający pełne imiona i nazwisko,
- ```InicjalyINazwisko``` zwracającą napis zawierający inicjały (inicjał) i nazwisko,
- ```DataUrodzenia``` zwracającą datę urodzenia,
- ```Wiek``` zwracającą wiek osoby w dniu określonym datą przekazaną w parametrze.

Klasa powinna przejść następujące testy:
<pre>
void test_Osoba(void)
  {
  Osoba jkw(Data(1922,2,24), "Wscieklica", "Jan", "Karol");
  assert(jkw.IleImion()==2);
  assert(jkw.Imie()=="Jan");
  assert(jkw.Imiona()=="Jan Karol");
  assert(jkw.Nazwisko()=="Wscieklica");
  assert(jkw.ImionaINazwisko()=="Jan Karol Wscieklica");
  assert(jkw.InicjalyINazwisko()=="J. K. Wscieklica");
  assert(jkw.DataUrodzenia()==Data(1922,2,24));
  assert(jkw.Wiek(Data(2014,4,16))==92);

  const Osoba aa(Data(2013,4,16), "Abacki", "Adam");
  assert(aa.IleImion()==1);
  assert(aa.Imie()=="Adam");
  assert(aa.Imiona()=="Adam");
  assert(aa.Nazwisko()=="Abacki");
  assert(aa.ImionaINazwisko()=="Adam Abacki");
  assert(aa.InicjalyINazwisko()=="A. Abacki");
  assert(aa.DataUrodzenia()==Data(2013,4,16));
  assert(aa.Wiek(Data(2013,12,31))==0);
  assert(aa.Wiek(Data(2014,4,16))==1);
  }
</pre>

## Zadanie 2

Zdefiniuj klasę Zespolona modelującą liczbę zespoloną. Wyposaż ją w konstruktor domyślny ustawiający wartość liczby na zero oraz konstruktory przyjmujące jedną lub dwie liczby zmiennoprzecinkowe odpowiadające części rzeczywistej i części urojonej (w razie podania tylko części rzeczywistej przyjmujemy, że urojona jest równa zero) oraz w metody:
- ```Re``` zwracającą część rzeczywistą liczby,
- ```Im``` zwracającą część urojoną liczby,
- ```Abs``` zwracającą moduł liczby,
- ``Arg``` zwracającą argument (kąt) liczby w radianach
- ```Tekst``` zwracającą napis reprezentujący liczbę, o postaci a+bi (zamiast a i b stosowne wielkości)

Wszystkie atrybuty obiektów typu Zespolona powinny być prywatne. Zastanów się, czy przechowywanie jako atrybutów części rzeczywistej i urojonej jest jedynym sposobem na zrealizowanie powyższego inferfejsu.

Napisz operator wejścia akceptujący liczby w formacie a+bi, pamiętaj o sprawdzeniu, czy na pewno po części urojonej wpisano 'i' oraz spróbuj sprawdzić, czy na pewno pomiędzy liczbami jest plus lub minus (tu może Ci się przydać omawiany już na laboratoriach manipulator std::ws z biblioteki iomanip oraz metody strumienia peek albo unget zdefiniowane w klasie std::basic_istream i przy niej udokumentowane).
Napisz operator wyjścia korzystający z metody ```Tekst```.

Napisz funkcję testującą konstruktor i wszystkie metody i funkcje.

## Zadanie 3

Znajdź w sieci informacje o cyfrze kontrolnej i kodowaniu płci w numerze PESEL. Napisz funkcję, która sprawdzi, czy data urodzenia zawarta w numerze przekazanym jako napis jest sensowna, i która zwróci stosowną wartość logiczną. Napisz drugą funkcję, która sprawdzi, czy cyfra kontrolna zawarta w numerze również przekazanym jako napis jest poprawna, i która zwróci stosowną wartość logiczną.

Zdefiniuj klasę ```PESEL``` reprezentującą numery PESEL. Wyposaż ją w konstruktor przyjmujący napis. Upewnij się w konstruktorze, że data zawarta w przekazanym napisie jest sensowna, natomiast nie wymagaj poprawnej cyfry kontrolnej.

Wyposaż obiekty tej klasy w metody:

- ```Numer``` zwracającą cały numer jako napis
- ```DataUrodzenia``` zwracającą datę urodzenia zakodowaną w numerze
- ```CzyKobieta``` zwracającą wartość logiczną odpowiadającą na zadane pytanie
- ```CzyPoprawny``` zwracającą wartość logiczną informującą czy cyfra kontrolna jest poprawna

Napisz operator wyjścia oraz operator wejścia dla obiektów tej klasy. Spróbuj napisać operator wejścia w taki sposób, aby jako poprawne wejście odczytywać kolejne 11 cyfr (tzn. ciąg cyfr krótszy powinien być rozumiany jako niewłaściwy, a w przypadku dłuższego operator powinien zdjąć ze strumienia pierwszych 11 cyfr a pozostałe zostawić i pozwolić ewentualnej kolejnej operacji wczytywania z tego samego strumienia na ich interpretację).

Napisz funkcję, która zapyta użytkownika konsoli o PESEL, podejmie próbę wczytania go, i w przypadku niepowodzenia (złe litery lub zła data) ponowi próbę, a w przypadku złej cyfry kontrolnej zapyta, czy użytkownik na pewno taki ma przydzielony, i pozwoli mu albo na potwierdzenie albo na ponowienie próby.

Napisz testy wszystkich funkcji, które do testów się nadają.