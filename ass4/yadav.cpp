#include<bits/stdc++.h>
#include<random>
using namespace std;
// create random no. that are uniformly distributed
/*float* randomizedArr(int n,float r)
{
    float *a =new float[n];
    float m=1/r;
    random_device rd;  //device used to generate random no.
    minstd_rand gen(rd()); // engine used to generate random no.
    uniform_real_distribution<float> dis{0.0,m};

    for (int i = 0; i < n; ++i)
    {
        a[i]=dis(gen);
    }
    return a;
}
float* randomizedService(float m,float v,int n)
{
    float *b=new float[n];
    random_device rd;
    minstd_rand gen(rd());
    uniform_real_distribution<float> dis{m-v,m+v};

    for (int i = 0; i < n; ++i)
    {
        b[i]=dis(gen);
    }
    return b;
}

*/
class Node1{
public: int identity;
        int customers;
        float totalSt;
        Node1()
        {
            customers=0;
            totalSt=0;
        }
};
class heap1
{
    int k;int t=1;
    Node1* h1[]=new Node1[1000];
    void CounterNo(int total)
    {
        k=total;
        for(int i=0;i<=total;i++)
        {
            h1[i]=new Node1();
        }
    }
    void intialize()
    {
        for(int i=0;i<=k;i++)
        {
            h1.identity=i;
        }
    }
    float* insertCust(float st)
    {
        float* q=new float[2];
        if(t<=k)
        {
            q[0]=h1[1].identity;
            h1[t].customers++;
            h1[t].totalSt+=st;
            q[1]=h1[t].totalSt;
            t++;
        }
        else
        {
            q[0]=h1[1].identity;
            h1[1].customers++;
            h1[1].totalSt+=st;
            q[1]=h1[1].totalSt;
            heapifydown(1);
        }
        return q;
    }
    int searchDelElePos(float key)
    {
        for(int i=0;i<=k;i++)
        {
            if(key==h1[i].identity)
                return i;
        }
        return -1;
    }
    void update(float key,float st)
    {
        int pos=searchDelElePos(key);
        if(pos!=-1)
        {
            h1[pos].customers--;
            h1[pos].totalSt-=st;
            heapify(pos);
        }
    }
    void heapify(int n)
    {
        int loc=n;
        while(loc!=1)
        {
            if(h1[loc].customers<h1[loc/2].customers)
            {
                Node1 *temp=h1[loc];
                h1[loc]=h1[loc/2];
                h1[loc/2]=temp;
                loc=(loc/2);
            }
        }
    }
    void heapifydown(int pos)
    {
        int loc=pos;
        while(loc*2<=k)
        {
            if(h1[loc].customers>h1[2*loc].customers ||h1[loc].customers>h1[loc*2+1].customers)
            {
                if(h1[loc*2].customers!=0 &&h1[loc*2+1].customers!=0)//both left and right child exists
                {
                    if(h1[loc*2].customers<h1[loc*2+1].customers)
                    {
                        Node1* tmp=h1[loc];
                        h1[loc]=h1[loc*2];
                        h1[loc*2]=tmp;
                        loc=loc*2;
                    }
                     else
                    {
                        Node1* tmp=h1[loc];
                        h1[loc]=h1[loc*2+1];
                        h1[loc*2+1]=tmp;
                        loc=loc*2+1;
                     }
                }
                else if(h1[loc*2].nocust!=0) //only left child exists
                    {
                        Node1* tmp=h1[loc];
                        h1[loc]=h1[loc*2];
                        h1[loc*2]=tmp;
                        loc=loc*2;
            +        }
            }
                else
                break;
        }
    }
};
class Node2
{
    float QueueNo;
    float arrTime;
    float depTime;
};
class heap2
{
    int N;int currentsize=0;
    float avgwt=0;
    Node2* h2=new Node2[1000];
    heap1* h3=new heap1();
    void take_n_k(int total,int k)
    {
        this->N=total;
        for(int i=0;i<=total;i++)
        {
            h2[i]=new Node2();
        }
        h3.CounterNo(k);
        h3.intialize();
    }
    void insert(float at,float st)
    {
        float* get[]=new float[2];
        get=h3.insertCust(st);
        h2[currentsize+1].QueueNo=get[0];
        h2[currentsize+1].arrTime=at;
        h2[currentsize+1].depTime=get[1]+at;
        heapify(currentsize+1);
        currentsize++;
    }
    void deletee(float at,int i)
    {
        while(at>=h2[1].depTime)
        {
            float getQno=h2[1].QueueNo;
            float getst=h2[1].depTime-h2[1].arrTime;
            h3.update(getQno,getst);
            h2[1]=h2[currentsize];
            currentsize--;
            heapifydown(1);
        }
    }
    void heapifydown(int pos)
    {
        int loc=pos;
        while(loc*2<=currentsize)
        {
            if(h2[loc].depTime>h2[2*loc].depTime ||h2[loc].depTime>h2[loc*2+1].depTime)
            {
                if(h2[loc*2].depTime!=0 &&h2[loc*2+1].depTime!=0)//both left and right child exists
                {
                    if(h2[loc*2].depTime<h2[loc*2+1].depTime)
                    {
                        Node2* tmp=h2[loc];
                        h2[loc]=h2[loc*2];
                        h2[loc*2]=tmp;
                        loc=loc*2;
                    }
                     else
                    {
                        Node2* tmp=h2[loc];
                        h2[loc]=h2[loc*2+1];
                        h2[loc*2+1]=tmp;
                        loc=loc*2+1;
                     }
                }
                else if(h2[loc*2].nocust!=0) //only left child exists
                    {
                        Node2* tmp=h2[loc];
                        h2[loc]=h2[loc*2];
                        h2[loc*2]=tmp;
                        loc=loc*2;
                    }
            }
                else
                break;
        }
    }
    void heapify(int n)
    {
        int loc=n;
        while(loc!=1)
        {
            if(h2[loc].depTime<h2[loc/2].depTime)
            {
                Node2 *temp=h2[loc];
                h2[loc]=h2[loc/2];
                h2[loc/2]=temp;
            }
            loc=loc/2;
        }
    }
    void calc_avg_wt()
    {
        avgwt+=h2[currentsize].depTime-h2[currentsize].arrTime;
        cout<<h2[currentsize].depTime-h2[currentsize].arrTime;
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int N;
    float m,v;
    float R;
    float* a;
    cin>>N;
    cin>>R;
    //generate random no. between 0 and 1/R and store in array a
    a=randomizedArr(N,R);
    float ArrivalTime[N];
    for(int i=0;i<N;i++)
    {
        if(i==0)
            ArrivalTime[i]=a[0];
        else
            ArrivalTime[i]=ArrivalTime[i-1]+a[1];
            //cout<<ArrivalTime[i]<<" ";
    }
    cin>>m>>v;
    //generate random no. between m-v to m+v and store in array b
    cout<<endl;
    randomizedService(m,v,N);
    heap1 *h1=new heap1();
    heap2 *h2=new heap2();
    //take n and k as parameter
    for(int i=0;i<=n;i++)
    {
        if(i!=1)
            h2.delete(ArrivalTime[i],i);
            h2.insert(ArrivalTime[i],randomizedService[i]);
            h2.calAvgWt();
    }
    h2.print();
    cout<<"Average WT:"<<h2.avgwt<<endl;
}
