#include <iostream>
using namespace std;

const size_t MAX_SIZE = 100;

class List {
private:
    int array[MAX_SIZE];
    size_t size;

public:
    List() : size(0) {}

    void append(int value) {
        if (size < MAX_SIZE) {
            array[size++] = value;
        } else {
            cout << "List is full, cannot append more elements.\n";
        }
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    List myList;
    int numElements;
    int value;

    cout << "Enter the number of elements you want to add to the list: ";
    cin >> numElements;

    if (numElements > MAX_SIZE) {
        cout << "The number of elements exceeds the maximum size of " << MAX_SIZE << ".\n";
        return 1;
    }

    for (int i = 0; i < numElements; ++i) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> value;
        myList.append(value);
    }

    cout << "List elements: ";
    myList.print();
    return 0;
}