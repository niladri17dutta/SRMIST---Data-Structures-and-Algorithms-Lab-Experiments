#include <iostream>
using namespace std;

class BinaryTree {
private:
    int* treeArray;
    int size;

public:
    // Constructor to initialize tree of given size
    BinaryTree(int n) {
        size = n;
        treeArray = new int[size];

        // Initialize the tree with -1 (assuming -1 represents an empty node)
        for (int i = 0; i < size; i++) {
            treeArray[i] = -1;
        }
    }

    // Insert element into the tree
    void insert(int value, int index) {
        if (index >= size) {
            cout << "Index out of bounds!" << endl;
            return;
        }
        treeArray[index] = value;
    }

    // Function to get left child of a node at index i
    int leftChild(int index) {
        int leftIndex = 2 * index + 1;
        if (leftIndex < size && treeArray[leftIndex] != -1) {
            return treeArray[leftIndex];
        }
        return -1;  // No left child
    }

    // Function to get right child of a node at index i
    int rightChild(int index) {
        int rightIndex = 2 * index + 2;
        if (rightIndex < size && treeArray[rightIndex] != -1) {
            return treeArray[rightIndex];
        }
        return -1;  // No right child
    }

    // Display the tree
    void displayTree() {
        cout << "Tree elements: ";
        for (int i = 0; i < size; i++) {
            if (treeArray[i] != -1) {
                cout << treeArray[i] << " ";
            } else {
                cout << "_ ";  // Represent empty nodes as "_"
            }
        }
        cout << endl;
    }

    // Destructor to free the allocated memory
    ~BinaryTree() {
        delete[] treeArray;
    }
};

int main() {
    int size;
    
    // Get the size of the tree from the user
    cout << "Enter the size of the tree: ";
    cin >> size;
    
    // Create a tree of the given size
    BinaryTree tree(size);

    int value, index;
    char choice;
    
    // Input nodes from the user
    do {
        cout << "Enter the value to insert: ";
        cin >> value;
        cout << "Enter the index to insert the value (0 to " << size - 1 << "): ";
        cin >> index;
        
        // Insert the value at the specified index
        tree.insert(value, index);

        cout << "Do you want to insert another value? (y/n): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');

    // Display the tree
    tree.displayTree();

    // Display left and right children of the root (if root exists)
    if (size > 0) {
        cout << "Left child of root: " << tree.leftChild(0) << endl;
        cout << "Right child of root: " << tree.rightChild(0) << endl;
    }

    return 0;
}