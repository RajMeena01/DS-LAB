#include <iostream>
#include <stack>
#include <string>
using namespace std;
int evaluatePostfix(string expression) {
    stack<int> stk;
    for (char c : expression) {
        if (isdigit(c)) {
            stk.push(c - '0');
        } 
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = stk.top();
            stk.pop();
            int operand1 = stk.top();
            stk.pop();
            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            stk.push(result);
        }
    }
    return stk.top();
}
int main() {
    string postfix = "8 8 / 2 3 * + 5 1 * -";
    int result = evaluatePostfix(postfix);
    cout << "Result of the postfix expression: " << result << endl;
    return 0;
}