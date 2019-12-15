/*
Napisz procedurę (czyli funkcję, która nie oblicza wartości, ale ma interesujący nas efekt uboczny), 
która wyświetli cyfry zadanej liczby naturalnej w zapisie pozycyjnym o zadanej podstawie, w naturalnej kolejnośći, 
tzn. np. 25(10) w zapisie przy podstawie 8 da 31, bo 25(10) = 8^1*3+8^0*1. Nie obliczaj tych cyfr wewnątrz tej procedury, 
skorzystaj z funkcji z jednej z poprzednich list. Napisz program, który zapyta użytkownika o liczbę naturalną, 
wywoła tę procedurę, a następnie zapyta użytkownika, czy chce podać jeszcze jedną liczbę (przy pomocy wpisania 0 lub 1). 
Jeżeli odpowiedź użytkownika będzie na tak, program przejdzie znów cały cykl wprowadzenie danej-wypisanie wyniku-pytanie 
o kontynuację. Jeżeli odpowiedź będzie na nie to program podziękuje i skończy pracę. 
UWAGA (dopisane 13.03): interesują nas w tym i następnym zadaniu wyłącznie układy pozycyjne o podstawach od 2 do 10 włącznie.
*/

#include <iostream>

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

int main(void)
{
    bool odp=true;
    while(odp)
    {
        cout<<"Podaj liczbe w systemie dziesietnym: ";
        int liczba=0;
        cin>>liczba;
        cout<<endl<<"Podaj podstawe systemu pozycyjnego: ";
        int podstawa;
        cin>>podstawa;

        cout<<liczba<<" = ";
        zapis(liczba,podstawa);
        cout<<endl<<"Chcesz podac jeszcze jedna liczbe? (Podaj odpowiedz w formie 0 lub 1) ";
        cin>>odp;
    }

    cout<<endl<<"Nasza wspolpraca dobiegla wiec konca. Do widzenia.";


    cin.get();
    cout<<endl;
    cin.get();
    return 0;
}
