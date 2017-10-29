#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
using namespace std;

main()
{
    string p;
    getline(cin, p);
   /* char *t;
    int i;
    t = new char[50];
    cout<<"Enter characters \n";
    for( i=0;i<5; i++)
    {
        cin>>t[i];
    }
    t[i] = '\0';*/
        cout<<p.at(3);
}
