#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node{val, NULL};
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int target, int val) {
        if (head == NULL) return;
        if (head->data == target) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != target)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Target not found!\n";
            return;
        }
        Node* newNode = new Node{val, temp->next};
        temp->next = newNode;
    }

    void insertAfter(int target, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != target)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Target not found!\n";
            return;
        }
        Node* newNode = new Node{val, temp->next};
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteSpecific(int val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Node not found!\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Node found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, target;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before Node\n";
        cout << "4. Insert After Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new value to insert: ";
                cin >> val;
                list.insertBefore(target, val);
                break;
            case 4:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new value to insert: ";
                cin >> val;
                list.insertAfter(target, val);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteSpecific(val);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                list.search(val);
                break;
            case 9:
                list.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}