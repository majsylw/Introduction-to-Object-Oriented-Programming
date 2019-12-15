/*
Opracuj algorytm i napisz funkcję, która dla zadanej liczby całkowitej bez znaku, 
podstawy układu liczenia oraz wykładnika zwróci stosowny współczynnik 
w zapisie wartości tej liczby w układzie pozycyjnym o zadanej podstawie. 
Np. dla liczby 17, podstawy 10 i wykładnika 1 odpowiedzią jest oczywiście 1. 
Dla liczby 254, podstawy 16 i wykładnika 0 odpowiedzią jest 14, ponieważ 254=15*16^1+14*16^0.
*/

#include <iostream>

using namespace std;

int zamiana(unsigned int liczba,int podstawa,int wykladnik)
{
    int reszta=0,i=-1;
    do
    {
        reszta=liczba%podstawa;
        liczba=liczba/podstawa;
        i++;
    } while(i!=wykladnik);
    return reszta;
}

int main()
{
   /* unsigned int liczba;
    cout<<"Podaj liczbe: ";
    cin>>liczba;
    cout<<endl;
    int podstawa;
    cout<<"Podaj podstawe: ";
    cin>>podstawa;
    cout<<endl;
    int wykladnik;
    cout<<"Podaj wykladnik: ";
    cin>>wykladnik;
    cout<<endl; */

    cout<<zamiana(4294967296,10,5);

    cin.get();
    cout<<endl;
    cin.get();

    return 0;
}
