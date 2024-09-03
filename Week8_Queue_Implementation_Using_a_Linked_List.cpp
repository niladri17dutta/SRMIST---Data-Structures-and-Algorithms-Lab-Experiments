#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    QueueLinkedList() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* temp = new Node(value);
        if (rear == NULL) {
            front = rear = temp;
            cout << "Enqueued " << value << endl;
            return;
        }
        rear->next = temp;
        rear = temp;
        cout << "Enqueued " << value << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == NULL) rear = NULL;

        cout << "Dequeued " << temp->data << endl;
        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int choice, value;

    QueueLinkedList q;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to enqueue: ";
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
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
