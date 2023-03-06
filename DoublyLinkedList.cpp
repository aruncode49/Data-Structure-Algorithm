#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    node* prev;
    int item;
    node* next;
};

class DLL
{
    private:
        node* start;

    public:
        DLL();
        DLL(DLL&);
        DLL& operator =(DLL&);
        void insertAtStart(int);
        void insertAtLast(int);  
        void insertAfter(node*,int); 
        node* search(int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        ~DLL();
};

DLL::DLL()
{
    start = NULL;
}

DLL::DLL(DLL& list)    
{
   node *t;
   if(list.start != NULL)
   {
        t=list.start;
        while (t->next != NULL)
            t = t->next;
        while(t)
        {
            insertAtStart(t->item)
            t=t->prev;
        }       
   }
   else
   {
        start = NULL;
   }
}

DLL& DLL::operator =(DLL& list)
{
   while(start) 
        deleteFirst();
   node *t;
   if(list.start != NULL)
   {
        t=list.start;
        while (t->next != NULL)
            t = t->next;
        while(t)
        {
            insertAtStart(t->item)
            t=t->prev;
        }       
   }
   else
   {
        start = NULL;
   }
   return *this;
}

void DLL::insertAtStart(int data)
{
    node *n = new node;
    n->prev = NULL;
    n->item = data;
    n->next = start;
    if(start != NULL)
        start->prev = n;
    start = n;
}

void DLL::insertAtLast(int data)
{
    // ready node to insert
    node *n = new node;
    node *t = start;
    n->item = data;
    n->next = NULL;

    // check if start node contain null
    if(start == NULL)
    {
        start = n;
        n->prev = NULL;
    }
    else // if list is not empty then we have to traverse the list until second-last node
    {   
        while(t->next != NULL)
            t = t->next;
        
        n->prev = t;
        t->next = n;    
    }
}

void DLL::insertAfter(node *t, int data)
{
    try{

        if(start == NULL)
            throw 1;

        node *n = new node;
        n->next = t->next;
        n->item = data;
        n->prev = t;
        if(t->next)
            t->next->prev = n;
        t->next = n;
 
    }

    catch(int e)
    {
        cout<<"List is empty";
    }
}

node* DLL::search(int data)             
{
    node* t = start;
    try
    {
        if(t == NULL)
            throw 1;

        while(t)
        {
            if(t->item == data)           
                return t;
            t = t->next;            
        }
        return NULL;
    }
    catch(int e)
    {
        cout<<"Invalid node";
    }
}

void DLL::deleteFirst()
{
    if(start)
    {
        node *r = start;
        start = r->next;
        delete r;
        start->prev = NULL;
    }
}

void DLL::deleteLast()
{
    try
    {
        if(start == NULL)
            throw 1;

        if(start->next == NULL)
        {
            delete start;
            start = NULL;
        }
        else
        {
            node *t = start;
            while(t->next->next != NULL)
                    t = t->next;
            delete t->next;
            t->next = NULL;
        }
    }
    catch(int e)
    {
        cout<<"List is empty";
    }
}

void DLL::deleteNode(node* t)
{
    try{
        if(start == NULL)
            throw 1;
        else if(start == t)
            deleteFirst();
        else if(t->next == NULL)
            deleteLast();
        else
        {
            node *r = start;
            while(r->next != t)
                r = r->next;
            r->next = t->next;
            t->next->prev = r;
            delete t;
        }
    }
    catch(int e)
    {
        cout<<"List is empty.";
    }
}

DLL::~DLL()
{
    while(start)
        deleteFirst();
}
