//Write a c++ program to create a Binary Search Tree and include following operations in tree:
/*(a) Insertion (Recursive and Iterative Implementation)
(b) Deletion by copying
(c) Deletion by Merging
(d) Search a no. in BST
(e) Display its preorder, postorder and inorder traversals Recursively
(f) Display its preorder, postorder and inorder traversals Iteratively
(g) Display its level-by-level traversals
(h) Count the non-leaf nodes and leaf nodes
(i) Display height of tree
(j) Create a mirror image of tree
(k) C */



#include <iostream>
#include <queue>
#include <stack>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

// Function to insert a value into the BST (Recursive)
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

// Function to insert a value into the BST (Iterative)
    void insertIterative(int value) {
        TreeNode* newNode = new TreeNode(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        TreeNode* current = root;
        TreeNode* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            } else if (value > current->data) {
                current = current->right;
            } else {
                // Duplicate value, decide what to do
                delete newNode;
                return;
            }
        }

        if (value < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

 // Function to delete a node by copying
    TreeNode* deleteByCopying(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->data) {
            root->left = deleteByCopying(root->left, key);
        } else if (key > root->data) {
            root->right = deleteByCopying(root->right, key);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor
            TreeNode* temp = findMin(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteByCopying(root->right, temp->data);
        }

        return root;
    }

// Function to delete a node by merging
    TreeNode* deleteByMerging(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->data) {
            root->left = deleteByMerging(root->left, key);
        } else if (key > root->data) {
            root->right = deleteByMerging(root->right, key);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Merge the subtrees
            TreeNode* temp = findMax(root->left);

            // Copy the inorder predecessor's data to this node
            root->data = temp->data;

            // Delete the inorder predecessor
            root->left = deleteByMerging(root->left, temp->data);
        }

        return root;
    }

// Function to find the node with the minimum value in a BST
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Function to find the node with the maximum value in a BST
    TreeNode* findMax(TreeNode* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

 // Function to search for a value in the BST
    bool search(int key) {
        return search(root, key);
    }

// Function to search for a value in the BST (Helper Function)
    bool search(TreeNode* node, int key) {
        if (node == nullptr) {
            return false;
        }

        if (key == node->data) {
            return true;
        } else if (key < node->data) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

// Function to display preorder traversal recursively
    void preorderTraversalRecursive(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorderTraversalRecursive(node->left);
            preorderTraversalRecursive(node->right);
        }
    }

// Function to display inorder traversal recursively
    void inorderTraversalRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            std::cout << node->data << " ";
            inorderTraversalRecursive(node->right);
        }
    }

 // Function to display postorder traversal recursively
    void postorderTraversalRecursive(TreeNode* node) {
        if (node != nullptr) {
            postorderTraversalRecursive(node->left);
            postorderTraversalRecursive(node->right);
            std::cout << node->data << " ";
        }
    }

// Function to display preorder traversal iteratively
    void preorderTraversalIterative() {
        if (root == nullptr) {
            return;
        }

        std::stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* current = st.top();
            st.pop();

            std::cout << current->data << " ";

            if (current->right != nullptr) {
                st.push(current->right);
            }
            if (current->left != nullptr) {
                st.push(current->left);
            }
        }
    }

// Function to display inorder traversal iteratively
    void inorderTraversalIterative() {
        if (root == nullptr) {
            return;
        }

        std::stack<TreeNode*> st;
        TreeNode* current = root;

        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();

            std::cout << current->data << " ";

            current = current->right;
        }
    }

 // Function to display postorder traversal iteratively
    void postorderTraversalIterative() {
        if (root == nullptr) {
            return;
        }

        std::stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* current = st1.top();
            st1.pop();
            st2.push(current);

            if (current->left != nullptr) {
                st1.push(current->left);
            }
            if (current->right != nullptr) {
                st1.push(current->right);
            }
        }

        while (!st2.empty()) {
            std::cout << st2.top()->data << " ";
            st2.pop();
        }
    }

 // Function to display level-by-level traversal
    void levelOrderTraversal() {
        if (root == nullptr) {
            return;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            std::cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

// Function to count non-leaf nodes and leaf nodes
    void countNodes(TreeNode* node, int& nonLeafCount, int& leafCount) {
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr || node->right != nullptr) {
            nonLeafCount++;
        } else {
            leafCount++;
        }

        countNodes(node->left, nonLeafCount, leafCount);
        countNodes(node->right, nonLeafCount, leafCount);
    }

// Function to display the height of the tree
    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return 1 + std::max(leftHeight, rightHeight);
    }

// Function to create a mirror image of the tree
    void createMirror(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        // Swap left and right subtrees
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        // Recursively create mirror images for left and right subtrees
        createMirror(node->left);
        createMirror(node->right);
      }

 // Function to get the root of the tree
    TreeNode* getRoot() const {
        return root;
    }
  };

int main() {
    BinarySearchTree bst;

    // Insertion examples
    bst.insertRecursive(50);
    bst.insertRecursive(30);
    bst.insertRecursive(70);
    bst.insertIterative(20);
    bst.insertIterative(40);
    bst.insertIterative(60);
    bst.insertIterative(80);

    // Displaying inorder traversal
    std::cout << "Inorder Traversal (Recursive): ";
    bst.inorderTraversalRecursive(bst.getRoot());
    std::cout << std::endl;

    // Displaying level-by-level traversal
    std::cout << "Level Order Traversal: ";
    bst.levelOrderTraversal();
    std::cout << std::endl;

    // Deletion examples
    int keyToDelete = 30;
    bst.deleteByCopying(bst.getRoot(), keyToDelete);
    std::cout << "Inorder Traversal after deletion of " << keyToDelete << ": ";
    bst.inorderTraversalRecursive(bst.getRoot());
    std::cout << std::endl;

    keyToDelete = 60;
    bst.deleteByMerging(bst.getRoot(), keyToDelete);
    std::cout << "Inorder Traversal after deletion of " << keyToDelete << ": ";
    bst.inorderTraversalRecursive(bst.getRoot());
    std::cout << std::endl;

    // Other operations can be performed similarly

    return 0;
}
