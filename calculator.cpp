#include "calculator.h"
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <map>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Division by zero!");
    }
    return a / b;
}

int factorial(int n) {
    if (n < 0) {
        throw runtime_error("Factorial of negative number not defined!");
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a * b) / gcd(a, b);
}

int generateRandom(int min, int max) {
    return min + rand() % (max - min + 1);
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : throw runtime_error("Division by zero");
        default: throw runtime_error("Invalid operator");
    }
}

double evaluateExpression(const string &expression) {
    stack<double> values;
    stack<char> ops;

    for (size_t i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue;
        
        if (isdigit(expression[i])) {
            double val = 0;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    double fraction = 0.1;
                    i++;
                    while (i < expression.length() && isdigit(expression[i])) {
                        val += (expression[i] - '0') * fraction;
                        fraction *= 0.1;
                        i++;
                    }
                    i--; // Adjust for loop increment
                } else {
                    val = val * 10 + (expression[i] - '0');
                }
                i++;
            }
            i--;
            values.push(val);
        } else if (expression[i] == '(') {
            ops.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            ops.pop(); // Remove '('
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            ops.push(expression[i]);
        }
    }

    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}
