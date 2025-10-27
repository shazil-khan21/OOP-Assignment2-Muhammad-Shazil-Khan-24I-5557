#include <iostream>
using namespace std;

void ChangeLocation(char *A,int b1,int b2)
{
    if(b1>=b2)
        return;
    char t=A[b1];
    A[b1]=A[b2];
    A[b2]=t;
    ChangeLocation(A,b1+1,b2-1);
}

int main()
{
    char A[8]={'C','O','M','P','U','T','E','R'};
    ChangeLocation(A,2,6);
    for(int i=0;i<8;i++)
        cout<<A[i];
    return 0;
}

