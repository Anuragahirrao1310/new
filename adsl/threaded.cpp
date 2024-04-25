#include <iostream>

class ThreadedBSTNode {
public:
    int data;
    ThreadedBSTNode* left;
    ThreadedBSTNode* right;
    bool rightThread;

    ThreadedBSTNode(int value) : data(value), left(nullptr), right(nullptr), rightThread(false) {}
};

class ThreadedBST {
private:
    ThreadedBSTNode* root;

public:
    ThreadedBST() : root(nullptr) {}

    void insert(int value) {
        root = insertHelper(root, value);
    }

    void inorderTraversal() {
        ThreadedBSTNode* current = leftmostNode(root);

        while (current != nullptr) {
            std::cout << current->data << " ";
            if (current->rightThread)
                current = current->right;
            else
                current = leftmostNode(current->right);
        }

        std::cout << std::endl;
    }

private:
    ThreadedBSTNode* insertHelper(ThreadedBSTNode* node, int value) {
        if (node == nullptr)
            return new ThreadedBSTNode(value);

        if (value < node->data) {
            node->left = insertHelper(node->left, value);
            if (node->left->right == nullptr) {
                node->left->right = node;
                node->left->rightThread = true;
            }
        } else {
            node->right = insertHelper(node->right, value);
            if (node->right == nullptr) {
                ThreadedBSTNode* temp = new ThreadedBSTNode(value);
                temp->right = node->right;
                temp->rightThread = true;
                node->right = temp;
            }
        }

        return node;
    }

    ThreadedBSTNode* leftmostNode(ThreadedBSTNode* node) {
        if (node == nullptr)
            return nullptr;

        while (node->left != nullptr)
            node = node->left;

        return node;
    }
};

int main() {
    ThreadedBST threadedBST;

    threadedBST.insert(5);
    threadedBST.insert(3);
    threadedBST.insert(7);
    threadedBST.insert(2);
    threadedBST.insert(4);
    threadedBST.insert(6);
    threadedBST.insert(8);

    std::cout << "Inorder Traversal: ";
    threadedBST.inorderTraversal();

    return 0;
}
