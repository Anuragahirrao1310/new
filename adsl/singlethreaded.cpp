#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded;

    Node(int val) : data(val), left(nullptr), right(nullptr), isThreaded(false) {}
};

Node* insert(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

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
        while (root->left && !root->isThreaded) {
            root = root->left;
        }

        cout << root->data << " ";

        if (root->isThreaded) {
            root = root->right;
        } else {
            root = root->right;
        }
    }
}
int main() {
    Node* root = nullptr;

    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

    Node* prev = nullptr;
    createThreadedBST(root, prev);

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;
    return 0;
}
