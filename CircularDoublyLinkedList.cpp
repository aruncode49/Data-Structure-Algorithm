#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    node* prev;
    int item;
    node* next;
    
};

class CDLL
{
    private:
        node* start;
    public:
        CDLL();
        CDLL(CDLL&);
        CDLL& operator=(CDLL&);
        void insetAtStart(int);
        void insetAtLast(int);
        void insertAfter(node*, int);
        node* search(int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        ~CDLL();
};

CDLL::CDLL()        // constructor for initializing start node;
{
    start = NULL;
}

CDLL::CDLL(CDLL& list)      // copy constructor;
{
    node *t;
    if(list.start == NULL)
        start = NULL;
    else
    {
        t=list.start;
        do
        {
            insertAtLast(t->item);
            t=t->next;
        } while (t!=list.start);       
    }
}

CDLL& CDLL::operator=(CDLL& list)       // copy assignment operator;
{
    while(start)
        deleteFirst();

    node *t;
    if(list.start == NULL)
        start = NULL;
    else
    {
        t=list.start;
        do
        {
            insertAtLast(t->item);
            t=t->next;
        } while (t!=list.start);       
    }
    return *this;
}

void CDLL::insetAtStart(int data)
{
    node* n = new node;
    n->item = data;
    if(start==NULL)     // if list is empty
    {
        n->prev = n;
        n->next = n;
        start = n;
    }
    else if(start->next == NULL)        // if list has one node
    {
        n->next = start->next;
        n->prev = start;
        start->next = n;
        start->prev = n;
        start = n;
    }
    else        // if list has more than one node
    {
        n->next = start;
        n->prev = start->prev->next;
        start->prev->next = n;
        start->prev = n;
        start = n;
    }
}

void CDLL::insetAtLast(int data)
{
    node *n = new node;
    n->item = data;

    if(start==NULL){        // if list is empty
        n->prev = n;
        n->next = n;
        start = n;
    }
    else    // if list has one node or more than one node
    {
        start->prev->next = n;
        n->prev = start->prev;
        n->next = start;
        start->prev = n;
    }
}

void CDLL::insertAfter(node* t, int data)
{
    node* n = new node;
    n->item = data;
    if(start==NULL || t == NULL)
        cout<<"List Underflow";
    else if(start->prev ==t)
        insetAtLast(data);
    else
    {
        t->next = n;
        n->prev = t;
        t->prev = n;
        n->next = t->next;
        t->next->prev = n;
        t->next = n;
    }
}

node* CDLL::search(int data)
{
    node* r = start;
    do
    {
        if(r->item == data)
            return r;
        r = r->next;
    } while(r != start);
    return NULL;
}

void CDLL::deleteFirst()
{
    if(start->next==start)
    {
        delete start;
        start = NULL;
    }
    else if(start != NULL)
    {

        node*r = start;
        start->next->prev = start->prev;
        start->prev = start->next;
        start = start->next;
        delete r;
    }
}

void CDLL::deleteLast()
{
    if(start->next==start
    )
    {
        delete start;
        start = NULL;
    }
    else if(start != NULL)
    {

        node*r = start->prev;
        r->prev->next = start;
        start->prev = r->prev;
        delete r;
    }
}

void CDLL::deleteNode(node* t)
{
    if(start==t)
    {
        delete start;
        start = NULL;
    }

    else if(t->next == start)   // if t is last node;
        deleteLast();

    else if(start != NULL)     // when t is in middle
    {
        node*r = start;
        while(r->next != t)
            r = r->next;
        
        r->next = t->next;
        t->next->prev = r;
        delete t;
    }
}

CDLL::~CDLL()
{
    while(start != NULL)
        deleteFirst();
}