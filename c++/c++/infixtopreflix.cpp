#include <iostream>
#include <stack>
#include <string>

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    return (c == '+' || c == '-') ? 1 : (c == '*' || c == '/') ? 2 : 0;
}

std::string infixToPrefix(const std::string& infix) {
    std::string prefix = "";
    std::stack<char> operators;

    for (int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];

        if (isalnum(c)) {
            prefix = c + prefix;  
        } else if (c == ')') {
            operators.push(c);  
        } else if (c == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefix = operators.top() + prefix;
                operators.pop();
            }
            operators.pop(); 
        } else {  
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                prefix = operators.top() + prefix;
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        prefix = operators.top() + prefix;
        operators.pop();
    }

    return prefix;
}

int main() {
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::cin >> infixExpression;

    std::string prefixExpression = infixToPrefix(infixExpression);

    std::cout << "Prefix expression: " << prefixExpression << std::endl;

    return 0;
}
