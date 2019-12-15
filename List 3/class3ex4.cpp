/*
Napisz program, który przy pomocy zagnieżdżonych pętli wypisze na ekran tabliczkę mnożenia w układzie pozycyjnym o zadanej podstawie, z zachowaniem układu kolumn. Np. dla podstawy 8:

    1  2  3  4  5  6  7  10 
 1  1  2  3  4  5  6  7  10 
 2  2  4  6 10 12 14 16  20 
 3  3  6 11 14 17 22 25  30 
 4  4 10 14 20 24 30 34  40 
 5  5 12 17 24 31 36 43  50 
 6  6 14 22 30 36 44 52  60 
 7  7 16 25 34 43 52 61  70 
10 10 20 30 40 50 60 70 100
*/

#include <iostream>
#include<iomanip>

using namespace std;

int sprawdzenie(unsigned int liczba, int podstawa)
{
    int i=0;
    while (liczba>podstawa-1)
    {
      liczba=liczba/podstawa;
      i++;
    } ;
    return i;
}

int pozycyjny(unsigned int liczba,int podstawa,int wykladnik)
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


void zapis(unsigned int liczba,int podstawa)
{
    int wykladnik=sprawdzenie(liczba,podstawa);
    while(wykladnik!=-1)
    {
        cout<<pozycyjny(liczba,podstawa,wykladnik);
        wykladnik=wykladnik-1;

    }

}

int main()
{
    int podstawa=0;
    cout<<"Podaj podstawe systemu pozycyjnego: ";
    cin>>podstawa;
    cout<<endl<<"Oto tabliczka mnozenia:"<<endl;

    int i=1,j=1;
    cout<<" \t";
    do
    {
        zapis(j*i,podstawa);
        cout<<"\t";
        i++;
    } while(i<=podstawa);
    i=1;
    do
    {
        j=1;
        cout<<endl;
        zapis(i,podstawa);
        cout<<"\t";
        do
        {
            zapis(j*i,podstawa);
            cout<<"\t";
            j++;
        } while(j<=podstawa);
        i++;
    } while(i<=podstawa);

    cin.get();
    cout<<endl;
    cin.get();
    return 0;
}
