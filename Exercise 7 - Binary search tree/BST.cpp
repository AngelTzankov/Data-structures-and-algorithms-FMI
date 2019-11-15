#include <iostream>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int value;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

struct BST
{
    Node* root = NULL;

    Node* getRoot()
    {
        return root;
    }

    //tested
    Node* find(Node* curNode, int value)
    {
        if(curNode == NULL)
            return NULL;
        if(curNode->value == value)
            return curNode;
        if(curNode->value < value)
            return find(curNode->right, value);
         return find(curNode->left, value);
    }

    //tested
    Node* insert(Node *curNode, int value)
    {
        if(this->root == NULL)
        {
            this->root = new Node(value);
            return this->root;
        }
        if(curNode == NULL)
        {
            return new Node(value);
        }
        if(curNode->value < value)
        {
            curNode->right = insert(curNode->right, value);
        }
        else
        {
            curNode->left = insert(curNode->left, value);
        }
        return curNode;
    }

    //tested
    Node* remove(Node* curNode, int value)
    {
        if(curNode == NULL)
        {
            return NULL;
        }
        if(curNode->value < value)
        {
            curNode->right = remove(curNode->right, value);
        }
        else if(curNode->value > value)
        {
            curNode->left = remove(curNode->left, value);
        }
        else
        {
            if(curNode->left == NULL)
            {
                Node* tmp = curNode->right;
                delete curNode;
                return tmp;
            }
            Node* maxInLeftSubTree = curNode->left;
            while(maxInLeftSubTree->right != NULL)
            {
                maxInLeftSubTree = maxInLeftSubTree->right;
            }
            curNode->value = maxInLeftSubTree->value;
            curNode->left = remove(curNode->left, curNode->value);
        }
        return curNode;
    }

    //tested
    void printSorted(Node *root)
    {
        if(root == NULL)
        {
            return;
        }
        printSorted(root->left);
        cout<<root->value<<" ";
        printSorted(root->right);
    }

    //tested
    Node* findMax(Node *root)
    {
        if(root->right != NULL)
        {
            return findMax(root->right);
        }
        return root;
    }

    //tested
    Node* findMin(Node *root)
    {
        if(root->left != NULL)
        {
            return findMin(root->left);
        }
        return root;
    }

    //tested
    Node* lowerBound(Node* root, int value)
    {
        if(root == NULL)
        {
            return NULL;
        }

        if(root->value > value)
        {
            return lowerBound(root->left, value);
        }
        else
        {
            if(root->right == NULL)
            {
                return root;
            }
            if(root->right->value <= value)
            {
                return lowerBound(root->right, value);
            }
            if(root->value <= value)
                return root;
            return NULL;
        }
        return NULL;
    }
};

int main()
{

}
