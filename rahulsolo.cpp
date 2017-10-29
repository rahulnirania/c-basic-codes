#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name,place,total;
    cout<<"Enter your name\n";
    getline(cin,name);
    cout<<"Enter your city name\n";
    getline(cin,place);
    total=name+place;
    cout<<total;
}
