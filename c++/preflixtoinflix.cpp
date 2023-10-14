#include <iostream>
#include <stack>
#include <string>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

std::string prefixToInfix(const std::string& prefix) {
    std::stack<std::string> stack;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperand(c)) {
            stack.push(std::string(1, c));
        } else if (isOperator(c)) {
            std::string operand1, operand2;
            if (!stack.empty()) {
                operand1 = stack.top();
                stack.pop();
            }
            if (!stack.empty()) {
                operand2 = stack.top();
                stack.pop();
            }

            std::string infixExpression = "(" + operand1 + c + operand2 + ")";
            stack.push(infixExpression);
        }
    }

    if (!stack.empty()) {
        return stack.top();
    } else {
        return "Invalid prefix expression";
    }
}

int main() {
    std::string prefixExpression;
    std::cout << "Enter a prefix expression: ";
    std::cin >> prefixExpression;

    std::string infixExpression = prefixToInfix(prefixExpression);

    std::cout << "Infix expression: " << infixExpression << std::endl;

    return 0;
}