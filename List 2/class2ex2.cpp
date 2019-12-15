/*
Liczby Catalana Cn to ważny ciąg w kombinatoryce i teorii grup wolnych. 
Jednym ze sposobów ich obliczania jest wzór Cn=(2n)!/((n+1)!n!). 
Opracuj algorytm i napisz funkcję, która obliczy n-tą liczbę Catalana. 
Jeżeli potrzeba, możesz przyjąć, że n>=1. Napisz, skompiluj i uruchom program, 
który zilustruje jej działanie. Zastanów się nad algorytmem i pośrednimi wynikami obliczeń 
w kontekście ograniczeń na wielkość liczb całkowitych. Dla jakiego największego argumentu n 
wynik jest jeszcze poprawny? Czy da się to polepszyć?
*/

#include <iostream>

using namespace std;

unsigned long long int silnia(int m)
{
    unsigned long long int wynik = 1; # polepszenie wyniku -> typ unsigned long long
    if (m==0) return wynik;
    do
    {
        wynik = wynik * m;
        m = m - 1;
    }
    while( m!=0 );
    return wynik;
}

int catalan(int k)
{
    return silnia(2*k)/(silnia(k+1)*silnia(k));
}

int c(int m)
{
    unsigned long long int dzielna = 1,dzielnik=1,k=m,i=2*m;
    if (m==0) return dzielna;
    do
    {
        dzielna = dzielna * i;
        i= i - 1;
    }
    while( i!=0 );
    do
    {
        dzielnik = dzielnik * k;
        k = k - 1;
    }
    while( k!=0 );

    return dzielna/(dzielnik*(dzielnik*(m+1)));
}

int catal(int n)
{
    if(n==0) return 1;
    unsigned int suma=0,i=0;
    do
    {
        suma=suma+catal(i)*catal(n-i-1);
        i++;
    } while(i<=n-1);
    return suma;
}
int main()
{
    int a;
    cout << "Podaj indeks dla ktorego chcesz obliczy wartosc liczby Catalana = Cn." << endl;
    cout << "Wprowadz n = ";
    cin >> a;
    cout << "Liczba Catalana dla podanego indeksu n="<<a<<" wynosi: "<<catal(a)<<endl<<catalan(a)<<endl<<c(a);

    cin.get();
    cout<<endl;
    cin.get();
    return 0;
}
