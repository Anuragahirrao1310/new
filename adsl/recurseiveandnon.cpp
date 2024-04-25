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

bool isOperand(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

Node* constructTree(string prefixExpression) {
    stack<Node*> st;

    for (int i = prefixExpression.length() - 1; i >= 0; i--) {
        char c = prefixExpression[i];

        if (isOperand(c)) {
            st.push(new Node(c));
        } else {
            Node* operand1 = st.top();
            st.pop();
            Node* operand2 = st.top();
            st.pop();

            Node* newNode = new Node(c);
            newNode->left = operand1;
            newNode->right = operand2;

            st.push(newNode);
        }
    }

    return st.top();
}

void recursivePreorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        recursivePreorder(root->left);
        recursivePreorder(root->right);
    }
}

void iterativePreorder(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* current = st.top();
        st.pop();

        cout << current->data << " ";

        if (current->right != nullptr)
            st.push(current->right);

        if (current->left != nullptr)
            st.push(current->left);
    }
}

void recursiveInorder(Node* root) {
    if (root != nullptr) {
        recursiveInorder(root->left);
        cout << root->data << " ";
        recursiveInorder(root->right);
    }
}

void iterativeInorder(Node* root) {
    stack<Node*> st;

    while (root != nullptr || !st.empty()) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();

        cout << root->data << " ";

        root = root->right;
    }
}

void recursivePostorder(Node* root) {
    if (root != nullptr) {
        recursivePostorder(root->left);
        recursivePostorder(root->right);
        cout << root->data << " ";
    }
}

void iterativePostorder(Node* root) {
    stack<Node*> st;
    stack<char> output;

    st.push(root);

    while (!st.empty()) {
        Node* current = st.top();
        st.pop();

        output.push(current->data);

        if (current->left != nullptr)
            st.push(current->left);

        if (current->right != nullptr)
            st.push(current->right);
    }

    while (!output.empty()) {
        cout << output.top() << " ";
        output.pop();
    }
}

int main() {
    string prefixExpression;
    cout << "Enter a prefix expression: ";
    getline(cin, prefixExpression);

    Node* root = constructTree(prefixExpression);

    cout << "\nRecursive Preorder Traversal: ";
    recursivePreorder(root);

    cout << "\nNon-Recursive Preorder Traversal: ";
    iterativePreorder(root);

    cout << "\nRecursive Inorder Traversal: ";
    recursiveInorder(root);

    cout << "\nNon-Recursive Inorder Traversal: ";
    iterativeInorder(root);

    cout << "\nRecursive Postorder Traversal: ";
    recursivePostorder(root);

    cout << "\nNon-Recursive Postorder Traversal: ";
    iterativePostorder(root);

    return 0;
}
