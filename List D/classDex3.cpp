/*
Napisz procedurę Sortuj3Wskazniki, której argumentem będzie tablica wskaźników do napisów (czyli wskaźnik do tablicy 
wskaźników). Zakładamy, że tych napisów jest dokładnie 3. Procedura zmodyfikuje tę tablicę wskaźników zgodnie 
z porządkiem leksykograficznym napisów, na które one wskazują (ponieważ do posortowania mamy zawsze trzy i tylko 
trzy wielkości, algorytm sortujący nie musi być zbyt wyrafinowany).
*/

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <ctime>

bool czy_posortowana(std::string* a[])
{
    int n = 3;

    for(int i = 0; i < n-1; ++i)
    {
        if(*a[i] > *a[i+1])
            return false;
    }

    return true;
}

void permutacja(std::string* a[])
{
    int n = 3;
    /*std::string* t;
    int r = 0;*/

    for(int i=0; i < n; i++)
    {
        /*t = a[i];
        r = rand() % n;
        a[i] = a[r];
        a[r] = t;*/
        swap(a[i],a[rand()%n]);
    }

}

void bogosort(std::string* a[], int n)
{
    //int i = 0;
    while (!czy_posortowana(a))
    {
        permutacja(a);
        //++i;
    }
    //std::cout << i << std::endl;
}

void Sortuj3Wskazniki(std::string* tab[3])
{
    assert(tab != nullptr);
    int n = 3;

    bogosort(tab,n);
}

/*void Sortuj3Wskazniki(std::string* tab[3])
{
    assert(tab != nullptr);
    int n = 3;
    //std::string* pom = nullptr;

    for(int i=0; i<n-1; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            if(*tab[i]>*tab[j])
            {
                swap(tab[i],tab[j]);
                //pom=tab[i];
                //tab[i]=tab[j];
                //tab[j]=pom;
            }
        }
    }
}*/

auto test_Sortuj3Wskazniki(void) -> void
{
  std::string napisy[]={"Dabacki","Babacki","Abacki"};
  std::string* wskazniki[]={napisy,napisy+1,napisy+2};

  Sortuj3Wskazniki(wskazniki);

  assert(napisy[0]=="Dabacki");
  assert(napisy[1]=="Babacki");
  assert(napisy[2]=="Abacki");

  assert(*(wskazniki[0])=="Abacki");
  assert(*(wskazniki[1])=="Babacki");
  assert(*(wskazniki[2])=="Dabacki");

  std::cerr << "test_Sortuj3Wskazniki ok\n";
}

int main()
{
    srand(time(NULL));

    test_Sortuj3Wskazniki();

    std::cin.get();

    return 0;
}
