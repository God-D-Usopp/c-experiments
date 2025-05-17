#include <iostream>
using namespace std;

// Node class for linked list structure
class Node {
public:
    int data;  // Holds the data
    Node* next;  // Pointer to the next node in the list

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class that uses linked list
class Queue {
private:
    Node* front;  // Points to the first node
    Node* rear;   // Points to the last node

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation: Adds a new element at the rear
    void enqueue(int value) {
        Node* newNode = new Node(value);  // Create a new node

        if (rear == nullptr) {
            // If queue is empty, both front and rear will point to the new node
            front = rear = newNode;
        } else {
            rear->next = newNode;  // Add new node after rear
            rear = newNode;        // Update rear to the new node
        }
        cout << value << " has been enqueued.\n";
    }

    // Dequeue operation: Removes the front element
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;  // Save the front node
        front = front->next;  // Move the front pointer to the next node

        if (front == nullptr) {
            rear = nullptr;  // If the queue is now empty, set rear to nullptr
        }

        cout << temp->data << " has been dequeued.\n";
        delete temp;  // Free the memory of the removed node
    }

    // Display operation: Shows all elements in the queue
    void display() const {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor: Deallocate all the memory used by the queue
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
