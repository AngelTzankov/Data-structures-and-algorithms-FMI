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

Node* getTreeFromSortedArray(int *arr, int n)
{
    if(n == 0)
        return NULL;
    Node* root = new Node(arr[n/2]);
    root->left = getTreeFromSortedArray(arr, n/2);
    root->right = getTreeFromSortedArray(arr + n/2+1, n-n/2-1);
    return root;
}

int main()
{

}
