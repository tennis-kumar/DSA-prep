#include <iostream>
#include <stack>
#include <string>
using namespace std;


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    // using for each loop
    for (char ch : infix) {
        if (isalnum(ch)) { // If operand, add to postfix
            postfix += ch;
        } else if (ch == '(') { // If '(', push to stack
            st.push(ch);
        } else if (ch == ')') { // If ')', pop and add until '(' is found
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        } else { // If operator
            while (!st.empty() && precedence(ch) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}




int main() {
    string infix = "(a+b*c)/(d+e)";
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}