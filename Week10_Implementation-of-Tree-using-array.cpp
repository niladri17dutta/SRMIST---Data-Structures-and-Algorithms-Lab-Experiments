#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
private:
    vector<int> treeArray;  // Keeps it private to enforce encapsulation
    int capacity;           // Maximum capacity of the tree

public:
    BinaryTree(int size) {
        treeArray.resize(size, -1);  // Initialize array with -1 to indicate empty slots
        capacity = size;
    }

    void setRoot(int value) {
        treeArray[0] = value;
    }

    void setLeftChild(int parentIndex, int value) {
        int leftChildIndex = 2 * parentIndex + 1;
        if (leftChildIndex < capacity) {
            treeArray[leftChildIndex] = value;
        } else {
            cout << "No space to insert left child for parent at index " << parentIndex << endl;
        }
    }

    void setRightChild(int parentIndex, int value) {
        int rightChildIndex = 2 * parentIndex + 2;
        if (rightChildIndex < capacity) {
            treeArray[rightChildIndex] = value;
        } else {
            cout << "No space to insert right child for parent at index " << parentIndex << endl;
        }
    }

    // Getter function to access treeArray elements
    int getNodeValue(int index) const {
        if (index < capacity) {
            return treeArray[index];
        }
        return -1;  // Return -1 for invalid indices
    }

    void printTree() const {
        cout << "Tree representation in array: ";
        for (int i = 0; i < capacity; i++) {
            if (treeArray[i] != -1)
                cout << treeArray[i] << " ";
            else
                cout << "- ";  // Indicate empty nodes
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the total number of nodes for the tree: ";
    cin >> n;

    BinaryTree tree(n);

    int value, parentIndex, choice;

    cout << "Enter the value for the root: ";
    cin >> value;
    tree.setRoot(value);

    for (int i = 0; i < n; i++) {
        cout << "\nChoose action for node at index " << i << " (current value = " 
             << tree.getNodeValue(i) << "):" << endl;  // Use the getter function
        cout << "1. Set Left Child\n";
        cout << "2. Set Right Child\n";
        cout << "3. Skip this node\n";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter the value for the child: ";
            cin >> value;
            if (choice == 1) {
                tree.setLeftChild(i, value);
            } else if (choice == 2) {
                tree.setRightChild(i, value);
            }
        }
    }

    // Print the final tree structure
    tree.printTree();

    return 0;
}
