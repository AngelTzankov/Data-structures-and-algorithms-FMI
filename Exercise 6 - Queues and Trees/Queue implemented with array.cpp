#include <iostream>
using namespace std;

struct Queue
{
    int arr[1000];
    int size;

    Queue()
    {
        this->size = 0;
    }

    bool empty()
    {
        return this->size <= 0;
    }

    int front()
    {
        return this->arr[this->size-1];
    }

    void pop()
    {
        --this->size;
    }

    int push(int x)
    {
        this->arr[this->size++] = x;
    }

    void clear()
    {
        this->size = 0;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}
