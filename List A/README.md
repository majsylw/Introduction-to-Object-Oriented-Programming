# Zadania na laboratorium

## Zadanie 1
Uzupełnij klasę Trojmian z poprzedniej listy o unarne operatory ```+``` oraz ```-```, o operator ```*=``` pozwalający 
na domnożenie trójmianu przez liczbę, o dwa operatory mnożenia ```*``` pozwalające na mnożenie trójmianu przez liczbę 
z lewej i z prawej strony, o operator ```<``` definiujący porządek leksykograficzny (relacja przez niego określona 
na liczbach wymiernych jest Strict Weak Order, co więcej, klasy równoważności, o których była mowa na wykładzie, 
są jednoelementowe, więc ta równoważność jest w istocie relacją równości), i wszystkie pozostałe 
operatory porównywania ```>```, ```<=```, ```>=```, ```==```, ```!=``` zrealizuj bez osobnego liczenia 
a jedynie poprzez stosowne wywoływanie operatora ```<```.

Wyposaż klasę w metody pozwalające na znalezienie liczby zer danego trójmianu i ich obliczenie. 
Dobrze się zastanów ile trójmian może mieć zer. Do obliczania zastosuj wzory, 
które gwarantują poprawność numeryczną, znajdziesz je w pracy 
"What Every Computer Scientist Should Know About Floating Point Arithmetic".

Napisz funkcję testującą, która przynajmniej raz sprawdzi działanie każdej metody i funkcji.

## Zadanie 2
W pewnym pliku przechowywane są dane o czasie i położeniu pewnej cząstki, jako pary liczb zmiennoprzecinkowych 
o składni (czas;położenie), dopuszczamy rozdzielanie odstępami w dowolnym miejscu zapisu, przy czym nie mamy gwarancji, 
że każda para zajmuje osobny wiersz, dopuszczamy więcej par w wierszu i dopuszczamy pary, które zajmują więcej wierszy, 
np. ( w jednym, czas; w kolejnym i położenie) w trzecim. Ponadto po ostatniej parze może być jeszcze pewna ilość odstępów.
Napisz klasę Pomiar, która będzie reprezentowała pojedynczy pomiar położenia i czasu. 
Wyposaż ją w ```operator>>```, który posłuży przy wczytywaniu danych z pliku, o którym mowa wyżej.

Napisz klasę ```SeriaPomiarowa```, która będzie reprezentowała dane wczytane ze strumienia. Wyposaż ją w ```operator>>```, 
który podejmie próbę wczytania danych ze strumienia, i w przypadku pomyślnego wczytania punktów i wyczerpania 
zawartości strumienia przypisze wczytane dane na prawostronny argument, a w przeciwnym razie zwróci zepsuty strumień. 
(Na marginesie: tak napisany ```operator>>``` będzie poprawnie współpracował ze strumieniami plikowymi i napisowymi, 
ale nie z konsolą, ponieważ w strumieniu konsolowym nie ma naturalnego pojęcia końca strumienia). 
Napisz ten operator w taki sposób, żeby działał z dowolnym strumieniem danych o zadanym formacie, 
w szczególności, ilość punktów do przeczytania musi wynikać z zawartości danych i nie może być wpisana w kod programu.

Wyposaż klasę ```SeriaPomiarowa``` w metodę/metody pozwalające na odczytanie przechowywanego punktu pomiarowego 
o zadanym indeksie, oraz o metody obliczające przybliżenie pierwszej pochodnej (prędkości) ze wzoru

pp(i)=(y<sub>i+1</sub>-y<sub>i-1</sub>)/(t<sub>i+1</sub>-t<sub>i-1</sub>)

i drugiej (przyspieszenia) ze wzoru
dp(i)=2((t<sub>i</sub>-t<sub>i-1</sub>)\*(y<sub>i+1</sub>-y<sub>i</sub>) -(t<sub>i+1</sub>-t<sub>i</sub>)\*(y<sub>i</sub>-y<sub>i-1</sub>))/(t<sub>i+1</sub>-t<sub>i-1</sub>)

Oczywiście te dwie pochodne da się policzyć dla wszystkich punktów poza pierwszym i ostatnim.
Wyposaż swoją kolekcję w możliwość zapisu do pliku w formacie rozdzielanym średnikami, 
umieszczając w pierwszej kolumnie czas, w drugiej położenie, w trzeciej prędkość a w czwartej przyspieszenie, 
zostawiając puste te miejsca, gdzie prędkości i przyspieszenia nie da się policzyć.

Zastanów się jak to wszystko zrobić tak, aby była możliwość testowania wszystkich funkcji z wewnątrz funkcji testującej, 
bez wykorzystania zewnętrznych plików.

## Zadanie 3
Napisz klasę ```Macierz8```, która będzie reprezentowała macierze 8x8. Wyposaż ją w konstruktory swojego pomysłu, oraz w ```operator[]```, który będzie przyjmował obiekt zawierający dwie liczby całkowite, rozumiane jako współrzędne ze zbioru {1,...,8}, i zwracał współczynnik macierzy o zadanych współrzędnych. Wyposaż swoje macierze w dodawanie, mnożenie i ewentualnie inne operacje, które mogą być potrzebne do zrealizowania powyższych i/lub do demonstracji i testowania.
Napisz klasę ```Wektor8```, która będzie reprezentowała wektory (w sensie matematycznym) długości 8. Wyposaż ją w stosowne konstruktory i w ```operator[]```, który będzie przyjmował jedną liczbę całkowitą, rozumianą jako współrzędna ze zbioru {1,...,8}, i zwracał współczynnik wektora o tej współrzędnej. Wyposaż swoje wektory w dodawanie i ewentualnie inne operacje, które mogą być potrzebne do zrealizowania powyższych i/lub do demonstracji i testowania.

Uzupełnij swój program o mnożenie macierzy przez wektor. Postaraj się tak napisać całość, aby zmiana rozmiaru 8 na inny nie pociągała za sobą konieczności zrobienia dużych zmian w kodzie.