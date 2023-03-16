#include<stdio.h>
#include<iostream>
using namespace std;

class Stack
{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        Stack();
        Stack(int);
        Stack(Stack &);
        Stack& operator=(Stack &);
        void push(int);
        int peek();
        void pop();
        bool isFull();
        bool isEmpty();
        ~Stack();
};

Stack::Stack()
{
    capacity = 0;
    top = -1;
    ptr = NULL;
}

Stack::Stack(int cap)
{
    capacity = cap;
    top = -1;
    ptr = new int[cap];
}

Stack::Stack(Stack &d)
{
    capacity = d.capacity;
    top = d.top;
    ptr = new int[capacity];
    for(int i = 0; i<=top; i++)
        ptr[i] = d.ptr[i];   
}

Stack& Stack::operator=(Stack& d)
{
    if(ptr != NULL)
        delete [] ptr;
    capacity = d.capacity;
    top = d.top;
    ptr = new int[capacity];
    for(int i = 0; i<=top; i++)
        ptr[i] = d.ptr[i];   
    return *this;
}

void Stack::push(int data)
{
    if(isFull())
        cout<<"Stack Overflow! Data cannot push.";
    else
    {
        top++;
        ptr[top] = data;
    }
}

int Stack::peek()
{
    if(isEmpty())
        cout<<"Stack Underflow.";
    else
        return ptr[top];
}

void Stack::pop()
{
    if(isEmpty())
        cout<<"Stack Underflow";
    else
        top--;
}

bool Stack::isFull()
{
    return (top == capacity-1);
}

bool Stack::isEmpty()
{
    return (top == -1);
}

Stack::~Stack()
{
    if(ptr != NULL)
        delete [] ptr;
}
