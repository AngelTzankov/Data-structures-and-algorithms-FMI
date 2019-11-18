#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left, *right;

    Node(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

bool checkIfBST(Node *root, int &prevValue)
{
    if(root == NULL)
        return true;
    if(!checkIfBST(root->left, prevValue))
        return false;
    if(root->value < prevValue)
        return false;
    prevValue = root->value;
    if(!checkIfBST(root->right, prevValue))
        return false;
    return true;
}

int main()
{
    Node *a, *b, *c, *d, *e, *f;
    a = new Node(5);
    b = new Node(3);
    c = new Node(2);
    d = new Node(4);
    e = new Node(6);
    f = new Node(0);
    a->left = b;
    b->left = c;
    b->right = d;
    a->right = e;
    e->right = f;
    int prevValue = -INT_MAX;
    cout<<checkIfBST(a, prevValue);
}
