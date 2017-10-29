#include<iostream>
using namespace std;
/*class X
{public:
 int i;

 X(int x)   // Constructor
 { i=x; }

 int f() const   // Constant function
 { i++; }

 int g()
 { i++; }
};

int main()
{
X obj1(10);          // Non const Object
const X obj2(20);   // Const Object

obj1.f();   // No error
obj2.f();   // No error

cout << obj1.i <<"\t"<< obj2.i<<"\n";

obj1.g();   // No error

cout << obj1.i <<"\t" ;  // Compile time error
}*/
class MyClass {
     private:
  int regVar;
  const int constVar;
 public:
  MyClass(int a, const int b)
  : regVar(a), constVar(b)
  {
  }
  /*
  Myclass(int a,const int b){
  regvar=a;
  constVar=b;
  }
  */
};/*
MyClass::MyClass(int a, int b)
: regVar(a), constVar(b)
{
  cout << regVar << endl;
  cout << constVar << endl;
}
*/
main()
{
    MyClass rahul(50,55);
}
