#include <iostream>
#include <fstream>

using namespace std;
class myhash
{
    public:
    string key;
    int freq;
    myhash(string a="",int fre=0)
    {
        key=a;
        freq = fre;
    }
    void ink(string t)
    {
        key = t
    }
    void inf(int f)
    {
        freq = f;
    }
};

int hashfunc(string s)
{
    int h = ((int)s.at(0))%13;
    return h;
}

int main()
{

    myhash table[13];
    for(int i=0; i<13; i++)
    {   string t;
        cout<<"enter word no. "<<i+1<<"\t";
        cin>>t;
        int p = hashfunc(t);
        int flag = 0;
        while(flag == 0)
        {if(table[p].freq == 0 )
        {
            table[p].ink(t);
            table[p].inf(1);
            flag = 1;
        }
        else
        if(table[p].freq!=0 && table[p].key == t)
        {
            table[p].inf(table[p].freq +1);
            flag = 1;
        }
        else
            p++;

        }
    }
        int thres;
        cout<<"enter threshold frequency \t";
        cin>>thres;
        for(int i=0;i<13;i++)
        {
            if(table[i].freq > thres)
            {
                cout<<table[i].key<<"->"<<table[i].freq<<"\n";
            }
        }
   }
