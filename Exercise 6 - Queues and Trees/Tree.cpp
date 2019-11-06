#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int value;
    vector<Node*> children;
    Node(int value)
    {
        this->value = value;
    }
};

struct tree
{
    Node* root;
};

void traverse_in_depth(Node* root)
{
    cout<<root->value<<" ";
    for(int i=0;i<root->children.size();++i)
    {
        traverse_in_depth(root->children[i]);
    }
}

void traverse_in_breadth(Node* root)
{
    queue<Node*> nodes;
    nodes.push(root);
    while(!nodes.empty())
    {
        cout<<nodes.front()->value<<" ";
        Node* curNode = nodes.front();
        for(int i=0;i<curNode->children.size();++i)
        {
            nodes.push(curNode->children[i]);
        }
        nodes.pop();
    }
}

int main()
{
    Node a(0), b(1), c(2), d(3), e(4), f(5);
    a.children.push_back(&b);
    a.children.push_back(&c);
    a.children.push_back(&d);
    b.children.push_back(&e);
    b.children.push_back(&f);
    traverse_in_depth(&a);
    cout<<endl;
    traverse_in_breadth(&a);
}
