#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int clk=0;
int avg=0;

struct counterinfo{
    int billcounter;
    int customers;
    float timeSerEnd;
};

struct cfo
{
    int queueNo;
    float ArrivalTime;
    float DepartTime;
};
class heap2{};
class heap1{};
class heap1:public heap2
{
    int ms;
    counterinfo *a;

public:
    heap1(int counters){
        ms=counters;
        a=new counterinfo[ms];
        int i=0;
        while(i<ms){
         a[i].billcounter=i;
         a[i].customers=0;
         a[i].timeSerEnd=0;
        }
    }

    void insertion(float arrivaltime,float servicetime){
        int diff=arrivaltime-clk;
        for(int i=0;i<ms;i++){
             a[i].timeSerEnd=a[i].timeSerEnd-diff;
            if(a[i].timeSerEnd<=0){
                a[i].timeSerEnd=0;
            }
        }
        clk=arrivaltime;
        avg+=servicetime;
        a[0].customers++;
        a[0].timeSerEnd+=a[0].timeSerEnd;
        insertion2(a[0].billcounter,arrivaltime,timeSerEnd);
        while((i<ms)&&(((2*i+1<ms)&&(a[left(i)].customers<a[i].customers))||((2*i+2<ms)&&(a[right(i)].customers<a[i].customers)))){
            if(a[left(i)].customers<a[right(i)].customers)
            {
                cfo temp=a[left(i)];
                a[left(i)]=a[i];
                a[i]=temp;
            }
            else{
                cfo temp=a[right(i)];
                a[right(i)]=a[i];
                a[i]=temp;
            }
        }

    }

    void delete1(float dpt,int q){
        int diff=dpt-clk;
        clk=dpt;
    for(int i=0;i<ms;i++){
             a[i].timeSerEnd=a[i].timeSerEnd-diff;
            if(a[i].timeSerEnd<=0){
                a[i].timeSerEnd=0;
            }
            for(int i=0;i<ms;i++){
                if(a[i].billcounter==q)
                    a[i].billcounter--;
    }
            }

int parent(int k){
    return (k-1)/2;
}

int right(int k){
    return (2*k+2);
}

int left(int k){
    return (2*k+1);
}

};

class heap2: public heap1
{
    int cs;
    cfo *b;
public:
    heap2(int noc){
      cs=0;
      b=new cfo[noc];
    }

    void insertion2(int x,float arrive,float depart){
        cs++;
        int i=cs-1;
        b[i].arrivaltime=arrive;
        b[i].DepartTime=depart;
        b[i].queueNo=x;
         while (i != 0 && b[parent(i)].DepartTime > b[i].DepartTime)
    {
       counterinfo temp=b[parent(i)];
                b[parent(i)]=b[i];
                b[i]=temp;
       i = parent(i);
    }
    }
     int parent(int k){
    return (k-1)/2;
}

int right(int k){
    return (2*k+2);
}

int left(int k){
    return (2*k+1);
}
    void delete2(){
        int i=cs-1;
        delete1(b[0].DepartTime,b[0].queueNo)
        counterinfo temp=b[i];
                b[i]=b[0];
                b[0]=temp;
        cs--;
       while((i<cs)&&(((2*i+1<cs)&&(b[left(i)].DepartTime<b[i].DepartTime))||((2*i+2<cs)&&(b[right(i)].DepartTime<b[i].DepartTime)))){
            if(b[left(i)].DepartTime<b[right(i)].DepartTime)
            {
                cfo temp=b[left(i)];
                b[left(i)]=b[i];
                b[i]=temp;
            }
            else{
                cfo temp=b[right(i)];
                b[right(i)]=b[i];
                b[i]=temp;
            }
    }

};

int main(){
    int k,n1,a;
    float r,m,v,n;
    cin>>r>>m>>v>>k>>n1;
    float at[n1];
    srand(time(0));
    float st[n1],sum=0;
    for(int i=0;i<n1;i++){
    a=rand()%1023;
    n=a/1023;
    st[i]=((n*2*v)+(m-v)); sum+=st[i];
    cout<<st[i]<<" ";
    }
    for(int i=0;i<n1;i++){
    a=rand()%1023;
    n=a/1023;
    at[i]=i/r+n/r;
    }

  heap1 h1(k);
  heap2 h2(n);
  for(int i=0;i<n;i++){
      if(h2.recentdeparture()>at[i])
          h1.insertion(at[i],st[i]);
      else if(h2.departure()==-1)
          h1.insertion(at[i],st[i])
      else{
         h2.delete2();
         i--;
        }
      }

  cout<<(avg+sum)/n;
      return 0;
}
