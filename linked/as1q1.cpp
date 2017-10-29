#include <iostream>
using namespace std;
template <typename T>
class mystack
{
    int capacity;
    int index;
    T * S ;
public:
    mystack()
    {
        capacity=5;
        S=new T [capacity];
        index=0;
    }
    void push(T ele);
    T pop();
    int sizestack();
    T top();
    bool isemp();
};
void mystack::push(T ele)
{

        if (index<capacity)
        {
            S[index] = ele;
        }
        else
        {
            T * X = S;
            S = new T[2*capacity];
            for(int i=0;i<capacity;i++)
            S[i] = X[i];
            S[index] = ele;
            delete []X;
            capacity=2*capacity;
        }
        index++;
}
T mystack::pop()
{       if(index==0)
        {
            cout<<"STACK IS EMPTY";
        }
        else
        {   T temp =S[index - 1]
        S[index-1]=NULL;
        index--;
        return temp;
        }
}
int mystack::sizestack()
{
    return index;
}
T mystack::top()
{
    return S[index-1];
}
bool mystack::isemp()
{
    if(index==0)
        return 1;
    else
        return 0;
}
int main()
{   T<char>;
    mystack rahul;
    rahul.push(a);
    rahul.push(b);
    rahul.push(c);
    cout<<rahul.sizestack();
    rahul.pop();
    return 0;
}
