#include <iostream>
using namespace std;

struct Data {
    int id;
    string name;
};

struct Node {
    Data data;
    Node* next;
};

class StackLinkedList {
    Node* top;

public:
    StackLinkedList() { top = NULL; }

    void push(Data data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        cout << "Pushed element: ID = " << data.id << ", Name = " << data.name << "\n";
    }

    Data pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return {-1, ""};
        } else {
            Node* temp = top;
            top = top->next;
            Data poppedData = temp->data;
            delete temp;
            cout << "Popped element: ID = " << poppedData.id << ", Name = " << poppedData.name << "\n";
            return poppedData;
        }
    }

    bool isEmpty() { return top == NULL; }

    Data peek() {
        if (top == NULL) {
            cout << "Stack is Empty\n";
            return {-1, ""};
        } else {
            return top->data;
        }
    }
};

int main() {
    StackLinkedList stack;
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
