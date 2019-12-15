/*
Opracuj algorytm obliczania wielkoœci n!! (przy za³o¿eniu n>0), okreœlonej jako n!!=n*(n2)*...*(n-2k)
dla dodatnich czynników, czyli np. 6!!=6*4*2, 7!!=7*5*3*1, tzn. okreœl liczbê i typy
argumentów, typ wyniku, kroki prowadz¹ce do wyniku. Napisz funkcjê, która obliczy tê funkcjê.
Skompiluj i uruchom program, który wyœwietli obliczony wynik dla argumentu podanego w kodzie
programu. Skomentuj wyniki dla du¿ych argumentów.
*/

#include <iostream>

using namespace std;

int podwojna_silnia(int n) {
    int wynik = 1;
    do {
        wynik = wynik * n;
        n = n - 2;
        //cout<<n<<endl;
    }
    while( n>=1 );
    return wynik;
}

int main() {
    int n = 5;
    if ( n > 0) {
        cout << n << "!! = " << podwojna_silnia(n);
    }
    else
        cout << "Podana liczba musi byc naturalna!";

    return 0;
    cin.get();
}
