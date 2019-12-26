# Zadania na laboratorium

## Zadanie 1
Napisz procedurę, która dla danego podzakresu kolekcji ```deque<int>``` znajdzie wartość minimalną, i zastąpi wszystkie wartości w tym podzakresie różnicą danej wartości i owej minimalnej. Nie wolno używać pętli ani rekursji, należy funkcję zaimplementować przy pomocy algorytmów z biblioteki standardowej (podpowiedź: ```min_element``` oraz ```transform``` lub ```for_each```). Przykładowy test do przejścia:
<pre>
void test_Odniesienie(void)
  {
  std::deque<int> d {-4, 5, 7,2, 8,-3,-5, 9, 9};
  std::deque<int> dd{ 1,10,12,7,13, 2, 0,14, 9};
  Odniesienie(std::begin(d),std::end(d)-1);
  assert(d==dd);
  }
</pre>
Uwaga: do użycia ```std::deque``` trzeba na początku zadeklarować użycie ```#include <deque>```

## Zadanie 2
Napisz funkcję, która dla danego podzakresu listy wielkości typu ```double```, reprezentujących oceny szkolne, obliczy średnią z tych ocen z tego podzakresu, które są pozytywne, tj. większe od jedynki. Nie wolno używać pętli ani rekursji, należy funkcję zaimplementować przy pomocy algorytmów z biblioteki standardowej (podpowiedź: ```accumulate``` oraz ```count_if```). Przykładowy test do przejścia:

<pre>
// Zmiana funkcji testującej 5.06 8:19
// Zmiana std::list na std::list<double> 7.06 18:00

void test_SredniaPozytywnych(void)
  {
  std::list<double> oceny{1,3,1,2,4,5,1,2};
  double s=SredniaPozytywnych(std::begin(oceny),--(std::end(oceny)));
  assert(s==3.5); // 3+2+4+5=14; 14.0/4==3.5, ostatnia 2 nie wchodzi
                  //             do średniej bo podzakres kończy się 
                  //             na przedostatniej ocenie
  }
</pre>
Ten test nie kompiluje się:
<pre>
void test_SredniaPozytywnych(void)
  {
  std::list oceny{1,3,1,2,4,5,1,2};
  double s=SredniaPozytywnych(std::begin(oceny),std::end(oceny)-1); // nie ma arytmetyki iteratorów do listy
  assert(s==3.5); // 3+2+4+5=14; 14.0/4==3.5, ostatnia 2 nie wchodzi
                  //             do średniej bo podzakres kończy się 
                  //             na przedostatniej ocenie
  }
</pre>
Uwaga: do użycia ```std::list``` trzeba na początku zadeklarować użycie ```#include <list>```

## Zadanie 3
Napisz procedurę, która zadany podwektor napisów typu ```std::string```, reprezentujący kolejne wpisy w logu pewnej aplikacji, posortuje zgodnie z porządkiem leksykograficznym działającym na pierwszym występującym haśle (ujętym w kwadratowe nawiasy) w napisie. Napisy bez haseł są równoważne między sobą i większe od napisów z hasłami, a różne napisy z takim samym pierwszym hasłem są równoważne. Należy zadbać o to, żeby nie zmienić względnej kolejności w grupach równoważnych napisów. Nie wolno używać pętli ani rekursji, należy funkcję zaimplementować przy pomocy algorytmów z biblioteki standardowej (podpowiedź: stable_sort, find oraz lexicographical_compare). Przykładowy test do przejścia:
<pre>
void test_SortujPoHaslach(void)
  {
  std::vector<std::string> d {"O 13 uruchomienie aplikacji",
                              "O 14 proba logowania haslem [madrehaslo] zakonczona powodzeniem",
                              "O 15 proba logowania haslem [glupiehaslo] zakonczona niepowodzeniem",
                              "O 15.30 restart aplikacji",
                              "Uzytkownik zmienil [madrehaslo] na [innehaslo] o 16",
                              "O 17 odmowa zmiany hasla na [aaaaaa] z powodu niedostateczego skomplikowania",
                              "O 18 chyba bledna proba zmiany hasla na puste []"};

  std::vector<std::string> ds{"O 18 chyba bledna proba zmiany hasla na puste []",
                              "O 17 odmowa zmiany hasla na [aaaaaa] z powodu niedostateczego skomplikowania",
                              "O 15 proba logowania haslem [glupiehaslo] zakonczona niepowodzeniem",
                              "O 14 proba logowania haslem [madrehaslo] zakonczona powodzeniem",
                              "Uzytkownik zmienil [madrehaslo] na [innehaslo] o 16",
                              "O 13 uruchomienie aplikacji",
                              "O 15.30 restart aplikacji"
                              };
  SortujPoHaslach(std::begin(d),std::end(d));
  assert(d==ds);
  }
</pre>