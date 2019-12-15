/*
Opracuj algorytm i napisz funkcjê, która dla zadanej liczby ca³kowitej bez znaku obliczy
przy jakiej najwiêkszej potêdze dwójki w dwójkowym zapisie tej liczby stoi jedynka.
Np. dla 17(10)=00000000000000000000000000010001(2) (zapisanej tu w 32-bitowej reprezentacji dwójkowej)
najstarsza jedynka stoi przy 2^4. Zmieñ teraz typ argumentu z unsigned int na unsigned long,
i spróbuj skompilowaæ i uruchomiæ swój program zarówno na 32-bitowym jak i na 64-bitowym komputerze
przy pomocy gcc, np. na Windows i na Linux. W obliczeniu u¿yj liczby 9223372036854775808 (to jest 2^63).
Jakie wyniki otrzyma³aœ? Je¿eli nie masz dostêpu do komputera z innym systemem, zapytaj kolegi/kole¿anki, lub sprawdŸ w instytucie.
*/

#include <iostream>

using namespace std;

int sprawdzenie(unsigned long liczba)
{
    int i=0;
    do
    {
      liczba=liczba/2;
      i++;
    } while (liczba>1);
    return i;
}

int main(void)
{
    unsigned long a=9223372036854775808;
    cout<<sprawdzenie(a);
    cin.get();
    return 0;
}
