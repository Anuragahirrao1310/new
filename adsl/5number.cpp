#include<iostream>
#include<cstdlib>


class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (!root) {
        return new TreeNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

int height(TreeNode* node) {
    if (!node) {
        return 0;
    }

    return std::max(height(node->left), height(node->right)) + 1;
}

bool isBalanced(TreeNode* root) {
    if (!root) {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return std::abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    int num;
    TreeNode* bstRoot = nullptr;

    std::cout << "Enter at least 5 numbers separated by space: ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> num;
        bstRoot = insert(bstRoot, num);
    }

    if (isBalanced(bstRoot)) {
        std::cout << "The constructed binary search tree is height balanced." << std::endl;
    } else {
        std::cout << "The constructed binary search tree is not height balanced." << std::endl;
    }

    return 0;
}
