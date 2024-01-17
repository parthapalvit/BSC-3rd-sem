/* Write a program to create a Threaded Binary Tree as per inorder traversal, and 
implement operations like finding the successor / predecessor of an element, insert an 
element, inorder traversal. */

#include <iostream>

using namespace std;

// Node structure for threaded binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded; // true if right pointer is threaded, false otherwise

    Node(int value) : data(value), left(nullptr), right(nullptr), isThreaded(false) {}
};

class ThreadedBinaryTree {
private:
    Node* root;

    // Helper function to perform inorder traversal
    void inorderTraversalHelper(Node* root) {
        Node* current = findLeftmostNode(root);

        while (current != nullptr) {
            cout << current->data << " ";

            if (!current->isThreaded) {
                current = current->right;
            } else {
                current = findLeftmostNode(current->right);
            }
        }
    }

    // Helper function to find the leftmost node in the tree
    Node* findLeftmostNode(Node* node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to find the inorder successor of a given node
    Node* findSuccessorHelper(Node* target) {
        if (target->right != nullptr) {
            return findLeftmostNode(target->right);
        }

        Node* successor = nullptr;
        Node* current = root;

        while (current != nullptr) {
            if (current->data > target->data) {
                successor = current;
                current = current->left;
            } else if (current->data < target->data) {
                current = current->right;
            } else {
                break; // Found the target node
            }
        }

        return successor;
    }

public:
    ThreadedBinaryTree() : root(nullptr) {}

    // Function to insert a new element into the threaded binary tree
    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = new Node(value);
                    current->isThreaded = true;
                    current->left->right = current;
                    break;
                }
                current = current->left;
            } else {
                if (!current->isThreaded) {
                    current = current->right;
                } else {
                    Node* newNode = new Node(value);
                    newNode->right = current->right;
                    current->right = newNode;
                    current->isThreaded = false;
                    newNode->isThreaded = true;
                    break;
                }
            }
        }
    }

    // Function to perform inorder traversal
    void inorderTraversal() {
        cout << "Inorder Traversal: ";
        inorderTraversalHelper(root);
        cout << endl;
    }

    // Function to find the successor of a given element
    void findSuccessor(int value) {
        Node* target = root;
        while (target != nullptr && target->data != value) {
            if (value < target->data) {
                target = target->left;
            } else {
                target = target->right;
            }
        }

        if (target == nullptr) {
            cout << "Element not found in the tree." << endl;
        } else {
            Node* successor = findSuccessorHelper(target);
            if (successor != nullptr) {
                cout << "Successor of " << value << " is: " << successor->data << endl;
            } else {
                cout << "No successor found." << endl;
            }
        }
    }
};

int main() {
    ThreadedBinaryTree threadedTree;

    // Insert elements into the threaded binary tree
    threadedTree.insert(50);
    threadedTree.insert(30);
    threadedTree.insert(70);
    threadedTree.insert(20);
    threadedTree.insert(40);
    threadedTree.insert(60);
    threadedTree.insert(80);

    // Perform inorder traversal
    threadedTree.inorderTraversal();

    // Find the successor of an element
    threadedTree.findSuccessor(30);
    threadedTree.findSuccessor(60);
    threadedTree.findSuccessor(80);

    return 0;
}
