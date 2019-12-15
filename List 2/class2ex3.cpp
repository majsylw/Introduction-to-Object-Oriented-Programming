/*
Opracuj algorytm i napisz funkcj�, kt�ra dla zadanej liczby ca�kowitej bez znaku obliczy
przy jakiej najwi�kszej pot�dze dw�jki w dw�jkowym zapisie tej liczby stoi jedynka.
Np. dla 17(10)=00000000000000000000000000010001(2) (zapisanej tu w 32-bitowej reprezentacji dw�jkowej)
najstarsza jedynka stoi przy 2^4. Zmie� teraz typ argumentu z unsigned int na unsigned long,
i spr�buj skompilowa� i uruchomi� sw�j program zar�wno na 32-bitowym jak i na 64-bitowym komputerze
przy pomocy gcc, np. na Windows i na Linux. W obliczeniu u�yj liczby 9223372036854775808 (to jest 2^63).
Jakie wyniki otrzyma�a�? Je�eli nie masz dost�pu do komputera z innym systemem, zapytaj kolegi/kole�anki, lub sprawd� w instytucie.
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
