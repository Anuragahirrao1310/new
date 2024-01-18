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

Node* constructTreeFromPrefix(string prefix) {
    stack<Node*> s;
    int length = prefix.size();

    for (int i = length - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperator(c)) {
            Node* newNode = new Node(c);
            newNode->left = s.top();
            s.pop();
            newNode->right = s.top();
            s.pop();
            s.push(newNode);
        } else {
            Node* newNode = new Node(c);
            s.push(newNode);
        }
    }

    return s.top();
}

void preorderTraversal(Node* root) {
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

void inorderTraversal(Node* root) {
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

void postorderTraversal(Node* root) {
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
    string prefix = "*+ab+cd";
    Node* root = constructTreeFromPrefix(prefix);
    cout<<"Expressions in non recursive :"<<endl;

    cout << "Pre-order traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "In-order traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
