#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

struct List
{
    int listSize;
    Node* head;
    Node* tail;
};

void init(List& list)
{
    list.listSize = 0;
    list.head = NULL;
    list.tail = NULL;
}

bool empty(List& list)
{
    return list.listSize == 0;
}

Node* at(List& list, int idx)
{
    int curIdx = 0;
    Node* curNode = list.head;
    while(curIdx != idx && curNode != NULL)
    {
        curIdx++;
        curNode = curNode->next;
    }
    if(idx > curIdx)
        return NULL;
    return curNode;
}

void push_front(List& list, Node* node)
{
    if(list.listSize == 0)
    {
        list.head = node;
        list.tail = node;
    }
    else
    {
        node->next = list.head;
        list.head->prev = node;
        list.head = node;
    }
    list.listSize++;
}

void push_back(List& list, Node* node)
{
    if(listSize == 0)
    {
        list.head = node;
        list.tail = node;
    }
    else
    {
        node->prev = list.tail;
        list.tail->next = node;
        list.tail = node;
    }
    ++list.listSize;
}

void insert(List& list, int idx, Node* node)
{
    Node *nodeAtIdx = at(list, idx);
    if(idx <= 0)
        push_front(list, node);
    if(idx >= list.listSize)
        push_back(list, node);
    Node *nodeBeforeIdx = nodeAtIdx->prev;
    nodeBeforeIdx->next = node;
    node->prev = nodeBeforeIdx;
    nodeAtIdx->prev = node;
    node->next = nodeAtIdx;
    list.listSize++;
}

void pop_front(List& list)
{
    if(list.listSize  == 1)
    {
        list.head = NULL;
        list.tail = NULL;
        list.listSize--;
    }
    else if(list.listSize > 1)
    {
        list.head = list.head->next;
        list.head->prev = NULL;
        list.listSize--;
    }
}

void pop_back(List& list)
{
    if(list.listSize <= 1)
    {
        list.tail = NULL;
        list.head = NULL;
        list.listSize = 0;
    }
    else
    {
        list.tail = list.tail->prev;
        list.tail->next = NULL;
        list.listSize--;
    }
}

void erase(List& list, int idx)
{
    if(idx <= 0)
    {
        pop_front(list);
    }
    else if(idx >= list.listSize-1)
    {
        pop_back(list);
    }
    else
    {
        cout<<"asfas"<<endl;
        Node* nodeAtIdx = at(list, idx);
        Node* nodeAfterIdx = nodeAtIdx->next;
        Node* nodeBeforeIdx = nodeAtIdx->prev;
        nodeAfterIdx->prev = nodeBeforeIdx;
        nodeBeforeIdx->next = nodeAfterIdx;
        list.listSize--;
    }
}

void print(List& list)
{
    Node* node = list.head;
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

int main()
{

    ///tests
    Node node(5);
    List list;
    init(list);
    push_front(list,new Node(1));
    push_front(list,new Node(2));
    push_front(list,new Node(3));
    push_front(list,new Node(4));
    push_front(list,new Node(5));
    push_back(list, new Node(6));
    pop_back(list);
    cout<<list.listSize<<endl;
    cout<<at(list, 3)->data<<endl;
    erase(list, 3);
    print(list);
    erase(list, 0);
    erase(list, 0);
    erase(list, 0);
    erase(list, 0);
    print(list);
}
