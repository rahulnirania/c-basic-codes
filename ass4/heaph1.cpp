#include <iostream>
#include <random>
using namespace std;

class node()
{
    public
    int custno;
    int timeleft;
    void node()
    {
        custno = 0;
        timeleft = 0;
    }
    void cust(int t)
    {
        custno++;
        timeleft  = timeleft + custtime(t);
    }
};

main()
{
    int k;
    cin>>k;
    node h1[k];

}
