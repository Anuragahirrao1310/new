#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class SingleThreadedBST {
private:
    Node* root;

    // Helper function for insertion
    Node* insertUtil(Node* root, int key) {
        if (!root)
            return new Node(key);

        if (key < root->key)
            root->left = insertUtil(root->left, key);
        else if (key > root->key)
            root->right = insertUtil(root->right, key);

        return root;
    }

    // Helper function for threaded inorder traversal
    void threadedInorderUtil(Node* root) {
        Node* current = root;

        while (current) {
            while (current->left)
                current = current->left;

            std::cout << current->key << " ";

            if (current->right)
                current = current->right;
            else
                break;
        }
    }

public:
    SingleThreadedBST() : root(nullptr) {}

    // Public function to insert a key
    void insert(int key) {
        root = insertUtil(root, key);
    }

    // Public function to perform threaded inorder traversal
    void threadedInorder() {
        threadedInorderUtil(root);
        std::cout << std::endl;
    }
};

int main() {
    SingleThreadedBST singleThreadedBST;

    // Insert keys into the single-threaded BST
    singleThreadedBST.insert(4);
    singleThreadedBST.insert(2);
    singleThreadedBST.insert(6);
    singleThreadedBST.insert(1);
    singleThreadedBST.insert(3);
    singleThreadedBST.insert(5);
    singleThreadedBST.insert(7);

    // Perform threaded inorder traversal
    std::cout << "Threaded Inorder Traversal: ";
    singleThreadedBST.threadedInorder();

    return 0;
}
