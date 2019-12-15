/*
 Opracuj iteracyjny (tj. z użyciem pętli) algorytm obliczania n-tej liczby Fibonacciego dla n>0
(F(0)=1, F(1)=1, F(n)=F(n-1)+F(n-2) dla n≥2). tzn. określ ilość i typy argumentów, typ wyniku, kroki
prowadzące do wyniku. Użyj stanu i pętli, nie używaj rekursji (tzn. nie wywołuj funkcji z wewnątrz
jej własnej definicji). Napisz funkcję, która obliczy zadaną n-tą liczbę Fibonacciego. Skompiluj i
uruchom program, który wyświetli obliczony wynik dla argumentu podanego w kodzie programu.
Skomentuj wyniki dla dużych argumentów.
*/

#include <iostream>

using namespace std;

int fibonacci(int n) {
    int i = 0;
    int poprzednik = 0, liczba = 1;
    if (n==0) return 1;
    do {
        liczba = liczba + poprzednik;
        poprzednik = liczba - poprzednik;
        i = i + 1;
    }
    while(i != n);
    return liczba;
}

int main() {
    int n = 45;
    if (n <= 0) cout << "Podana liczba musi byc dodatnia!";
    else cout << n << "-ta liczba w ciagu Fibonacciego to: " << fibonacci(n);
    cin.get();
    return 0;
}
