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

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertMultiple(int count) {
        for (int i = 0; i < count; i++) {
            int value;
            cout << "Enter value " << i + 1 << ": ";
            cin >> value;

            Node* newNode = new Node(value);

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
            cout << "Deleted node at position " << position << " from the list.\n";
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        for (int i = 1; current != nullptr && i < position; i++) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Position " << position << " is out of range.\n";
            return;
        }

        previous->next = current->next;
        if (current == tail) {
            tail = previous;
        }
        delete current;
        cout << "Deleted node at position " << position << " from the list.\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~SinglyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void showMenu() {
    cout << "\nMenu Options:\n";
    cout << "1. Insert multiple elements\n";
    cout << "2. Delete element at a position\n";
    cout << "3. Display list\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    SinglyLinkedList sll;
    int choice, count, position;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of elements to insert: ";
                cin >> count;
                sll.insertMultiple(count);
                break;

            case 2:
                cout << "Enter the position of the element to delete: ";
                cin >> position;
                sll.deleteAtPosition(position);
                break;

            case 3:
                sll.display();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}