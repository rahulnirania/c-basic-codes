#include <iostream>
using namespace std;
main()
{
    int n;
    int i, j, k, l=0;
    cout<<"Hello My friend \n";
    cout<<"Please input the value n \n";
    cin>>n;
    int inp[n], out[1000], stac[n];
    cout<<"Please input the queue Q2 \n";
    for(i=0;i<n;i++)
    {
        cin>>inp[i];
    }
    i=0;
    k=0;
    j=1;
    while(i<n)
    {   if(inp[i]>j)
        {  while(j!=inp[i])
            {
                stac[l]= j;
                l++;
                out[k]=3;
                k++;
                j++;
            }
            out[k]=1;
            k++;
            j++;
        }
        else
        if (inp[i]<j)
        {   if(inp[i]==stac[l-1])
            {   l--;
                out[k]=2;
                k++;
            }
            else
            {
             break;
            }
        }
        else
        if(inp[i] == j)
        {
            out[k]=1;
            k++;
            j++;
        }
        i++;
    }
    cout<<"The result of inputed queue is \n";
    if(i==n)
    {
        for(int p=0;p<k;p++)
        {
            if(out[p]==1)
            cout<<"enqueue(Q2, dequeue(Q1)) \n";
            else
            if(out[p]==2)
            cout<<"enqueue(Q2, pop(S)) \n";
            else
            cout<<"push(S, dequeue(Q1)) \n";

        }
    }
    else
        cout<<"permutation not possible";
}
