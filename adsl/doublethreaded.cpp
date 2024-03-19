#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    bool isThreaded;

    Node(int value) : key(value), left(nullptr), right(nullptr), isThreaded(false) {}
};

class ThreadedBST {
private:
    Node* root;

    Node* insertUtil(Node* root, int key) {
        if (!root)
            return new Node(key);

        if (key < root->key) {
            root->left = insertUtil(root->left, key);
            root->left->right = root;
            root->left->isThreaded = true;
        } else if (key > root->key) {
            root->right = insertUtil(root->right, key);
        }

        return root;
    }

    void threadedInorderUtil(Node* root) {
        Node* current = root;

        while (current) {
            while (current->left)
                current = current->left;

            std::cout << current->key << " ";

            if (current->isThreaded)
                current = current->right;
            else
                break;
        }
    }

    void inorderUtil(Node* root) {
        if (root) {
            inorderUtil(root->left);
            std::cout << root->key << " ";
            inorderUtil(root->right);
        }
    }

public:
    ThreadedBST() : root(nullptr) {}

    void insert(int key) {
        root = insertUtil(root, key);
    }

    void threadedInorder() {
        threadedInorderUtil(root);
        std::cout << std::endl;
    }

    void inorder() {
        inorderUtil(root);
        std::cout << std::endl;
    }
};

int main() {
    ThreadedBST threadedBST;

    threadedBST.insert(4);
    threadedBST.insert(2);
    threadedBST.insert(6);
    threadedBST.insert(1);
    threadedBST.insert(3);
    threadedBST.insert(5);
    threadedBST.insert(7);

    cout << "Threaded Inorder Traversal: ";
    threadedBST.threaded

}
