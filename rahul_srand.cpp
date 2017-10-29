#include<iostream>
#include<cstdlib>
using namespace std;
main()
{
    for(int i=0;i<5;i++)
    {
        srand(i);
        cout<<rand()<<"\n";
        cout<<"random no. under 10 \t"<<rand()%9<<"\n";
        cout<<"random no. under 7 \t"<<rand()%6<<"\n";
        cout<<"random no. under 5 \t"<<rand()%4<<"\n";
    }
}
