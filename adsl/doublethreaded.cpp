#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node* next;  // Threaded pointer
    bool leftThreaded;
    bool rightThreaded;

    Node(char value) : data(value), left(nullptr), right(nullptr), next(nullptr), leftThreaded(false), rightThreaded(false) {}
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Node* constructThreadedBSTFromPrefix(string prefix) {
    stack<Node*> s;
    int length = prefix.size();

    for (int i = length - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperator(c)) {
            Node* newNode = new Node(c);
            newNode->left = s.top();
            newNode->leftThreaded = true;
            s.pop();
            newNode->right = s.top();
            newNode->rightThreaded = true;
            s.pop();
            s.push(newNode);
        } else {
            Node* newNode = new Node(c);
            s.push(newNode);
        }
    }

    Node* root = s.top();
    root->leftThreaded = true;  // Additional threading for the leftmost node
    root->rightThreaded = true;  // Additional threading for the rightmost node

    return root;
}

// Function to perform in-order traversal using threaded pointers
void threadedInorderTraversal(Node* root) {
    Node* current = root;

    while (current && !current->leftThreaded) {
        current = current->left;
    }

    while (current) {
        cout << current->data << " ";

        if (current->rightThreaded) {
            current = current->right;
        } else {
            current = current->next;
        }
    }
}

int main() {
    string prefix = "*+ab+cd";
    Node* root = constructThreadedBSTFromPrefix(prefix);
    cout << "In-order traversal (using threaded pointers): ";
    threadedInorderTraversal(root);
    cout << endl;

    return 0;
}
