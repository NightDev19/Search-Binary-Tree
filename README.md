# Binary Search Tree (BST) Code Explanation

This document explains each function in the provided Binary Search Tree (BST) implementation in C++. It includes the purpose of each function and a step-by-step explanation of how it works.

## Program Code

```cpp
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};
```

Node Structure:
Node structure: Represents a single node in the binary search tree (BST).
int value: Holds the value of the node.
Node* left: A pointer to the left child node.
Node* right: A pointer to the right child node.
The constructor initializes value with the given value, and both left and right pointers are set to nullptr (indicating no children initially).


Certainly! Below is the Markdown (MD) file explaining the C++ code function by function.

markdown
Copy code
# Binary Search Tree (BST) Code Explanation

This document explains each function in the provided Binary Search Tree (BST) implementation in C++. It includes the purpose of each function and a step-by-step explanation of how it works.

## Program Code

```
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};
```
## Node Structure:
Node structure: Represents a single node in the binary search tree (BST).
int value: Holds the value of the node.
Node* left: A pointer to the left child node.
Node* right: A pointer to the right child node.
The constructor initializes value with the given value, and both left and right pointers are set to nullptr (indicating no children initially).

## 1. insert Function

```
void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value); 
        cout << "Added " << value << " to the tree." << endl;
    } else if (value < root->value) {
        insert(root->left, value); 
    } else {
        insert(root->right, value); 
    }
}
void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value); 
        cout << "Added " << value << " to the tree." << endl;
    } else if (value < root->value) {
        insert(root->left, value); 
    } else {
        insert(root->right, value); 
    }
}
```
## Explanation:
<i><b>Purpose</b></i>: Inserts a new node with the specified value into the tree.
## Steps:
1. If the root is nullptr: This means the tree (or subtree) is empty, so a new node with value is created, and the root pointer is updated to point to this new node.
2. If the value is less than the current node's value: The function is called recursively to insert the value into the left subtree.
3. If the value is greater than or equal to the current node's value: The function is called recursively to insert the value into the right subtree.

The recursive calls continue until the correct position for the new node is found.

## 2. findMin Function

```
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

```
## Explanation:
Purpose: Finds the minimum value node in the BST.
## Steps:
1. The function starts at the root and keeps moving left (root = root->left) until it reaches the leftmost node, which is the smallest in a BST.
2. It returns the pointer to the minimum node.

This function is used in deletion operations when a node has two children and we need to find the inorder successor (the smallest node in the right subtree).

## 3. delNode Function
```
void delNode(Node*& root, int value) {
    if (root == nullptr) return; 

    if (value < root->value) {
        delNode(root->left, value); 
    } else if (value > root->value) {
        delNode(root->right, value); 
    } else {
        cout << "Deleted " << root->value << " from the tree." << endl;
        
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        } else {
            Node* temp = findMin(root->right);
            root->value = temp->value;
            delNode(root->right, temp->value);
        }
    }
}

```

<h2>Explanation of the `delNode` Function</h2>
<ul>
    <li><strong>Purpose:</strong> Deletes a node with the specified value from the BST.</li>
    <li><strong>Steps:</strong>
        <ul>
            <li><strong>Search for the node:</strong> The function first traverses the tree to find the node with the given value:
                <ul>
                    <li>If the value is less than the current node's value, the function is recursively called on the left subtree.</li>
                    <li>If the value is greater than the current node's value, the function is recursively called on the right subtree.</li>
                </ul>
            </li>
            <li><strong>Found the node:</strong> Once the node is found, there are three possible cases for deletion:
                <ul>
                    <li><strong>Leaf node (no children):</strong> The node is deleted directly by freeing memory, and the pointer is set to <code>nullptr</code>.</li>
                    <li><strong>One child:</strong> The node is replaced by its only child (either left or right), and the memory for the old node is freed.</li>
                    <li><strong>Two children:</strong> The node is replaced with its inorder successor (the smallest node in the right subtree). The inorder successor is then deleted recursively.</li>
                </ul>
            </li>
        </ul>
    </li>
    <li>This function handles all cases for node deletion in a BST.</li>
</ul>

## 4. inorder Function

```
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

```
<h2>Explanation of the `inorder` Function</h2>
<ul>
    <li><strong>Purpose:</strong> Performs an inorder traversal of the BST and prints the values of the nodes in ascending order.</li>
    <li><strong>Steps:</strong>
        <ul>
            <li><strong>Left subtree:</strong> The function first recursively visits the left child.</li>
            <li><strong>Root node:</strong> Then, it prints the value of the current node.</li>
            <li><strong>Right subtree:</strong> Finally, it recursively visits the right child.</li>
        </ul>
    </li>
    <li><strong>Additional Information:</strong> The recursion ensures that all nodes are visited in sorted order, which is the characteristic of an inorder traversal in a BST.</li>
</ul>

## main() Function
```
int main() {
    Node* root = nullptr;

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

    delNode(root, 60);
    delNode(root, 80);
    delNode(root, 50);

    cout << "\nInorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}

```

<h2>Explanation of the `main` Function</h2>
<ul>
    <li><strong>Purpose:</strong> This is the main function where the Binary Search Tree is created, and nodes are inserted and deleted.</li>
    <li><strong>Steps:</strong>
        <ul>
            <li><strong>Create an empty tree:</strong> <code>Node* root = nullptr;</code> initializes an empty tree.</li>
            <li><strong>Insert nodes:</strong> Several insert calls are made to add nodes to the tree with values 70, 60, 80, 50, 65, 75, and 90.</li>
            <li><strong>Inorder traversal after insertion:</strong> The <code>inorder</code> function is called to print the tree after the insertions, displaying the values in sorted order.</li>
            <li><strong>Delete nodes:</strong> The <code>delNode</code> function is called to delete nodes with values 60, 80, and 50.</li>
            <li><strong>Inorder traversal after deletion:</strong> The <code>inorder</code> function is called again to print the tree after the deletions, showing the updated sorted order.</li>
        </ul>
    </li>
</ul>