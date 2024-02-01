#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded;

    Node(int val) : data(val), left(nullptr), right(nullptr), isThreaded(false) {}
};

void createThreadedBST(Node* root, Node*& prev) {
    if (!root) {
        return;
    }

    createThreadedBST(root->left, prev);

    if (!root->left) {
        root->isThreaded = true;
        root->left = prev;
    }

    prev = root;

    createThreadedBST(root->right, prev);
}

void inOrderTraversal(Node* root) {
    while (root) {
        while (root->left) {
            root = root->left;
        }

        cout << root->data << " ";

        if (root->isThreaded) {
            root = root->right;
        } else {
            root = root->right;
            while (root && !root->isThreaded) {
                root = root->left;
            }
        }
    }
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Node* prev = nullptr;
    createThreadedBST(root, prev);
    cout << "In-order traversal of the threaded BST: ";
    inOrderTraversal(root);
    cout << endl;    
    return 0;
}
