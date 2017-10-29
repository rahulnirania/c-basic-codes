#include<iostream>
#include <string.h>
using namespace std;
main()
{
    string str;
    getline(cin,str);
    cout<<str<<"\n";
    for (int i = 0; i < str.length(); i++)
    {
        char x = str.at(i);
        cout << int(x) << endl;
    }
}
