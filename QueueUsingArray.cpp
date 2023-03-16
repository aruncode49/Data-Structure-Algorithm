#include<iostream>
#include<stdio.h>
using namespace std;

#define QUEUE_UNDERFLOW 1;  // defining an exception for empty queue;

class Queue
{
    private:
        int capacity;
        int front;
        int rear;
        int *ptr;
    public:
        Queue();
        Queue(int);
        Queue(Queue&);
        Queue& operator=(Queue &);
        void insertAtRear(int);
        bool isOverflow();
        bool isUnderflow();
        int viewRearElement();
        int viewFrontElement();
        void deleteFront();
        int countElement();
        ~Queue();

};

Queue::Queue()
{
    capacity = 0;
    front = rear = -1;
    ptr = NULL; 
}

Queue::Queue(int cap)   // constructor
{
    capacity = cap;
    front = rear = -1; // initially queue is empty.
    ptr = new int[cap];
}

Queue::Queue(Queue& q)  // copy constructor
{
    capacity = q.capacity;
    front = q.front;
    rear = q.rear;
    ptr = new int[capacity];
    for(int i = 0; i<capacity; i++)
        ptr[i] = q.ptr[i];
}

Queue& Queue::operator=(Queue &q)
{
    if(ptr != NULL)
        delete [] ptr;  // this-> deleting the memory of pointer for( if it containes any other location)
    capacity = q.capacity;
    front = q.front;
    rear = q.rear;
    ptr = new int[capacity];
    for(int i = 0; i<capacity; i++)
        ptr[i] = q.ptr[i];
    return *this;
}

void Queue::insertAtRear(int data)
{
    if(isOverflow())     // when queue is full
        cout<<"Queue Overflow! Data cannot inserted.";

    else if(isUnderflow())  // when queue is empty
    {
        front = rear = 0;
        ptr[front] = data;
    }
    else if(rear == capacity-1)    // when queue is full from rear but front space is empty
    {
        rear = 0;
        ptr[rear] = data;
    }
    else     // normal case
    {
        rear++;
        ptr[rear] = data;
    }
}

bool Queue::isOverflow()    // for checking our queue is full or not
{
    if(rear == capacity-1 && front == 0 || rear + 1 == front)
        return true;        
    else                       
        return false;
}

bool Queue::isUnderflow()   // for checking our queue is empty or not
{
    if(rear == -1 && front == -1)   // checking for both rear or front is not necessary
        return true;
    else
        return false;
}

int Queue::viewRearElement() // for getting last or latest element inserted in queue
{
    if(isUnderflow())
        throw QUEUE_UNDERFLOW; 
    return ptr[rear];
}

int Queue::viewFrontElement() // for getting first or oldest element inserted in queue
{
    if(isUnderflow())
        throw QUEUE_UNDERFLOW;
    return ptr[front];
}

void Queue::deleteFront()
{
    if(isUnderflow())   // when queue is empty
        cout<<"Queue Underflow! Deletion not possible.";
    else if(front == rear)  // when queue has only one element
        front = rear = -1;
    else if(front == capacity-1)   // when front is our last element
        front = 0;
    else    // normal case
        front++; 
}

int Queue::countElement()
{
    if(isOverflow())    // if queue is full 
        return capacity;
    else if(isUnderflow())  // if queue is empty
        return 0;
    else if(rear == front)  // if queue has only one element
        return 1;
    else if(rear > front)   // if rear is greater than front
        return (rear-front+1);
    else 
        return capacity-front+rear+1;   // if any case other than all these
    
}

Queue::~Queue()     
{
    if(ptr != NULL)
        delete [] ptr;  // not necessary to check the NULL Condition because of parametrised constructor.
}

