#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int x) {
          data= x;
         next= NULL;
    }
};

void displayCircular(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node *temp = head;

    cout << temp->data << " ";

    temp = temp->next;

    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

  
    cout << head->data;
}


int main()
{
    
    Node *head = new Node(20);
    Node *n1 = new Node(100);
    Node *n2 = new Node(40);
    Node *n3 = new Node(80);
    Node *n4 = new Node(60);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = head; 

    displayCircular(head);

    return 0;
}
