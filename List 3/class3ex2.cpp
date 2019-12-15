/*
Napisz funkcję, która dla zadanej liczby naturalnej n≥0 znajdzie największą liczbę naturalną m, taką że m^2 ≤ n. 
Wskazówka: funkcja k^2 jest rosnąca, i wiadomo, że m leży gdzieś w przedziale [0,n]. 
Patrzymy zatem na liczbę naturalną zbliżoną do połowy przedziału [0,n], i jeżeli spełnia nasz warunek, 
to mamy rozwiązanie, jeżeli jest za duża, to wiemy, że m leży pomiędzy 0 a tą połową, 
jeżeli zaś jest za mała, to m leży pomiędzy tą połową a n. Jeżeli nie mamy rozwiązania i liczymy dalej, 
wiemy, że rozwiązanie jest w nowym, krótszym przedziale. Ponownie patrzymy na środek, itd. 
Postępując w ten sposób zawsze znajdziemy odpowiedź. Zastosuj opisany tu algorytm.
*/

#include <iostream>
#include<limits>


using namespace std;

int najw_naturalna(int n)
{
    if (n<=1) return n;
    int poczatek=0,koniec=n,m=0;

    while( m*m != n)
    {
        if( (koniec-poczatek)<=1 ) return poczatek;
        m = (koniec+poczatek)/2;
        if(m*m <= n)
            poczatek = m;
        else
            koniec = m;
    }

    return m;
}


int main()
{
    /*for(int i=0; i < 60; ++i) {
        cout << i << " < - > " << najw_naturalna(i) << endl;
    }*/
    cout << najw_naturalna(78) << endl;

    cin.clear();
    cin.ignore(numeric_limits<int>::max(), '\n');
    cin.get();
    return 0;
}
