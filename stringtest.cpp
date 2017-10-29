#include <iostream>
#include <fstream>

using namespace std;


class myhash
{
    public:
    string key;
    int freq;
    myhash *next;
    myhash(string a="def",int fre=1)
    {
        key=a;
        freq = fre;
        next = NULL;
    }
};

int hashfunc(string s)
{
    int h = ((int)s.at(0))%13;
    return h;
}

int main()
{
    string t;
    //myhash hashmap[13];
    myhash **hashmap=new myhash* [13] ;
                for(int i=0;i<10;i++)
                 {
                     cin>>t;
                    int p = hashfunc(t);


                    if(hashmap[p]->next!=NULL)
                   {
                       myhash *temp = new myhash(t);
                       temp->next = hashmap[p];

                    while(temp->key!=t||temp->next!=NULL)
                        temp = temp->next;

                    if(temp->key==t)
                        temp->freq = temp->freq + 1;
                    else
                    {

                        myhash * current=new myhash(t);
                        temp->next = current;
                        current->next = NULL;
                    }
                    }
                   else
                    {
                        myhash * current=new myhash(t);
                        hashmap[p]->next = current;
                        current->next = NULL;
                    }
                 }
        for(int i=0;i<13;i++)
    {   myhash *pp = hashmap[i];
        while (pp->next != NULL)
        {
            cout<<pp->key<<"\n";
            pp = pp->next;
        }
    }
    }
