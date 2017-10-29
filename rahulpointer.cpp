#include <iostream>
using namespace std;
int main()
{
    int var = 50;
int  *p;
p = &var;

cout << *p<<"\t"<<var<<"\t"<<p<<"\t"<<&var<<"\t" <<sizeof(var) <<sizeof(&var) <<sizeof(p) <<sizeof(*p) <<endl;
}
