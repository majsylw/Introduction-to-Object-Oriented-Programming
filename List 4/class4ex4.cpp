/*
Napisz funkcję, która dla zadanej rocznej stopy procentowej, 
i całkowitej ilości lat obliczy czynnik kapitalizujący w procencie składanym 
z kapitalizacją co roku (czynnik kapitalizujący to jest wielkość, 
przez którą trzeba pomnożyć naszą kwotę początkową, żeby dostać kwotę końcową). 
Napisz program, który zapyta o saldo początkowe, stopę procentową oraz ilość lat, 
a następnie, korzystając z powyższej funkcji, będzie w stanie wyświetlić 
w konsoli saldo końcowe konta oszczędnościowego po zadanej ilości lat, 
przy założeniu stałej stopy procentowej. Przykład wyniku:
10000 odłożone na 3 lata na 5.0% da na koniec 11576.25.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>


double procentskladany(int lata, double procent)
{
    double czynnik_kapitalizujacy = std::pow(1+procent/100,lata);
    return czynnik_kapitalizujacy;
}

int main()
{


    std::cout<<"Podaj saldo poczatkowe: ";
    double poczatkowa=0.0;
    std::cin>>poczatkowa;
    std::cout<<std::endl<<"Podaj liczbe lat: ";
    int okres=0;
    std::cin>>okres;
    std::cout<<std::endl<<"Podaj stope procentowa (w procentach): ";
    double procent=0.0;
    std::cin>>procent;
    std::cout<<std::endl;

    double wynik = procentskladany(poczatkowa, okres, procent);

    std::cout << poczatkowa << " odlozone na "<<okres<<" lata na "<<procent<<"% da na koniec "<<std::setprecision(2)<<poczatkowa*wynik<<"." << std::endl;

    system("PAUSE");


    return 0;
}
