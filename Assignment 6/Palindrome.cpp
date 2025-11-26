#include <iostream>
using namespace std;

class LL
{
public:
    char val;
    LL *next;
    LL *prev;

    LL()
    {                        //DEFAULT
        val = ' ';
        next = prev = NULL;
    }
    LL(char ch)
    {
        val = ch;
        next = prev = NULL;
    }
};

LL *head = NULL;


void insertatend(char ch)
{
    LL *newNode = new LL(ch);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }
    LL *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
}

bool checkpalindrome()
{
    if (head == NULL)
    {
        return true;
    }
    LL *left = head;
    LL *right = head->prev;

    while (left != right && right->prev != left)
    {
        if (left->val != right->val)
        {
            return false;
        }
        else
        {
            left = left->next;
            right = right->prev;
        }
    }
    return true; 
}

int main()
{
    insertatend('r');
    insertatend('a');
    insertatend('d');
    insertatend('s');
    insertatend('r');

    if (checkpalindrome())
    {
        cout << "Linked list is palindrome" << endl;
    }
    else
    {
        cout << "Linked list is not palindrome" << endl;
    }

    return 0;
}