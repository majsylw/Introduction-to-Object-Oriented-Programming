# Zadania na laboratorium

## Zadanie 1
Napisz procedurę, która wyświetli wszystkie długości boków i wszystkie wielkości kątów (w stopniach) trójkąta prostokątnego dla dwóch argumentów: długości przyprostokątnej oraz wielkości kąta (w stopniach) nieprzylegającego do tej przyprostokątnej. Napisz program, który zapyta użytkownika o dane, a następnie wywoła tę procedurę.

## Zadanie 2
Napisz funkcję, która dla trzech podanych długości odcinków sprawdzi, czy można z tych odcinków zbudować trójkąt. Napisz program, który zilustruje jej działanie.

## Zadanie 3
W matematyce i zastosowaniach bardzo ważną funkcją jest całka z f(x)=e<sup>-x<sup>2</sup></sup>. Niestety, nie da się takiej całki zapisać przy pomocy funkcji elementarnych, trzeba jej wartości obliczać numerycznie. Zadanie polega na napisaniu funkcji, która będzie obliczać całkę oznaczoną z f(x)=e<sup>-x<sup>2</sup></sup> na zbiorze [0,t], gdzie t będzie zadaną dodatnią liczbą. Obliczenia należy przeprowadzić metodą trapezów na równo rozłożonych ```N``` węzłach, to znaczy dzielimy zbiór [0,t] na ```N-1``` równych pododcinków o końcach w punktach: 0=x<sub>1</sub>,x<sub>2</sub>,...,x<sub>N-1</sub>,x<sub>N</sub>=t, i dla każdego pododcinka obliczamy pole trapezu ograniczonego punktami (x<sub>i</sub>,0), (x<sub>i</sub>,f(x<sub>i</sub>)),(x<sub>i+1</sub>,f(x<sub>i+1</sub>)),(x<sub>i+1</sub>,0). Całka po całym przedziale jest sumą oszacowań dla każdego podprzedziału. ```N``` powinno być drugim argumentem pisanej funkcji. Oceń jakość tego oszacowania dla różnych ```t``` i ```N``` porównując wartości z wynikiem działania funkcji ```std::erf``` z biblioteki ```cmath```.

## Zadanie 4
Napisz funkcję, która dla zadanej rocznej stopy procentowej, i całkowitej ilości lat obliczy czynnik kapitalizujący w procencie składanym z kapitalizacją co roku (czynnik kapitalizujący to jest wielkość, przez którą trzeba pomnożyć naszą kwotę początkową, żeby dostać kwotę końcową). Napisz program, który zapyta o saldo początkowe, stopę procentową oraz ilość lat, a następnie, korzystając z powyższej funkcji, będzie w stanie wyświetlić w konsoli saldo końcowe konta oszczędnościowego po zadanej ilości lat, przy założeniu stałej stopy procentowej. Przykład wyniku:
<pre>
10000 odłożone na 3 lata na 5.0% da na koniec 11576.25.
</pre>