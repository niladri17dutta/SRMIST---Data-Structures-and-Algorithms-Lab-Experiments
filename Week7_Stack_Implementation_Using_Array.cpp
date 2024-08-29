#include <iostream>
using namespace std;

#define MAX 100

struct Data {
    int id;
    string name;
};

class StackArray {
    Data stack[MAX];
    int top;

public:
    StackArray() { top = -1; }

    void push(Data data) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow\n";
        } else {
            stack[++top] = data;
            cout << "Pushed element: ID = " << data.id << ", Name = " << data.name << "\n";
        }
    }

    Data pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return {-1, ""};
        } else {
            Data data = stack[top--];
            cout << "Popped element: ID = " << data.id << ", Name = " << data.name << "\n";
            return data;
        }
    }

    bool isEmpty() { return top < 0; }

    Data peek() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return {-1, ""};
        } else {
            return stack[top];
        }
    }
};

int main() {
    StackArray stack;
    int choice;
    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Data data;
                cout << "Enter ID: ";
                cin >> data.id;
                cout << "Enter Name: ";
                cin >> data.name;
                stack.push(data);
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3: {
                Data data = stack.peek();
                if (data.id != -1) {
                    cout << "Top element: ID = " << data.id << ", Name = " << data.name << "\n";
                }
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
