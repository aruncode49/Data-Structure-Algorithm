#include <iostream>
#include <stdio.h>

#define QUEUE_UNDERFLOW 1;

using namespace std;

struct node
{
    int item;
    node *next;
};

class Queue
{
private:
    node *front; // point to start node
    node *rear; // point to last node

public:
    Queue();
    Queue(Queue &);
    Queue &operator=(Queue &);
    void insertElement(int);
    int getRear();
    int getFront();
    void deleteFront();
    int countElement();
    ~Queue();
};

Queue::Queue() // initially both node pointers containing null;
{
    front = rear = NULL;
}

Queue::Queue(Queue &q)
{
    front = rear = NULL;
    node *r = q.front;
        while (r != NULL)
        {
            insertElement(r->item);
            r = r->next;
        }       
}

Queue &Queue::operator=(Queue &q)
{
    while (front)
        deleteFront();
    node *r = q.front;
        while (r != NULL)
        {
            insertElement(r->item);
            r = r->next;
        }       
    return *this;
}

void Queue::insertElement(int data)
{
    node *n = new node; // prepare node
    n->item = data;
    n->next = NULL;

    if (front == NULL) // if linked List is empty
    {
        front = n;
        rear = n;
    }
    else // if linked list has one element or more
    {
        rear->next = n;
        rear = n;
    }
}

int Queue::getRear()
{
    if (rear == NULL)
        throw QUEUE_UNDERFLOW;
    return rear->item;
}

int Queue::getFront()
{
    if (front == NULL)
        throw QUEUE_UNDERFLOW;
    return front->item;
}

void Queue::deleteFront()
{
    if (front == NULL)
    {
        throw QUEUE_UNDERFLOW;
    }
    else if (front->next == NULL)   // or we can say that front == rear i.e list has only one element
    {
        delete front;
        front = rear = NULL;
    }
    else
    {
        node *r = front;
        front = front->next;
        delete r;
    }
}

int Queue::countElement()
{
    if(front==NULL)
        return 0;
    else if(front->next == NULL)
        return 1;
    else
    {
        node *r = front;
        int count=1;
        while(r->next == NULL)
        {
            count++;
            r = r->next;
        }
        return count;
    }
}

Queue::~Queue()
{
    while (front)
        deleteFront();
}
