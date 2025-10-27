#include <iostream>
using namespace std;

class Feature
{
public:
    string Name;
    Feature(string n){Name=n;}
    virtual void analyze()=0;
};

class LandFeature:public Feature
{
public:
    LandFeature(string n):Feature(n){}
    void analyze(){cout<<Name<<" Land Feature Detected"<<endl;}
};

class WaterFeature:public Feature
{
public:
    WaterFeature(string n):Feature(n){}
    void analyze(){cout<<Name<<" Water Feature Detected"<<endl;}
};

class Node
{
public:
    int FeatureID;
    Feature* f;
    Node* next;
    Node(int id,Feature* p)
    {
        FeatureID=id;
        f=p;
        next=NULL;
    }
};

class SinglyLinkedList
{
public:
    Node* head;
    SinglyLinkedList(){head=NULL;}

    void insertAtEnd(int id,Feature* p)
    {
        Node* n=new Node(id,p);
        if(head==NULL)
        {
            head=n;
            return;
        }
        Node* t=head;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }

    void deleteByID(int id)
    {
        if(head==NULL)
            return;
        if(head->FeatureID==id)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
            return;
        }
        Node* t=head;
        while(t->next!=NULL && t->next->FeatureID!=id)
            t=t->next;
        if(t->next==NULL)
            return;
        Node* temp=t->next;
        t->next=t->next->next;
        delete temp;
    }

    void displayAll()
    {
        Node* t=head;
        while(t!=NULL)
        {
            t->f->analyze();
            t=t->next;
        }
    }

    void reverseList()
    {
        Node* prev=NULL;
        Node* cur=head;
        Node* nxt;
        while(cur!=NULL)
        {
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        head=prev;
    }
};

int main()
{
    SinglyLinkedList L;

    L.insertAtEnd(1,new LandFeature("Forest"));
    L.insertAtEnd(2,new WaterFeature("River"));
    L.insertAtEnd(3,new LandFeature("Mountain"));
    L.insertAtEnd(4,new WaterFeature("Lake"));

    cout<<"Original List:"<<endl;
    L.displayAll();

    L.deleteByID(2);
    cout<<"After Deleting THE Feature ID 2:"<<endl;
    L.displayAll();

    L.reverseList();
    cout<<"After Reversing:"<<endl;
    L.displayAll();

    return 0;
}

