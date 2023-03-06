#include <iostream>
using namespace std;

struct node
{
    int item;
    node *next;
};

class CLL
{
    private:
        node *last;

    public:
        CLL();
        CLL(CLL &);
        CLL& operator=(CLL &);
        void insertAtStart(int);
        void insertAtLast(int);
        void insertAfter(node *, int);
        node *search(int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node *);
        ~CLL();
};

CLL::CLL()
{
    last = NULL;
}

CLL::CLL(CLL& list)
{
    node* t;
    if(list.last==NULL)
        last==NULL;
    else
    {
        t = list.last->next;
        while(t != list.last)
        {
            insertAtLast(t->item);
            t = t->next;
        }
        insertAtLast(last->item);
    }
}

CLL& CLL::operator=(CLL& list)
{
    while(last)
        deleteFirst();
    node* t;
    if(list.last==NULL)
        last==NULL;
    else
    {
        t = list.last->next;
        while(t != list.last)
        {
            insertAtLast(t->item);
            t = t->next;
        }
        insertAtLast(last->item);
    }
    return *this;
}

void CLL::insertAtStart(int data)
{
    node *n = new node;
    n->item = data;
    if(last==NULL)
    {
        n->next =n;
        last =n;
    }
    else
    {
        n->next = last->next;
        last->next = n;
    }
}

void CLL::insertAtLast(int data)
{
    node *n = new node;
    n->item = data;
    if(last==NULL)
    {
        n->next = n;
        last =n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}

void CLL::insertAfter(node *t, int data)
{
    try
    {
        if (t==last)
            insertAtLast(data);
        else if(t)
        {
            node *n = new node;
            n->item = data;
            n->next = t->next;
            t->next = n;
        }
    }
    catch (int e)
    {
        cout << "Wrong node address";
    }
}

node *CLL::search(int data)
{
    node *r = last->next;
    try
    {
        if (last == NULL)
            throw 1;
        while (last)
        {
            if (r->item == data)
                return r;
            r = r->next;
            if (r == last->next)
                break;
        }
        return NULL;
    }
    catch (int e)
    {
        cout << "List is empty";
    }
}

void CLL::deleteFirst()
{
    if (last)
    {
        node *r = last->next;
        last->next = r->next;
        if(last==r)
            last=NULL;
        delete r;
    }
}

void CLL::deleteLast()
{
    try{

        if(last == NULL)
            throw 1;

        if(last->next == last){
            delete last;
            last = NULL;
        }
        else
        {
            node* t = last->next;
            while(t->next !=  last)
                t = t->next;
            t->next = last->next;
            last = t;
            delete t;
        }
    }
    catch(int e)
    {
        cout<<"List is empty";
    }
}

void CLL::deleteNode(node* t)
{
    if(t!=NULL)
    {
        if(last == t)
            delete last;
        else if(t==last->next)
            deleteFirst();
        else{
            node* r = last->next;
            while(r->next != t)  
                r = r->next;
            r->next = t->next;
            delete t;
        }
    }      
}

CLL::~CLL()
{
    while(last)
        deleteFirst();
}
