#include <iostream>
using namespace std;

struct Node
{
    Node *left, *right;
    int value;
    Node(int value)
    {
        left = NULL;
        right = NULL;
        this->value = value;
    }
};

void removeSubtrees(Node *root, int value)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left != NULL)
    {
        if(root->left->value == value)
            root->left = NULL;
    }
    if(root->right != NULL)
    {
        if(root->right->value == value)
            root->right = NULL;
    }
    removeSubtrees(root->left, value);
    removeSubtrees(root->right, value);
}

int main()
{

}
