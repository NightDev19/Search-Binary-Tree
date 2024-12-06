#include <iostream>
using namespace std;

// Define the structure of a Node in the Binary Search Tree
struct Node {
    int value;
    Node* left;
    Node* right;

    // Constructor to initialize a new node with a given value
    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};

// Function to insert a new node into the BST
void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value); // If the tree is empty, create a new node
        cout << "Added " << value << " to the tree." << endl;
    }
    else if (value < root->value) {
        insert(root->left, value); // Insert in the left subtree
    }
    else {
        insert(root->right, value); // Insert in the right subtree
    }
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node in the BST
void delNode(Node*& root, int value) {
    if (root == nullptr) {
        return; // If the tree is empty, nothing to delete
    }

    // Search for the node to delete
    if (value < root->value) {
        delNode(root->left, value); // Go left
    }
    else if (value > root->value) {
        delNode(root->right, value); // Go right
    }
    else {
        // If the node to be deleted is found
        cout << "Deleted " << root->value << " from the tree." << endl;

        // Case 1: Node has no children (Leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // Case 2: Node has one child
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Node has two children
        else {
            // Find the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);
            root->value = temp->value; // Copy the inorder successor's value to the current node
            delNode(root->right, temp->value); // Delete the inorder successor
        }
    }
}

// Function to print the inorder traversal of the BST
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left); // Visit left subtree
    cout << root->value << " "; // Print the current node
    inorder(root->right); // Visit right subtree
}

// Main function to demonstrate the Binary Search Tree
int main() {
    Node* root = nullptr; // Start with an empty tree

    // Insert nodes
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 50);
    insert(root, 65);
    insert(root, 75);
    insert(root, 90);

    cout << "\nInorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    // Delete nodes
    delNode(root, 60);
    delNode(root, 80);
    delNode(root, 50);

    cout << "\nInorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
