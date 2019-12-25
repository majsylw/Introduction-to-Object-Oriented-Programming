/*
W matematyce i zastosowaniach bardzo wazna funkcja jest calka z f(x)=e^(-x^2).
Niestety, nie da sie takiej calki zapisac przy pomocy funkcji elementarnych,
trzeba jej wartosci obliczac numerycznie. Zadanie polega na napisaniu funkcji,
która bêdzie obliczac calke oznaczona z f(x)=e^(-x^2) na zbiorze [0,t], gdzie t bedzie zadana dodatnia liczba.
Obliczenia nalezy przeprowadzic metoda trapezów na równo rozlozonych N wezlach,
to znaczy dzielimy zbiór [0,t] na N-1 równych pododcinków o koncach w punktach: 0=x1,x2,...,xN-1,xN=t,
i dla kazdego pododcinka obliczamy pole trapezu ograniczonego punktami (xi,0), (xi,f(xi)),(xi+1,f(xi+1)),(xi+1,0).
Calka po calym przedziale jest suma oszacowan dla kazdego podprzedzialu. N powinno byc drugim argumentem pisanej funkcji.
Ocen jakosc tego oszacowania dla roznych t i N porównujac wartosci z wynikiem dzialania funkcji std::erf z biblioteki cmath.
*/

#include <iostream>
#include <cmath>


double MetodaTrapezow(int N, double t)
{
    double suma=0.0,x=0.0;
    double h=t/(N-1);

    while(x+h<=t)
    {
       suma=suma+(std::exp(-1*std::pow(x,2))+std::exp(-1*std::pow((x+h),2)))/2*h;
       x=x+h;
    }
    return suma;
}

int main()
{
    std::cout << "N \t t \t Metoda \t erf " << std::endl;
    for (int i=30;i<=70;i++)
    {
        for(double x=0.1;x<=3.1;x=x+0.5)
        {
            std::cout << i << "\t" << x  << "\t" << MetodaTrapezow(i,x) << "\t" << erf(x)*std::sqrt(M_PI)/2 << std::endl;
        }
    }

    return 0;
}
