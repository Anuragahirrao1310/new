#include <iostream>
#include <cstring>

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
private:
    char data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char item) {
        if (top < MAX_SIZE - 1) {
            data[++top] = item;
        } else {
            std::cout << "Stack is full. Cannot push " << item << std::endl;
        }
    }

    char pop() {
        if (top >= 0) {
            return data[top--];
        } else {
            std::cout << "Stack is empty." << std::endl;
            return '\0';
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack charStack;
    char name[MAX_SIZE];

    std::cout << "Enter a name: ";
    std::cin.getline(name, MAX_SIZE);

    int len = std::strlen(name);

    // Push each character of the name onto the stack
    for (int i = 0; i < len; i++) {
        charStack.push(name[i]);
    }

    std::cout << "Reversed name: ";

    // Pop and print each character from the stack
    while (!charStack.isEmpty()) {
        std::cout << charStack.pop();
    }

    std::cout << std::endl;

    return 0;
}
