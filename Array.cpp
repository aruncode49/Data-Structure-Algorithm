#include<stdio.h>
#include<iostream>
using namespace std;

class Array
{
    private:
        int capacity;
        int lastIndex;
        int *p;
    public:
        Array(int);
        bool is_empty();
        bool is_full();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        int getItem(int);
        int count();
        int getElementIndex(int);
        ~Array();
};

Array::Array(int)
{
    p=NULL;
}

Array::Array (int size) 
{
    capacity = size;
    lastIndex = -1;
    if(p != NULL)
        delete []p;
    p = new int[capacity];   
}

bool Array::is_empty() 
{
    return (lastIndex == -1);
}

bool Array::is_full()
{
    return (lastIndex+1 == capacity);
}

void Array::append(int data)
{
    if(!is_full())
    {
        lastIndex++;
        p[lastIndex]=data;
    }
    else
        cout<<"Overflow: appending not possible";
}

void Array::insert(int index, int data)
{
    int i;
    try{
        if(index<0 || index > lastIndex+1)
            throw 1;
        if(is_full())
            throw 2;
        for(i = lastIndex; i>=index; i--)
            p[i+1] = p[i];
        p[index] = data;
        lastIndex++;
    }
    catch(int e){
        if(e==1)
           cout<<"Invalid Index";
        else if(e==2) 
            cout<<"Array is full, so insert of new element is not possible.";
    }
}

void Array::edit(int index, int data)
{
    try{
        if(index<0 || index > lastIndex+1)
            throw 1;
        p[index] = data;
    }
    catch(int e)
    {
        if(e==1)
           cout<<"Invalid Index";
    }
}

void Array::del(int index)
{
    int i;
    try{
        if(index < 0 || index > capacity)
            throw 1;
        for(i = index; i < lastIndex; i++)
            p[i] = p[i+1];
        lastIndex--;
    }
    catch(int e){
        if(e==1)
        cout<<"Invalid Index";
    }
}

int Array::getItem(int index)
{
    try{
        if(index < 0 || index > lastIndex)
            throw 1;
        return p[index];
    }
    catch(int e){
        if(e==1)
            cout<<"Invalid Index";
    }
    return -1; 
}

int Array::count()
{
    return lastIndex+1;
}

int Array::getElementIndex(int element)
{
    int i;
    for(i=0; i<=lastIndex; i++)
    {
        if(p[i] == element)
            return i;
        else
            return -1;
    }
}

Array::~Array()
{
    delete []p;
}
