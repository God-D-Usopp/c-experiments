#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    int n;
    LinkedList() {
        head = nullptr;
        n = 0;
    }

    void insert(int value) {    //
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        n++; //
    }

    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl; //
    }

    void deleteNode(int value) {
        if (!head) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << value << " deleted from list" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << value << " deleted from list" << endl;
        } else {
            cout << value << " not present in list" << endl;
        }
    }

    void search(int value) {
        Node* temp = head;
        int position = 1;
        while (temp) {
            if (temp->data == value) {
                cout << value << " found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << value << " not found in list" << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, n;

    do {
        cout << "\nLinked List Menu:\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of values to insert: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cout << "Enter value: ";
                    cin >> value;
                    list.insert(value);
                }
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 4:
                list.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}