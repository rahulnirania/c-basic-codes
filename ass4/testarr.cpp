#include <iostream>
using namespace std;

main()
{
    /*int* arr[2] = new int[2][2];
    arr[0] = 2;
    arr[1] = 5;
    cout<<arr[0]<<"\t"<<arr[1];*/
    int** ary = new int*[5];
    int t=0;
for(int i = 0; i < 5; ++i)
    ary[i] = new int[4];
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<4; j++)
        {   ary[i][j]= t;
            t++;
        }
    }
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<4; j++)
        {   cout<<ary[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
