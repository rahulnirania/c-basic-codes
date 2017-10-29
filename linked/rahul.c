#include<iostream>
using namespace std;

int main()
{   int n, q, l, r, i, j,ans;
    cin>>n;

    char A[2n];
    cin.getline( A,2n+1);
       int k=0
    for(i=0;i<2n;i+=2)
    {

        X[k]=(int)A[i];
        k++;
    }
    for(j=1;j<=q;j++)
    {   cin>>l>>r;
        ans = 0;
        for(i=l-1;i<r;i++)
        {   ans = ans+ A[i];
        }
        ans = ans/(r-l+1);
        cout<<ans<<"\n";
    }

    return 0;
}
