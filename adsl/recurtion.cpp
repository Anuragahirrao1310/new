#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* newNode(char data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void constructTree(string prefix, Node** root) {
    stack<Node*> st;

    for (int i = prefix.size() - 1; i >= 0; --i) {
        if (!isOperator(prefix[i])) {
            *root = newNode(prefix[i]);
            st.push(*root);
        } else {
            *root = newNode(prefix[i]);
            (*root)->left = st.top();
            st.pop();
            (*root)->right = st.top();
            st.pop();
            st.push(*root);
        }
    }
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    string prefix = "*+ab+cd";
    Node* root = nullptr;
    
    constructTree(prefix, &root);

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}
