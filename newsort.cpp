#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
using namespace std;

class myhash
{
    public:
    string key;
    int freq;
    myhash(string a="",int fre=0)
    {
        key=a;
        freq = fre;
    }
    void ink(string t)
    {
        key = t;
    }
    void inf(int f)
    {
        freq = f;
    }
};


int hashfunc(int s)
{
    return s%47;
}
int partition (int arr[], int low, int high)
void swap(int* a, int* b)
void quickSort(int arr[], int low, int high)
void printArray(int arr[], int size)

int main()
{
    myhash table[50001];
    int thres;
    cout<<"Enter threshold value \t";
    cin>>thres;
    ifstream fin;
    ofstream fout;
    fin.open("test.txt");
    char s;
    char *t;
    int capacity = 10;
    t = new char[capacity];
    int ssize = 0;
    int k =1;
    int sum = 0;
    int pmax=0;


    while (!fin.eof())
    {


            fin.get(s);
            if(!(s<123&&int(s)>96||int(s)==39||int(s)>64&&int(s)<91))
                {
                    t[ssize]='\0';
                    if(ssize>=1)
                    {
                    //cout<<t<<"\n";
                    int p = hashfunc(sum);
                    int flag = 0;
                    while(flag == 0)
                    {if(table[p].freq == 0 )
                    {
                        table[p].ink(t);
                        table[p].inf(1);
                        flag = 1;
                    }
                    else
                    if(table[p].freq!=0 && table[p].key == t)
                    {
                        table[p].inf(table[p].freq +1);
                        flag = 1;
                    }
                    else
                        p=(p+1)%50001;

                    }
                    if(p>pmax)
                        pmax = p;
                    sum = 0;
                    ssize= 0;
                    capacity=10;
                    t=new char [capacity];

                    }
                }

                    else
                    {   sum = sum+int(s);
                        if((int)s>96 ||(int)s<123)
                        s = tolower(s);
                        if(ssize<capacity)
                    {    t[ssize]=s;
                        ssize++;
                    }
                    else
                    {   char*temp = t;

                    t = new char[capacity*2];
                    capacity = 2*capacity;
                    for(int i=0; i<ssize;i++)
                        t[i] = temp[i];
                    t[ssize] = s;
                    ssize++;
                    delete []temp;
                    }
                    }
    }
fin.close();
    for(int i=0;i<=pmax;i++)
        {
            if(table[i].freq > thres)
            {
                cout<<table[i].key<<"  ->  "<<table[i].freq<<"\n";
            }
        }
quickSort(table,0,pmax );
cout<<"\n The words whose frequency is greater than threshold frequency are \n\n";
    for(int i=pmax-1;i>=0;i--)
        {
            if(table[i].freq > thres)
            {
                cout<<table[i].key<<"  ->  "<<table[i].freq<<"\n";
            }
        }

}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high].freq;    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j].freq <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
