#include <iostream>
using namespace std;

struct Node {
    Node *left = NULL;
    Node *right = NULL;
    int valueue;
    int subTreeSize = -1;
};

int getSize(Node* root)
{
    if(root == NULL)
        return 0;
    if(root->subTreeSize != -1)
    {
        return root->subTreeSize;
    }
    return root->subTreeSize = getSize(root->left) + getSize(root->right) + 1;
}

bool isComplete(Node *root)
{
    if(root == NULL)
        return true;
    if(isComplete(root->left) && isComplete(root->right)
        && getSize(root->left) == getSize(root->right))
            return true;
    return false;
}

int main()
{

}
