/* Napisz procedure, ktora wyswietli wszystkie dlugosci bokow i wszystkie wielksci katow (w stopniach) trojkata prostokatnego
dla dwoch argumentow: dlugosci przyprostokatnej oraz wielkosci kata (w stopniach) nieprzylegajacego do tej przyprostokatnej.
Napisz program, ktory zapyta uzytkownika o dane, a nastepnie wywola te procedure. */

#include <iostream>
#include <cmath>

void sprawdzenie(double przyprostokatna1, double katAlpha)
{
    std::cout<<std::endl<<"Pozostale parametry tego trojkata wynosza odpowiednio: "<<std::endl;
    double katBeta=90-katAlpha;
    double przeciwprostokatna=przyprostokatna1/std::sin((katAlpha*M_PI)/180);
    double przyprostokatna2=przyprostokatna1/std::tan((katAlpha*M_PI)/180);

    std::cout<<"Pozostale katy: 90 stopni i "<<katBeta<<" stopni."<<std::endl;
    std::cout<<"Przeciwprostokatna: "<<przeciwprostokatna<<std::endl;
    std::cout<<"Druga przyprostokatna: "<<przyprostokatna2<<std::endl;

}

int main()
{
    std::cout<<"Program podajacy mozliwe dlugosci bokow i wielkosci katow trojkata prostokatnego."<<std::endl;
    std::cout<<"Podaj dlugosc przyprostokatnej: ";
    double a=0;
    std::cin>>a;
    std::cout<<std::endl<<"Podaj wielkosc kata nieprzylegajacego do tej przyprostokatnej (w stopniach): ";
    double alpha=0;
    std::cin>>alpha;

    sprawdzenie(a,alpha);

    return 0;
}
