#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;      // Array to store queue elements
    int front;     // Front points to the front element in the queue
    int rear;      // Rear points to the last element in the queue
    int size;      // Maximum size of the queue
    int count;     // Current number of elements in the queue

public:
    // Constructor to initialize the queue
    Queue(int s) {
        size = s;  // Set the size of the queue
        arr = new int[size];  // Dynamically allocate memory for the array
        front = 0;  // Initialize front and rear
        rear = -1;
        count = 0;
    }

    // Enqueue operation: Add an element to the rear of the queue
    void enqueue(int value) {
        if (count == size) {
            cout << "Queue is full.\n";
            return;
        }

        // Circular increment of rear
        rear = (rear + 1) % size;
        arr[rear] = value;
        count++;
        cout << value << " enqueued.\n";
    }

    // Dequeue operation: Remove an element from the front of the queue
    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << arr[front] << " dequeued.\n";
        front = (front + 1) % size;  // Circular increment of front
        count--;
    }

    // Display all elements in the queue
    void display() const {
        if (count == 0) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            // Calculate the index in the circular queue
            int index = (front + i) % size;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;  // Deallocate memory used by the array
    }
};

int main() {
    int queueSize;
    cout << "Enter the size of the queue: ";
    cin >> queueSize;

    Queue q(queueSize);  // Create a queue with the specified size
    int choice, value;

    do {
        cout << "\nQueue Menu: 1. Enqueue | 2. Dequeue | 3. Display | 4. Exit\nEnter your choice: ";
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
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
