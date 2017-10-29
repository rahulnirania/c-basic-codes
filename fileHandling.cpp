#include <iostream>
#include <fstream>
using namespace std;

int main()

{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    //fout.open("output.txt",ios::app);
    char s;
    char *t;
    int capacity = 10;
    t = new char[capacity];
    int ssize = 0;
    int k =1;
    while (!fin.eof())
    {
             fin.get(s);
if(!(s<123&&int(s)>96||int(s)==39||int(s)>64&&int(s)<91))
                {
                    t[ssize]='\0';
                    if(ssize>1)
                    cout<<t<<"\n";
                    ssize= 0;
                    capacity=10;
                    t=new char [capacity];

                }

            else
         //if(int(s)<123&&int(s)>96||int(s)==38)
           //cout << s<<"\t";
           {
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
    /*while(!fin.eof())
    {
        fin.get(s)

        //getline(fin,s);
       // cout<<s<<"\n";
        //fout<<"Line no."<<k<<" :"<<s<<"\n";
        //k++;
    }*/
    fin.close();
}
