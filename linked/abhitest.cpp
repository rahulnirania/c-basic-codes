#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char* charr=new char [2*n];
    int*arr=new int[2*n];
    int k=0;
    for(int i=0;i<2*n;i++){
        charr[i]=cin.get();
        if(charr[i]!=' '){
            arr[k]=(charr[i]-'0');
            k++;
        }
    }
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
}
