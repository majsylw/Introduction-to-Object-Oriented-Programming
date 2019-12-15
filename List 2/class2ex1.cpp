/*
Napisz program, który przy pomocy zagnieżdżonych pętli wypisze na ekran tabliczkę mnożenia dla liczb 1,2,3:
  1 2 3
1 1 2 3
2 2 4 6
3 3 6 9
*/


#include <iostream>

using namespace std;

int main()
{
    int i=1,j=1;
    cout<<"  ";
    do
    {
        cout<<j*i<<" ";
        i++;
    } while(i<=3);
    i=1;
    do
    {
        j=1;
        cout<<endl<<i<<" ";
        do
        {
            cout<<j*i<<" ";
            j++;
        } while(j<=3);
        i++;
    } while(i<=3);

    cin.get();
   return 0;
}
