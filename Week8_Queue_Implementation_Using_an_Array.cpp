#include<iostream>
using namespace std;

class QueueArray {
private:
    int front, rear, size;
    int* queue;

public:
    QueueArray(int s) {
        front = rear = -1;
        size = s;
        queue = new int[size];
    }

    ~QueueArray() {
        delete[] queue;
    }

    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) front = 0;
        queue[++rear] = value;
        cout << "Enqueued " << value << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued " << queue[front++] << endl;
        if (front > rear) front = rear = -1;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;

    cout << "Enter the size of the queue: ";
    cin >> size;

    QueueArray q(size);

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