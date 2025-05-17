#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Stack class
class Stack {
    Node* top = NULL;

public:
    void push(int value) {
        Node* n = new Node(value);
        n->next = top;
        top = n;
        cout << value << " pushed\n";
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped\n";
        delete temp;
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top) pop();
    }
};

// Main function
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top: " << s.peek() << endl;
    s.pop();
    s.display();
    return 0;
}
