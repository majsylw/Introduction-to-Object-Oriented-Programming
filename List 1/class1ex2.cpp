/*
Opracuj algorytm obliczania wielko�ci n!! (przy za�o�eniu n>0), okre�lonej jako n!!=n*(n2)*...*(n-2k)
dla dodatnich czynnik�w, czyli np. 6!!=6*4*2, 7!!=7*5*3*1, tzn. okre�l liczb� i typy
argument�w, typ wyniku, kroki prowadz�ce do wyniku. Napisz funkcj�, kt�ra obliczy t� funkcj�.
Skompiluj i uruchom program, kt�ry wy�wietli obliczony wynik dla argumentu podanego w kodzie
programu. Skomentuj wyniki dla du�ych argument�w.
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
