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

    Node* insertUtil(Node* root, int key) {
        if (!root)
            return new Node(key);

        if (key < root->key)
            root->left = insertUtil(root->left, key);
        else if (key > root->key)
            root->right = insertUtil(root->right, key);

        return root;
    }

    void threadedInorderUtil(Node* root) {
       Node* current = root;

    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->key << " ";

        current = current->right;
    }
    }

public:
    SingleThreadedBST() : root(nullptr) {}

    void insert(int key) {
        root = insertUtil(root, key);
    }

    void threadedInorder() {
        threadedInorderUtil(root);
        std::cout << std::endl;
    }
};

int main() {
    SingleThreadedBST singleThreadedBST;

    singleThreadedBST.insert(4);
    singleThreadedBST.insert(2);
    singleThreadedBST.insert(6);
    singleThreadedBST.insert(1);
    singleThreadedBST.insert(3);
    singleThreadedBST.insert(5);
    singleThreadedBST.insert(7);

    std::cout << "Threaded Inorder Traversal: ";
    singleThreadedBST.threadedInorder();

    return 0;
}
