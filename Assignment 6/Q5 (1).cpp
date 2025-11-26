#include <iostream>
using namespace std;

class Node
{
public:
    char val;
    Node *next;
    Node *prev;

    Node(char ch)
    {
        val = ch;
        next = prev = NULL;
    }
};

Node *head = NULL;

void insertatend(char ch)
{

    Node *newNode = new Node(ch);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
}

void checkcircular()
{
    if (head == NULL)
        cout << "list is empty";

    Node *temp = head;

    do
    {
        temp = temp->next;
    }

    while (temp != head);
    if (temp == head)
        cout << "linked list is circular";
}

int main()
{
    insertatend('a');
    insertatend('b');
    insertatend('c');
    insertatend('d');
    insertatend('a');

    checkcircular();
    return 0;
}
