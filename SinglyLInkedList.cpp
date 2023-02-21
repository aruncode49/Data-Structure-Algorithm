#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int item;
    node* next;
};

class SLL
{
    private:
        node* start;
    public:
        SLL();
        SLL(SLL&);                  
        SLL& operator=(SLL &);     
        void insertAtStart(int); 
        void insertAtLast(int);  
        void insertAfter(node*,int); 
        node* search(int);
        void deleteFirst();
        void deleteLast();
        void delNode(node*);
        ~SLL();
};

SLL::SLL()
{
    start = NULL;
}

SLL::SLL(SLL &list)
{
    node *t;
    t = list.start;
    start = NULL;
    while(t)
    {
        insertAtLast(t->item);
        t = t->next;
    }
}

SLL& SLL::operator=(SLL &list)
{
    node *t;
    t = list.start;
    while(start)
        deleteFirst();

    while(t)
    {
        insertAtLast(t->item);
        t = t->next;
    }
    return *this;
}

void SLL::insertAtStart(int data)
{
    node* n = new node;
    n->item = data;
    n->next = start;
    start = n;
}


void SLL::insertAfter(int data)
{
    node *n = new node;
    node *t = start;
    n->item = data;
    n->next = NULL;
    if(start == NULL)
        start = n;
    else
    {
        while(t->next != NULL)
            t = t->next;
        t->next = n;
    }    
}

void SLL::insertAfter(node *t, int data)
{
    try
    {
        if(t == NULL)
            throw 1;
        node *n = new node;
        n->item = data;
        t->next = n;
        n->next = t->next;        
    }
    catch(int e)
    {
        cout<<"Invalid node index."
    }
}

node* SLL::search(int data)
{
    node *t;
    t = start;
    try
    {
        if(t==NULL)
            throw 1;
        while(t)
        {
            if(t->item == data)
                return t;
            t = t-next;
        }
        return NULL;
    }
    catch(int e)
    {
        cout<<"List is empty, Item not found."
    }   
}

void SLL::deleteFirst()
{
    if(start)
    {
        node *r =start;
        start = r->next;
        delete r;
    }
}

void SLL::deleteLast()
{
    node *r = start;
    try{
        if(start == NULL)
            throw 1;
        if(start->next == NULL)
        {
            delete start;
            start = NULL;
        }

        else
        {
            while(r->next->next != NULL)
                r = r->next;
            delete r->next;
            r->next = NULL;
        }
    }
    catch(int e)
    {
        cout<<"List is empty, no last node present."
    }
}

void SLL::delNode(node *t)
{
    try{
        if(start == NULL)
            throw 1;
        if(start == t)
            deleteFirst();
        else
        {
            node *r = start;
            while(r->next != t)
                r = r->next;
            r->next = t->next;
            delete r->next;
        }
    }
    catch(int e)
    {
        cout<<"Invalid Index.";
    }
}

SLL::~SLL()
{
    while(start)
        deleteFirst();
}