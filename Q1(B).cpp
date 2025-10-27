#include <iostream>
using namespace std;

void PrintLine(int i,int n)
{
    if(i==0)
    {
        cout<<n;
        cout<<endl;
        return;
    }
    if(i==1)
    {
        cout<<n/2<<" "<<n/2<<endl;
        return;
    }
    for(int j=0;j<i-1;j++)
        cout<<"1 ";
    cout<<n-(i-1);
    cout<<endl;
}

void PrintPattern(int n,int i)
{
    if(i>n)
        return;
    PrintLine(i,n);
    PrintPattern(n,i+1);
}

int main()
{
    int n;
    cin>>n;
    PrintPattern(n,0);
    return 0;
}

