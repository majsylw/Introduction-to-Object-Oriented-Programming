/*
Napisz funkcję, która dla trzech podanych długości odcinków sprawdzi, 
czy można z tych odcinków zbudować trójkąt. Napisz program, który zilustruje jej działanie.
*/

#include <iostream>

bool trojkat(float bok1, float bok2, float bok3)
{
    return (bok1+bok2>bok3 && bok1+bok3>bok2 && bok2+bok3>bok1);
}

int main()
{
    float a=0,b=0,c=0;
    std::cout << "Podaj dlugosci bokow trojkata: " << std::endl;
    std::cin >> a >> b >> c;
    std::cout<<std::endl;
    if(trojkat(a,b,c))
        std::cout<<"Z danych odcinkow mozesz zbudowac trojkat.";
    else
        std::cout<<"Z danych odcinkow nie zbudujesz trojkata.";

    return 0;
}
