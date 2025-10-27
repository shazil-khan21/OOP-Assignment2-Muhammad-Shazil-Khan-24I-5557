#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node* next;
    Node(char d){data=d;next=NULL;}
};

class StackList
{
public:
    Node* top;
    StackList(){top=NULL;}
    void push(char d)
    {
        Node* n=new Node(d);
        n->next=top;
        top=n;
    }
    void pop()
    {
        if(top==NULL) return;
        Node* t=top;
        top=top->next;
        delete t;
    }
    char peek()
    {
        return top->data;
    }
    bool empty()
    {
        return top==NULL;
    }
};

class StackArray
{
public:
    char* arr;
    int top;
    int size;
    StackArray(int s)
    {
        size=s;
        arr=new char[size];
        top=-1;
    }
    void push(char d)
    {
        top++;
        arr[top]=d;
    }
    void pop()
    {
        if(top==-1) return;
        top--;
    }
    char peek()
    {
        return arr[top];
    }
    bool empty()
    {
        return top==-1;
    }
};

void ChangeLocationIterative(char A[],int b1,int b2)
{
    StackArray s(50);
    int i=b1;
    while(i<=b2)
    {
        s.push(A[i]);
        i++;
    }
    i=b1;
    while(!s.empty())
    {
        A[i]=s.peek();
        s.pop();
        i++;
    }
}

void PrintPatternIterative(int n)
{
    StackList s;
    s.push(n+'0');
    while(!s.empty())
    {
        int x=s.peek()-'0';
        s.pop();
        if(x==0) continue;
        if(x%2==0)
        {
            int half=x/2;
            cout<<half<<" "<<half<<endl;
        }
        else
        {
            for(int i=0;i<x-1;i++)
                cout<<"1 ";
            cout<<1<<endl;
        }
        s.push(x-1+'0');
    }
}

int main()
{
    char A[8]={'C','O','M','P','U','T','E','R'};
    ChangeLocationIterative(A,2,6);
    for(int i=0;i<8;i++)
        cout<<A[i];
    cout<<endl;

    int n;
    cin>>n;
    PrintPatternIterative(n);

    return 0;
}

// QUESTION 5 (B) PART
//In the linked list based stack, each push and pop operation takes O(1) time because memory is allocated dynamically and no shifting occurs. However, it uses extra memory for pointers.
//In the array based stack, push and pop operations also take O(1) time as long as the stack is not full. However, it requires a fixed size and may need resizing if capacity is exceeded. No pointers are stored, so it is more memory efficient than the linked list stack.
//Performance Difference:
//The linked list stack is flexible in size and avoids overflow but uses more memory. The array based stack is faster in memory access and uses less space, but requires predefined size.

