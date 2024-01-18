#include <iostream>
using namespace std;

const int MAX = 100;

class Stack {
private:
    int a[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        a[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(20);
    s.push(10);

    // Display the elements in the stack
    s.display();

    return 0;
}
