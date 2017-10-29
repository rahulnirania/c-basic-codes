#include <iostream>
using namespace std;

int main()
{
    int n, k, i, j;
    cin>>n;
    int X[n];
    char A[2*n];
    for(i=0;i<(2*n);i++)
    {
        A[i] = cin.get();
    }
    k=0;
    for(j=0;j<2*n;j++)
    {   if(A[j]!=' ')
        {   X[k]=A[j]-'0';
            k++;
        }
    }
    for(i=0;i<n;i++)
    cout<<X[i]<<" ";
    return 0;

}
