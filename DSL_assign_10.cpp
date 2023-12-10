#include <iostream>
#include <cstring>
using namespace std;

bool Operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

//SETTING PRECEDENCE
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

//CONVERTING INFIX TO POSTFIX
string infixToPostfix(string infix) {
    string postfix = "";
    int size_of_stack = 0;
    char stack_operators[infix.length()];

    for (char c : infix) {
        if (c == ' ') {
            continue;
        }
        else if (isalnum(c)) {
            postfix += c; 
        }
        else if (Operator(c)) {
            while (size_of_stack> 0 && stack_operators[size_of_stack-1]!= '(' &&
                   precedence(c)<=precedence(stack_operators[size_of_stack- 1]))
            {
                postfix += stack_operators[size_of_stack - 1];
                size_of_stack--;
            }
            stack_operators[size_of_stack++] = c; 
        }
        else if (c == '(') {
            stack_operators[size_of_stack++] = c;
        }
        else if (c == ')') {
            while (size_of_stack> 0 && stack_operators[size_of_stack - 1] != '(') {
                postfix += stack_operators[size_of_stack - 1];
                size_of_stack--;
            }
            if (size_of_stack > 0 && stack_operators[size_of_stack - 1] == '(') {
                size_of_stack--;
            }
        }
    }

    while (size_of_stack > 0) {
        postfix += stack_operators[size_of_stack - 1];
        size_of_stack--;
    }

    return postfix;
}


int main() {
    while(true){
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix <<endl;
    }

    return 0;
}
