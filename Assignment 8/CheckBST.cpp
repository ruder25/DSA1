#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

bool isBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->data <= min || root->data >= max)
        return false;

    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

bool isBST(Node *root)
{
    return isBST(root, -1000000, 1000000);

}

int main()
{
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);

    if (isBST(root))
    
        cout << "This Tree is a BST";
    else
        cout << "This Tree is NOT a BST";

    return 0;
}
