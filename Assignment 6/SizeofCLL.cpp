#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class CircularLinkedList
{
public:
    Node *tail;
    CircularLinkedList() { tail = NULL; }

    void insertEnd(int x)
    {
        Node *n = new Node(x);
        if (tail == NULL)
        {
            tail = n;
            tail->next = tail;
            return;
        }
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }

    int size()
    {
        if (tail == NULL)
            return 0;
        Node *temp = tail->next;
        int count = 1;
        while (temp->next != tail->next)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main()
{
    CircularLinkedList cll;
    cll.insertEnd(10);
    cll.insertEnd(20);
    cll.insertEnd(30);
    cll.insertEnd(40);

    cout << cll.size();
    return 0;
}
