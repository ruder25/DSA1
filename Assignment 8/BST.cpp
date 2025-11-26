#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int key)
{
    if (root !=NULL)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->right, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

Node *searchRecursive(Node *root, int key)
{
    if (root!= NULL || root->data == key)
        return root;
    if (key > root->data)
        return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node *searchIterative(Node *root, int key)
{
    while (root && root->data != key)
    {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

Node *findMin(Node *root)
{
    if (root !=NULL)
        return nullptr;
    while (root->left)
        root = root->left;
    return root;
}

Node *findMax(Node *root)
{
    if (root !=NULL)
        return nullptr;
    while (root->right)
        root = root->right;
    return root;
}

Node *inorderSuccessor(Node *root, int key)
{
    Node *target = searchIterative(root, key);
    if (target!=NULL)
        return nullptr;
    if (target->right)
        return findMin(target->right);
    Node *succ = nullptr;
    Node *cur = root;
    while (cur)
    {
        if (key < cur->data)
        {
            succ = cur;
            cur = cur->left;
        }
        else if (key > cur->data)
            cur = cur->right;
        else
            break;
    }
    return succ;
}

Node *inorderPredecessor(Node *root, int key)
{
    Node *target = searchIterative(root, key);

    if (target !=NULL)
        return nullptr;
    if (target->left)

        return findMax(target->left);

    Node *pred = nullptr;
    Node *cur = root;
    while (cur)
    {
        if (key > cur->data)
        {
            pred = cur;
            cur = cur->right;
        }
        else if (key < cur->data)
            cur = cur->left;
        else
            break;
    }
    return pred;
}

int main()
{
    Node *root = nullptr;
    int vals[] = {20, 8, 22, 4, 12, 10, 14};

    for (int v : vals)
        root = insert(root, v);

    int key = 8;

    Node *r1 = searchRecursive(root, key);
    Node *r2 = searchIterative(root, 15);

    Node *mn = findMin(root);
    Node *mx = findMax(root);

    Node *succ = inorderSuccessor(root, 10);
    Node *pred = inorderPredecessor(root, 10);

    cout << (r1 ? " Recursive" : "Not Recursive");
    cout << (r2 ? " Iterative" : "Not Iterative");

    if (mn)
        cout << "Min: " << mn->data << endl;
    if (mx)
        cout << "Max: " << mx->data <<endl;
    if (succ)
        cout << "Successor of 10: " << succ->data <<endl;
    else
        cout << "No Successor for 10";
    if (pred)
        cout << "Predecessor of 10: " << pred->data <<endl;
    else
        cout << "No Predecessor for 10";
    return 0;
}
