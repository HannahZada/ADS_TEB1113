#include <iostream>
using namespace std;

// =====================================================
// Binary Search Tree (BST)
// Rule:
// - Values smaller than the current node go to the left
// - Values larger than the current node go to the right
// =====================================================

class Tree {
public:
    int value;
    Tree* left;
    Tree* right;

    // Constructor: create a node with a value
    Tree(int v) : value(v), left(nullptr), right(nullptr) {}

    // =================================================
    // Insert a new value into the BST
    // =================================================
    void insert(int v) {

        // Go to the left subtree
        if (v < value) {

            // If no left child exists, create one
            if (left == nullptr) {
                left = new Tree(v);
            }
            else {
                // Continue searching in the left subtree
                left->insert(v);
            }
        }

        // Go to the right subtree
        else if (v > value) {

            // If no right child exists, create one
            if (right == nullptr) {
                right = new Tree(v);
            }
            else {
                // Continue searching in the right subtree
                right->insert(v);
            }
        }

        // Ignore duplicate values
    }

    // =================================================
    // Search for a value in the BST
    // Returns true if found, otherwise false
    // =================================================
    bool search(int v) {

        // Value found
        if (v == value)
            return true;

        // Search left subtree
        if (v < value)
            return left != nullptr && left->search(v);

        // Search right subtree
        return right != nullptr && right->search(v);
    }

    // =================================================
    // In-order Traversal
    // Left -> Root -> Right
    // Produces sorted output in a BST
    // =================================================
    void displayInOrder() {

        if (left)
            left->displayInOrder();

        cout << value << " ";

        if (right)
            right->displayInOrder();
    }

    // =================================================
    // Pre-order Traversal
    // Root -> Left -> Right
    // Useful for visualizing tree structure
    // =================================================
    void displayPreOrder() {

        cout << value << " ";

        if (left)
            left->displayPreOrder();

        if (right)
            right->displayPreOrder();
    }
};

int main() {

    // =================================================
    // Sample data
    // Inserted in this order to build the BST
    //
    //              50
    //            /    \
    //          30      70
    //         /  \    /  \
    //       20   40  60   80
    // =================================================

    int numbers[] = {50, 30, 70, 20, 40, 60, 80};

    // Create root node
    Tree* root = new Tree(numbers[0]);

    // Insert remaining values
    for (int i = 1; i < 7; i++) {
        root->insert(numbers[i]);
    }

    // =================================================
    // Display traversals
    // =================================================

    cout << "In-Order Traversal (Sorted): ";
    root->displayInOrder();
    cout << endl;

    cout << "Pre-Order Traversal: ";
    root->displayPreOrder();
    cout << endl;

    // =================================================
    // Search tests
    // =================================================

    cout << "Search 60: "
         << (root->search(60) ? "Found" : "Not Found")
         << endl;

    cout << "Search 90: "
         << (root->search(90) ? "Found" : "Not Found")
         << endl;

    return 0;
}
