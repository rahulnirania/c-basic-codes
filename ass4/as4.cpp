#include <bits/stdc++.h>

using namespace std;



class node1
{
public:
    int counterno;
    int nocustomer;
    int timerem;
    void node1()
    {
        nocustomer = 0;
        timerem = 0;
    }
};
class heap1
{   node1* h1[] = new node1[1000];
    int countsize;
    void CounterNo(int total)
    {
        countsize = total;
        for(int i=0;i<=total;i++)
        {
            h1[i]=new Node1();
            h1[i].counterno = i+1;
        }
    }
    int t=1;
    float* inscust(float st)
    {
        float* q=new float[2];
        if(t<=k)
        {
            q[0]=h1[t].identity;
            h1[t].nocustomer++;
            h1[t].timerem+=st;
            q[1]=h1[t].timerem;
            t++;
        }
        else
        {
            q[0]=h1[1].counterno;
            h1[1].nocustomer++;
            h1[1].timerem+=st;
            q[1]=h1[1].timerem;
            heapifydown(1);
        }
        return q;
    }

};
void heapify(int n)
    {
        int pos=n;
        while(pos>1)
        {
            if(h1[pos].nocustomer<h1[pos/2].nocustomer)
            {
                Node1 *temp=h1[pos];
                h1[pos]=h1[pos/2];
                h1[pos/2]=temp;
                pos=(pos/2);
            }
        }
    }
    void heapifydown(int n)
    {
        int pos= n;
        while(pos*2<=countsize)
        {
            if(h1[pos].nocustomer>h1[2*pos].nocustomer ||h1[pos].nocustomer>h1[pos*2+1].nocustomer)
            {
                if(h1[pos*2].nocustomer!=0 &&h1[pos*2+1].nocustomer!=0)//both left and right child exists
                {
                    if(h1[pos*2].customers<h1[pos*2+1].customers)
                    {
                        Node1* tmp=h1[pos];
                        h1[pos]=h1[pos*2];
                        h1[pos*2]=tmp;
                        pos=pos*2;
                    }
                     else
                    {
                        Node1* tmp=h1[pos];
                        h1[pos]=h1[pos*2+1];
                        h1[pos*2+1]=tmp;
                        pos=pos*2+1;
                     }
                }
                else if(h1[pos*2].nocustomer!=0) //only left child exists
                    {
                        Node1* tmp=h1[pos];
                        h1[pos]=h1[pos*2];
                        h1[pos*2]=tmp;
                        pos=pos*2;
                    }
            }
                else
                break;
        }
    }
};
