#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class myhash
{
    public:
    string key;
    int freq;
    myhash *next;
    myhash(string a="hello",int fre=1)
    {
        key=a;
        freq = fre;
        next = NULL;
    }
};
main()
{
    myhash *current[13];
    for(int i=0; i<13; i++){
        current[i]=new myhash;
    }
    //current.freq=5;
    //myhash curr;
    current[1]->freq=5;
    cout<<current[0]->freq<<endl;
    cout<<current[1]->freq;
    //cout<<curr.key;
   /* myhash h[10];
    /*myhash *arr;
    arr = &h;
    cout<<*arr.key;*/
    /*for(int i=0;i<10;i++)
        cout<<h[i].key;*/


}
