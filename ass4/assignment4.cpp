#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<random>
using namespace std;
int k;
class node1
{
public:
    int counterno;
    int nocustomer;
    float timerem;
    node1()
    {
        nocustomer = 0;
        timerem = 0;
    }
};
class binheap1
{
    public:
    int i;
    node1 *heap1 = new node1[k];

    binheap1()
    {
       for(i=0; i<k; i++)
    {
        heap1[i].counterno = i+1;
    }
    }

    float* inscust(float serv)
    {
        float *inf=new float[2];
        heap1[1].nocustomer++;
        heap1[1].timerem = heap1[1].timerem + serv;
        inf[0]=heap1[1].counterno;
        inf[1]=heap1[1].timerem;
        heapify(1);
        return inf;
    }
    void heapify(int t)
{
    while(t<=k)
    {if(heap1[2*t].nocustomer<heap1[t].nocustomer)
    {
                node1 *temp=&heap1[2*t];
                heap1[2*t]=heap1[t];
                heap1[t]=*temp;
                t=2*t;
    }
    else if(heap1[2*t +1].nocustomer<heap1[t].nocustomer)
    {
        node1 *temp=&heap1[2*t +1];
                heap1[2*t +1]=heap1[t];
                heap1[t]=*temp;
                t=2*t +1;
    }
    else
    break;
    }
}
void delcust(int coun, float ser)
{
    heap1[coun].nocustomer--;
    heap1[coun].timerem = heap1[coun].timerem - ser;
    heapify2(coun);
}
void heapify2(int q)
{
    while(q>=1)
    {
        if(heap1[q/2].nocustomer > heap1[q].nocustomer)
        {
                node1 *temp=&heap1[q];
                heap1[q]=heap1[q/2];
                heap1[q/2]=*temp;
                q = q/2;
        }
        else
        break;
    }
}
};
class node2
{
    public:
     float queueno;
     float sert;
    float arrt;
    float dept;
};
class binheap2
{
    public:
        node2* h2 = new node2[100];
    binheap1 h3;
    int  heap2size = 0;
    float wt;
    void insh2(float art, float srt)
    {
        float *info=h3.inscust(srt);
        h2[heap2size+1].queueno=info[0];
        h2[heap2size+1].sert = srt;
        h2[heap2size+1].arrt=art;
        h2[heap2size+1].dept=info[1]+srt;
        wt = wt + h2[heap2size+1].dept - h2[heap2size+1].arrt - srt;
        heapify3(heap2size+1);
        heap2size++;
    }
    void heapify3(int j)
    {
       while(j>=1)
    {
        if(h2[j/2].dept > h2[j].dept)
        {
                node2 temp=h2[j];
                h2[j]=h2[j/2];
                h2[j/2]=temp;
                j = j/2;
        }
        else
        break;
    }
    }
    void delh2()
    {
            h3.delcust(h2[1].queueno, h2[1].sert);
            h2[1]=h2[heap2size];
            heap2size--;
            heapify4(1);
    }
    heapify4(int u)
    {
        int j = u;
         while(j<=heap2size)
    {if(h2[2*j].dept<h2[j].dept)
    {
        node2 temp=h2[2*j];
                h2[2*j]=h2[j];
                h2[j]=temp;
                j=2*j;
    }
    else
    if(h2[2*j +1].dept<h2[j].dept)
    {
        node2 temp=h2[2*j +1];
                h2[2*j +1]=h2[j];
                h2[j]=temp;
                j=2*j +1;
    }
    else
    break;
    }
    }
};

float inputrandomrate(float rate)
{

    float m=1/rate;
    random_device rd;  //device used to generate random no.
    minstd_rand gen(rd()); // engine used to generate random no.
    uniform_real_distribution<float> dis{0,m};

        return (m);
}
float inputrandomeservicetime(float mean,float variance)
{
    random_device rd;
    minstd_rand gen(rd());
    uniform_real_distribution<float> dis{mean-variance,mean+variance};

        return (mean+variance);

}



int main()
{
    int n;
    float arri, depr, rrate, mmean, var;
    cin>>rrate>>mmean>>var>>k>>n;
    float time = 0;
    binheap2 h4;
    h4.insh2(inputrandomrate(rrate), inputrandomeservicetime(mmean,var));
    int incust = 1;
    int outcust = 0;
    while(incust<=n || outcust<=n)
    {
        int orgarr = time + inputrandomrate(rrate);
        if(h4.h2[0].dept< orgarr)
        {
            time = h4.h2[0].dept;
            h4.delh2();
            outcust++;
        }

        else
        {
         h4.insh2(inputrandomrate(rrate), inputrandomeservicetime(mmean,var));
         time= orgarr;
         incust++;
        }

    }
    cout<<(h4.wt)/n;

    return 0;

}
