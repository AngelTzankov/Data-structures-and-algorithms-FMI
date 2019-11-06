#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

struct Queue
{
    int size;
    Node* head;
    Node* tail;

    Queue()
    {
        this->size = 0;
        this->head = this->tail = NULL;
    }

    bool empty()
    {
        return this->size <= 0;
    }

    void push(int val)
    {
        Node* newNode = new Node(val);
        if(this->size == 0)
        {
            this->head = this->tail = newNode;
        }
        else
        {
            newNode->prev = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
        }
        ++this->size;
    }

    void pop()
    {
        if(this->size == 0)
        {
            this->head = this->tail = NULL;
        }
        else
        {
            Node *oldHead = this->head;
            this->head = this->head->next;
            delete oldHead;
        }
        this->size--;
    }

    int front()
    {
        cout<<this->size<<endl;
        if(this->size > 0)
            return this->head->value;
        return -1;
    }

    void clear()
    {
        while(this->head != NULL)
        {
            Node* node = this->head;
            this->head = node->next;
            delete node;
        }
        this->size = 0;
        this->head = this->tail = NULL;
    }
};


int main()
{

}
