#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

struct Stack
{
    Node* head;
    int size;
    Stack()
    {
        size = 0;
        head = NULL;
    }

    void push(int x)
    {
        Node *newHead = new Node(x);
        newHead->next = head;
        head = newHead;
        size++;
    }

    void pop()
    {
        if(size <= 1)
        {
            size = 0;
            head = NULL;
            return;
        }
        head = head->next;
    }

    void clear()
    {
        Node* curNode = head;
        while(curNode != NULL)
        {
            delete curNode;
            head = head->next;
            curNode = head;
        }
        size = 0;
    }
};

int main()
{
    Stack stack;
    int n, a;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>a;
        stack.push(a);
    }
    for(int i=0;i<n;++i)
    {
        cout<<stack.head->value<<" ";
        stack.pop();
    }
    cout<<endl;
    stack.clear();
    cout<<stack.size<<endl;
    if(stack.head == NULL)
    {
        cout<<"The stack is empty"<<endl;
    }
}
