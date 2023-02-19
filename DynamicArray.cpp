#include<stdio.h>
#include<iostream>
using namespace std;

class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *p;

    protected:
        void doubleArray();
        void halfArray();
    public:
        DynArray(int);               // parametrised constructor 
        DynArray(DynArray &);           // copy constructor for deep copy
        DynArray& operator=(DynArray&); // copy assignment operator for deep copy
        bool is_empty();          // is empty function for checking empty
        bool is_full();           // is full function for checking full
        void append(int);         // append function for adding element at last index
        void insert(int,int);     // insert function for inserting element at particular index
        void edit(int,int);       // edit function for edit element at particular index
        void del(int);            // delete function for deleting element at particular index
        int getItem(int);         // get item function for get element at particular index
        int count();              // count function for counts the number of elements present inside array
        int getElementIndex(int); // for getting index at particular index
        ~DynArray();                 // destructor
};

void DynArray::doubleArray()
{
    int *temp;
    temp = new int[capacity*2];
    for(int i = 0; i < lastIndex; i++)
        temp[i] = p[i];
    delete []p;
    p = temp;
    capacity *= 2;
}

void DynArray::halfArray()
{
    int *temp;
    temp = new int[capacity/2];
    for(int i = 0; i < lastIndex; i++)
        temp[i] = p[i];
    delete []p;
    p = temp;
    capacity /=2;
}

DynArray& DynArray::operator=(DynArray& arr)
{
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    if(p != NULL)
        delete []p;
    p = new int[capacity];
    for(int i = 0; i < lastIndex; i++)
        p[i] = arr.p[i];
    return (*this);
}

DynArray::DynArray(DynArray &arr)
{
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    if(p != NULL)
        delete []p;
    p = new int[capacity];
    for(int i = 0; i < lastIndex; i++)
        p[i] = arr.p[i];
}

DynArray::DynArray(int)
{
    p=NULL;
}

DynArray::DynArray (int size) 
{
    capacity = size;
    lastIndex = -1;
    if(p != NULL)
        delete []p;
    p = new int[capacity];   
}

bool DynArray::is_empty() 
{
    return (lastIndex == -1);
}

bool DynArray::is_full()
{
    return (lastIndex+1 == capacity);
}

void DynArray::append(int data)
{
    if(is_full())
        doubleArray();
    lastIndex++;
    p[lastIndex]=data;  
}

void DynArray::insert(int index, int data)
{
    int i;
    try{
        if(index<0 || index>lastIndex+1)
            throw 1;
        if(is_full())
            doubleArray();
        for(i = lastIndex; i>=index; i--)
            p[i+1] = p[i];
        p[index] = data;
        lastIndex++;
    }
    catch(int e){
        if(e==1)
           cout<<"Invalid Index";
    }
}

void DynArray::edit(int index, int data)
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

void DynArray::del(int index)
{
    int i;
    try{
        if(index < 0 || index > lastIndex)
            throw 1;
        for(i = index; i < lastIndex; i++)
            p[i] = p[i+1];
        lastIndex--;
        if(capacity > 1 && lastIndex+1 < capacity/2)
            halfArray();
    }
    catch(int e){
        if(e==1)
        cout<<"Invalid Index";
    }
}

int DynArray::getItem(int index)
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

int DynArray::count()
{
    return lastIndex+1;
}

int DynArray::getElementIndex(int element)
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

DynArray::~DynArray()
{
    delete []p;
}
