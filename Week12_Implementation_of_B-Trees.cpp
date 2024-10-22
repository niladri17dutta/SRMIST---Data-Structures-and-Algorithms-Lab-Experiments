#include <iostream>
using namespace std;

class BTreeNode {
    int *keys;              // Array of keys in the node
    int t;                  // Minimum degree (defines the range for the number of keys)
    BTreeNode **children;    // Array of child pointers
    int n;                  // Current number of keys
    bool leaf;              // True if leaf node

public:
    BTreeNode(int _t, bool _leaf);   // Constructor

    // Function to traverse all nodes in a subtree rooted with this node
    void traverse();

    // Function to search a key in the subtree rooted with this node
    BTreeNode* search(int k);   // Returns NULL if k is not present

    // Function to insert a new key in the subtree rooted with this node
    // When this node is full, the key is not inserted in this node but in the parent node
    void insertNonFull(int k);

    // A utility function to split the child y of this node
    // Note that y must be full when this function is called
    void splitChild(int i, BTreeNode *y);

    // Make BTree a friend so that BTree functions can access private members of BTreeNode
    friend class BTree;
};

class BTree {
    BTreeNode *root;   // Pointer to root node
    int t;             // Minimum degree

public:
    // Constructor (Initializes tree as empty)
    BTree(int _t) {
        root = NULL;
        t = _t;
    }

    // Function to traverse the tree
    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    // Function to search a key in this tree
    BTreeNode* search(int k) {
        return (root == NULL) ? NULL : root->search(k);
    }

    // The main function that inserts a new key in this B-Tree
    void insert(int k);
};

// Constructor for BTreeNode
BTreeNode::BTreeNode(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;

    // Allocate memory for maximum number of possible keys and child pointers
    keys = new int[2 * t - 1];
    children = new BTreeNode *[2 * t];

    // Initialize the number of keys as 0
    n = 0;
}

// Function to traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        // If this is not a leaf, then before printing keys[i],
        // traverse the subtree rooted with child children[i].
        if (leaf == false)
            children[i]->traverse();
        cout << " " << keys[i];
    }

    // Print the subtree rooted with the last child
    if (leaf == false)
        children[i]->traverse();
}

// Function to search key k in subtree rooted with this node
BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (leaf == true)
        return NULL;

    return children[i]->search(k);
}

// Function to insert a new key in the subtree rooted with this node
void BTree::insert(int k) {
    if (root == NULL) {
        // If tree is empty
        root = new BTreeNode(t, true);
        root->keys[0] = k;  // Insert key
        root->n = 1;        // Update number of keys in root
    } else {
        if (root->n == 2 * t - 1) {
            // If root is full, then tree grows in height
            BTreeNode *s = new BTreeNode(t, false);

            // Make old root as a child of new root
            s->children[0] = root;

            // Split the old root and move a key to the new root
            s->splitChild(0, root);

            // New root has two children now. Decide which of the two children will have new key
            int i = (s->keys[0] < k) ? 1 : 0;
            s->children[i]->insertNonFull(k);

            root = s;
        } else
            root->insertNonFull(k);
    }
}

// Function to insert a new key in a node that is not full
void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n = n + 1;
    } else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (children[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        children[i + 1]->insertNonFull(k);
    }
}

// Function to split the child y of this node
void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        children[j + 1] = children[j];

    children[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n = n + 1;
}

// Main function for user-defined input
int main() {
    int t, n, key;

    cout << "Enter the minimum degree of the B-Tree (t): ";
    cin >> t;

    BTree tree(t);

    cout << "Enter the number of keys to insert: ";
    cin >> n;

    cout << "Enter the keys to insert: ";
    for (int i = 0; i < n; i++) {
        cin >> key;
        tree.insert(key);
    }

    cout << "Traversal of the B-Tree is: ";
    tree.traverse();
    cout << endl;

    return 0;
}
