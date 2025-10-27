#include <iostream>
using namespace std;

class Node
{
public:
    int ID;
    string Name;
    int Tickets;
    Node* next;
    Node(int i,string n,int t)
    {
        ID=i;
        Name=n;
        Tickets=t;
        next=NULL;
    }
};

class Queue
{
public:
    Node* front;
    Node* rear;
    Queue()
    {
        front=NULL;
        rear=NULL;
    }

    void Enqueue(int i,string n,int t)
    {
        Node* temp=new Node(i,n,t);
        if(rear==NULL)
        {
            front=temp;
            rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }

    void Dequeue()
    {
        if(front==NULL)
            return;
        Node* temp=front;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        delete temp;
    }

    void Display()
    {
        Node* t=front;
        while(t!=NULL)
        {
            cout<<t->ID<<" "<<t->Name<<" "<<t->Tickets<<endl;
            t=t->next;
        }
    }
};

int main()
{
    Queue q;

    q.Enqueue(1,"Shazil",2);
    q.Enqueue(2,"Sara",4);
    q.Enqueue(3,"Hassan",1);

    cout<<"Queue:"<<endl;
    q.Display();

    q.Dequeue();
    cout<<"After Serving First Customer:"<<endl;
    q.Display();

    q.Enqueue(4,"Ayesha",3);
    cout<<"After Adding New Customer:"<<endl;
    q.Display();

    return 0;
}

