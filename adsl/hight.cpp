#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int key) : val(key), left(nullptr), right(nullptr) {}
};

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
}

void printLeafNodes(Node* root) {
    if (root != nullptr) {
        if (root->left == nullptr && root->right == nullptr) {
            cout << root->val << " ";
        } else {
            printLeafNodes(root->left);
            printLeafNodes(root->right);
        }
    }
}

void mirrorTree(Node* root) {
    if (root != nullptr) {
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
    }
}

void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            Node* current = q.front();
            q.pop();

            cout << current->val << " ";

            if (current->left) {
                q.push(current->left);
            }

            if (current->right) {
                q.push(current->right);
            }
        }

        cout << endl;
    }
}

int main() {
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Height of the tree: " << height(root) << endl;

    cout << "Leaf nodes: ";
    printLeafNodes(root);
    cout << endl;

    cout << "Original tree (level-wise): " << endl;
    levelOrderTraversal(root);
    cout << endl;

    mirrorTree(root);

    cout << "Mirror image (level-wise): " << endl;
    levelOrderTraversal(root);
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
