#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Node* constructTreeFromPrefix(const string& prefix, int& pos) {
    if (pos < 0) return nullptr;

    char c = prefix[pos--];
    Node* newNode = new Node(c);

    if (isOperator(c)) {
        newNode->right = constructTreeFromPrefix(prefix, pos);
        newNode->left = constructTreeFromPrefix(prefix, pos);
    }

    return newNode;
}

void recursivePreorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    recursivePreorder(root->left);
    recursivePreorder(root->right);
}

void nonRecursivePreorder(Node* root) {
    if (!root) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";

        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
}

void recursiveInorder(Node* root) {
    if (!root) return;
    recursiveInorder(root->left);
    cout << root->data << " ";
    recursiveInorder(root->right);
}

void nonRecursiveInorder(Node* root) {
    if (!root) return;

    stack<Node*> s;
    Node* current = root;

    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";

        current = current->right;
    }
}

void recursivePostorder(Node* root) {
    if (!root) return;
    recursivePostorder(root->left);
    recursivePostorder(root->right);
    cout << root->data << " ";
}

void nonRecursivePostorder(Node* root) {
    if (!root) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left) s1.push(current->left);
        if (current->right) s1.push(current->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {
    string prefix;
    int choice;

    cout << "Enter the prefix expression (e.g., *+ab+cd): ";
    cin >> prefix;

    if (prefix.size() <= 1) {
        cout << "Invalid prefix expression. Please enter a valid prefix expression.\n";
        return 1;
    }

    Node* root = nullptr;
    int pos = prefix.size() - 1;
    root = constructTreeFromPrefix(prefix, pos);

    cout << "Choose the traversal method:\n";
    cout << "1. Recursive\n";
    cout << "2. Non-recursive\n";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Recursive Pre-order traversal: ";
            recursivePreorder(root);
            cout << "\nRecursive In-order traversal: ";
            recursiveInorder(root);
            cout << "\nRecursive Post-order traversal: ";
            recursivePostorder(root);
            cout << endl;
            break;
        case 2:
            cout << "Non-recursive Pre-order traversal: ";
            nonRecursivePreorder(root);
            cout << "\nNon-recursive In-order traversal: ";
            nonRecursiveInorder(root);
            cout << "\nNon-recursive Post-order traversal: ";
            nonRecursivePostorder(root);
            cout << endl;
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }

    return 0;
}