#include <iostream>
#include <stack>
#include <string>

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    return (c == '+' || c == '-') ? 1 : (c == '*' || c == '/') ? 2 : 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operatorStack;
    std::string postfix = "";

    for (char c : infix) {
        if (std::isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); 
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int evaluatePostfix(const std::string& postfix) {
    std::stack<int> operandStack;

    for (char c : postfix) {
        if (std::isdigit(c)) {
            operandStack.push(c - '0');
        } else if (isOperator(c)) {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = (c == '+') ? operand1 + operand2 : (c == '-') ? operand1 - operand2
                        : (c == '*') ? operand1 * operand2 : operand1 / operand2;
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int main() {
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::cin >> infixExpression;

    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << "Postfix expression: " << postfixExpression << std::endl;

    int result = evaluatePostfix(postfixExpression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
