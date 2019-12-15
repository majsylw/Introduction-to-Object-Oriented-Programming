/*
Opracuj algorytm obliczania zadanej n-tej naturalnej potęgi (przy założeniu n>0) zadanej liczby
całkowitej m, mając do dyspozycji operację mnożenia *, tzn. określ liczbę i typy argumentów, typ
wyniku, kroki prowadzące do wyniku. Napisz funkcję, która obliczy tę potęgę. Skompiluj i uruchom
program, który wyświetli obliczony wynik dla argumentów podanych w kodzie programu. Skomentuj
wyniki.
*/

#include <iostream>

using namespace std;

int potega(int n, int m) {
    int i = 1;
    int potega = n;
    if (m==0) return 1;
    do {
        potega = potega * n;
        i = i + 1;
    }
    while(i < m);
    return potega;
}

int main() {
    int n = 4;
    int m = 2;
    cout << m << "-ta potega liczby " << n << " wynosi " << potega(n,m);
    cin.get();
    return 0;
}
