#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() { head = nullptr; }

    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << "\n";
    }

    int countAndDeleteOccurrences(int key) {
        int count = 0;

        while (head && head->data == key) {
            Node* del = head;
            head = head->next;
            delete del;
            count++;
        }

        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* del = curr->next;
                curr->next = curr->next->next;
                delete del;
                count++;
            } else {
                curr = curr->next;
            }
        }

        return count;
    }
};

int main() {
    LinkedList list;
    int n, val, key;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Enter key to delete: ";
    cin >> key;

    cout << "Original Linked List: ";
    list.display();

    int count = list.countAndDeleteOccurrences(key);

    cout << "Count: " << count << "\n";
    cout << "Updated Linked List: ";
    list.display();

    return 0;
}