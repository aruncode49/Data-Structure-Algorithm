#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
    int item;
    node *next;
};

class Stack
{
    private:
        node *top;
    public:
        Stack();
        Stack(Stack&);
        Stack& operator=(Stack&);
        void push(int);
        void pop();
        int peek();
        void reverse();
        ~Stack();
}; 

Stack::Stack()
{
    top = NULL;
}

Stack::Stack(Stack &s)
{
    s.reverse();
    node *t = s.top;
    while(t)
    {
        push(t->item);
        t = t->next;
    }
    s.reverse();
}

Stack& Stack::operator=(Stack& s)
{
    if(top != NULL)
    {
        while(top)
        pop();
    }
    s.reverse();
    node *t = s.top;
    while(t)
    {
        push(t->item);
        t = t->next;
    }
    s.reverse();
    return *this;
}

void Stack::push(int data)
{
    node *n =  new node;
    n->item = data;
    n->next = top;
    top = n;
}

int Stack::peek()
{
    if(top==NULL)
        cout<<"Stack Underflow";
    else
        return top->item;
}

void Stack::pop()
{
    if(top != NULL)
    {
        node *r = top;
        top = top->next;
        delete r;
    }
}

void Stack::reverse()
{
    Stack s1;
    while(top)
    {
        s1.push(peek());
        pop();
    }
    top = s1.top;
    s1.top = NULL;
}

Stack::~Stack()
{
    while(top)
        pop();
}
