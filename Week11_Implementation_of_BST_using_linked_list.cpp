#include <iostream>
using namespace std;

// Define the structure of a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Class to represent the BST
class BST {
    Node* root;

public:
    // Constructor to initialize the root of the tree
    BST() {
        root = nullptr;
    }

    // Function to insert a new node in the BST
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Function to search for a value in the BST
    bool search(int value) {
        return searchRec(root, value);
    }

    // Function to display the BST in inorder traversal (sorted order)
    void inorderTraversal() {
        inorderRec(root);
        cout << endl;
    }

private:
    // Helper function to insert a node recursively
    Node* insertRec(Node* node, int value) {
        // Base case: If the tree is empty, create a new node
        if (node == nullptr) {
            return new Node(value);
        }

        // If the value is smaller, go to the left subtree
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        }
        // If the value is larger, go to the right subtree
        else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        // Return the unchanged node pointer
        return node;
    }

    // Helper function to search for a value recursively
    bool searchRec(Node* node, int value) {
        // Base case: The tree is empty or the value is found
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }

        // If the value is smaller, search in the left subtree
        if (value < node->data) {
            return searchRec(node->left, value);
        }
        // If the value is larger, search in the right subtree
        return searchRec(node->right, value);
    }

    // Helper function for inorder traversal (left-root-right)
    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);  // Traverse left subtree
            cout << node->data << " ";  // Visit root node
            inorderRec(node->right);  // Traverse right subtree
        }
    }
};

// Main function
int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n1. Insert a node\n2. Search for a value\n3. Display inorder traversal\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            tree.insert(value);
            cout << "Value inserted." << endl;
            break;
        case 2:
            cout << "Enter the value to search: ";
            cin >> value;
            if (tree.search(value)) {
                cout << "Value found in the tree." << endl;
            } else {
                cout << "Value not found." << endl;
            }
            break;
        case 3:
            cout << "Inorder traversal of the BST: ";
            tree.inorderTraversal();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
