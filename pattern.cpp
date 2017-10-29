#include <iostream>
using namespace std ;
int main()
{	int n;
	cout<<"insert the value of n\n";
	cin>>n;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	if (n%2==1)
		cout<<"n is odd\n";
	else
		cout<<"n is even\n";
	return 0;
}