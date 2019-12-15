/*
Napisz funkcję, która sprawdzi, czy podany rok jest przestępny. 
Sprawdź od kiedy obowiązuje kalendarz gregoriański i które dokładnie lata są w nim przestępne. 
Możesz skorzystać z operatora koniunkcji: wartosc_logiczna1 && wartosc_logiczna2 jest prawdą 
wtedy i tylko wtedy gdy obie wartości są prawdą, 
alternatywy: wartosc_logiczna1 || wartosc_logiczna2 jest prawdą wtedy i tylko wtedy, 
gdy chociaż jedna z wartości jest prawdą, 
oraz negacji: !wartosc_logiczna jest prawdą wtedy i tylko wtedy, gdy wartość jest fałszem. 
Napisz program, który zilustruje działanie tej funkcji.
*/

#include <iostream>

using namespace std;

bool sprawdzenie(int rok)
{
    bool odpowiedz=false;
    if((rok%4 == 0 && rok%100 != 0) || rok%400 == 0)
        odpowiedz=true;
   return odpowiedz;
}

int main()
{
    int rok;
    cout<<"Podaj interesujacy Cie rok: ";
    cin>>rok;
    cout<<endl;

    if(sprawdzenie(rok))
        cout <<"Podany rok ("<<rok<<"r.) jest przestepny."<< endl;
    else
        cout <<"Podany rok ("<<rok<<"r.) nie jest jest przestepny."<< endl;

    cin.get();
    cout<<endl;
    cin.get();
    return 0;


}
