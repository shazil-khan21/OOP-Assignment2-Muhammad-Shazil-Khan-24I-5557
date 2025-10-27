#include <iostream>
using namespace std;

class Node
{
public:
    int BookID;
    string Title;
    string Author;
    Node* prev;
    Node* next;
    Node(int id,string t,string a)
    {
        BookID=id;
        Title=t;
        Author=a;
        prev=NULL;
        next=NULL;
    }
};

class DoublyLinkedList
{
public:
    Node* head;
    Node* tail;
    DoublyLinkedList()
    {
        head=NULL;
        tail=NULL;
    }

    void addAtBeginning(int id,string t,string a)
    {
        Node* n=new Node(id,t,a);
        if(head==NULL)
        {
            head=n;
            tail=n;
            return;
        }
        n->next=head;
        head->prev=n;
        head=n;
    }

    void addAtEnd(int id,string t,string a)
    {
        Node* n=new Node(id,t,a);
        if(tail==NULL)
        {
            head=n;
            tail=n;
            return;
        }
        tail->next=n;
        n->prev=tail;
        tail=n;
    }

    void addAtPosition(int pos,int id,string t,string a)
    {
        if(pos<=1)
        {
            addAtBeginning(id,t,a);
            return;
        }
        Node* temp=head;
        for(int i=1;i<pos-1 && temp!=NULL;i++)
            temp=temp->next;
        if(temp==NULL||temp->next==NULL)
        {
            addAtEnd(id,t,a);
            return;
        }
        Node* n=new Node(id,t,a);
        n->next=temp->next;
        n->prev=temp;
        temp->next->prev=n;
        temp->next=n;
    }

    void deleteByID(int id)
    {
        if(head==NULL)
            return;
        Node* temp=head;
        while(temp!=NULL && temp->BookID!=id)
            temp=temp->next;
        if(temp==NULL)
            return;
        if(temp==head)
            head=head->next;
        if(temp==tail)
            tail=tail->prev;
        if(temp->prev!=NULL)
            temp->prev->next=temp->next;
        if(temp->next!=NULL)
            temp->next->prev=temp->prev;
        delete temp;
    }

    void displayForward()
    {
        Node* t=head;
        while(t!=NULL)
        {
            cout<<t->BookID<<" "<<t->Title<<" "<<t->Author<<endl;
            t=t->next;
        }
    }

    void displayBackward()
    {
        Node* t=tail;
        while(t!=NULL)
        {
            cout<<t->BookID<<" "<<t->Title<<" "<<t->Author<<endl;
            t=t->prev;
        }
    }
};

int main()
{
    DoublyLinkedList L;

    L.addAtBeginning(1,"BookA","AuthorA");
    L.addAtEnd(2,"BookB","AuthorB");
    L.addAtEnd(3,"BookC","AuthorC");
    L.addAtPosition(2,4,"BookD","AuthorD");

    cout<<"Forward:"<<endl;
    L.displayForward();

    cout<<"Backward:"<<endl;
    L.displayBackward();

    L.deleteByID(2);
    cout<<"After Deleting THE ID 2:"<<endl;
    L.displayForward();

    return 0;
}

