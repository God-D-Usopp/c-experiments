#include <iostream>
using namespace std;

class Stack {
public:
    int arr[50]; 
    int top;

    Stack() { 
        top = -1;
    }

    bool isEmpty() { 
        return top == -1;
    }

    bool isFull() { 
        return top == 50 - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "stack is Full, cannot push" << endl; 
        } else {
            top++;
            arr[top] = value; 
            cout << value << " pushed onto the stack" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "stack is empty, cannot pop" << endl;
        } else {
            cout << arr[top] << " popped from the stack" << endl; 
            top--;
        }
    }

    void display() { 
        if (isEmpty()) {
            cout << "stack is empty" << endl;
        } else {
            cout << "stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) { 
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "stack menu" << endl;
        cout << "1-push 2-pop 3-check if empty 4-check if full 5-display 6-exit" << endl;
        cout << "enter your choice: ";
        cin >> choice;

        switch (choice) { 
            case 1:
                cout << "enter value to push: ";
                cin >> value;
                stack.push(value);
                cout<<endl;
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                if (stack.isEmpty()) {
                    cout << "stack is empty" << endl;
                } else {
                    cout << "stack is not empty" << endl;
                }
                break;
            case 4:
                if (stack.isFull()) {
                    cout << "stack is full" << endl;
                } else {
                    cout << "stack is not full" << endl;
                }
                break;
            case 5:
                stack.display();
                break;
            case 6:
                cout << "EXIT" << endl;
                break;
            default:
                cout << "invalid choice" << endl;
        }
    } while (choice != 6); 

    return 0;
}