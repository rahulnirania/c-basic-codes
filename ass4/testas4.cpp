#include <iostream>
#include<stdio.h>
#include<random.h>
#include<stdlib.h>
using namespace std;
int k,n;
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

    void inscust(float departure_time)
    {
        heap1[0].nocustomer++;
        heap1[0].timerem += departure_time;
        heapify(0);
    }
    void heapify(int t)
{
    int flag = 1;
    while(t<k && flag==1)
    {   if(2*t+2<k)
       {
           if(heap1[2*t+1].nocustomer<heap1[t].nocustomer||heap1[2*t +2].nocustomer<heap1[t].nocustomer)
    {
               if(heap1[2*t+1].nocustomer<heap1[2*t +2].nocustomer)
               {
                node1 temp=heap1[2*t+1];
                heap1[2*t+1]=heap1[t];
                heap1[t]=temp;
                t=2*t +1;
               }
               else
                {
                node1 temp=heap1[2*t +2];
                heap1[2*t +2]=heap1[t];
                heap1[t]=temp;
                t=2*t +2;
               }
    }
    else
    flag = 0;
    }
    else
        if(2*t+1<k)
    {
        if(heap1[2*t+1].nocustomer<heap1[t].nocustomer)
               {
                node1 temp=heap1[2*t+1];
                heap1[2*t+1]=heap1[t];
                heap1[t]=temp;
                t=2*t +1;
               }
        flag = 0;
    }
    else
    flag = 0;
}}
void delcust(int coun, float ser)
{
    heap1[coun].nocustomer--;
    heap1[coun].timerem = heap1[coun].timerem - ser;
    heapify(heap1[coun].counterno);
}
void heapify2(int q)
{
    while(q>=1)
    {
        if(heap1[(q-1)/2].nocustomer > heap1[q].nocustomer)
        {
                node1 *temp=&heap1[q];
                heap1[q]=heap1[(q-1)/2];
                heap1[(q-1)/2]=*temp;
                q = (q-1)/2;
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
        node2* h2 = new node2[n];
    binheap1 h3;
    int  heap2size = -1;
    float wt;
    void insh2(float art, float srt)
    {

        h2[heap2size+1].sert = srt;
        h2[heap2size+1].arrt=art;
        if(art<h3.heap1[0].timerem)
            h2[heap2size+1].dept=srt+h3.heap1[0].timerem;
        else
            h2[heap2size+1].dept=srt + art;

        h2[heap2size+1].queueno=h3.heap1[0].counterno;
         h3.inscust(h2[heap2size+1].dept);
        wt = wt + h2[heap2size+1].dept - h2[heap2size+1].arrt - srt;
        heapify3(heap2size+1);
        heap2size++;
    }
    void heapify3(int j)
    {
       while(j>=1)
    {
        if(h2[(j-1)/2].dept > h2[j].dept)
        {
                node2 temp=h2[j];
                h2[j]=h2[(j-1)/2];
                h2[(j-1)/2]=temp;
                j = (j-1)/2;
        }
        else
        break;
    }
    }
    void delh2()
    {
            h3.delcust(h2[0].queueno, h2[0].sert);
            h2[0]=h2[heap2size];
            heap2size--;
            heapify4(0);
    }
   /*void heapify4(int u)
    {
        int j = u;
         while(j<heap2size)
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
    }*/
       void heapify4(int t)
{
    int flag = 1;
    while(t<heap2size && flag==1)
    {   if(2*t+2<=heap2size)
       {
           if(h2[2*t+1].dept<h2[t].dept||h2[2*t +2].dept<h2[t].dept)
    {
               if(h2[2*t+1].dept<h2[2*t +2].dept)
               {
                node2 temp=h2[2*t+1];
                h2[2*t+1]=h2[t];
                h2[t]=temp;
                t=2*t +1;
               }
               else
                {
                node2 temp=h2[2*t +2];
                h2[2*t +2]=h2[t];
                h2[t]=temp;
                t=2*t +2;
               }
    }
    else
    flag = 0;
    }
    else
        if(2*t+1<=heap2size)
    {
        if(h2[2*t+1].dept<h2[t].dept)
               {
                node2 temp=h2[2*t+1];
                h2[2*t+1]=h2[t];
                h2[t]=temp;
                t=2*t +1;
               }
        flag = 0;
    }
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
        if(h4[0].dept< orgarr)
        {
            time = h4[0].dept;
            h4.delh2();
            outcust++;
        }

        else
        {
         h4.insh2(orgarr, inputrandomeservicetime(mmean,var));
         time= orgarr;
         incust++;
        }

    }
    cout<<(h4.wt)/n;


    cout<<h4.wt/n;
    return 0;

}
