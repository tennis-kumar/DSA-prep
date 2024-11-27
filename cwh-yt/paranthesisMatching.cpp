#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if the given characters form a matching pair
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Function to validate if an expression has balanced brackets
bool isBalanced(const string& expression) {
    stack<char> st;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            // Push opening brackets onto the stack
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            // Check if the stack is empty or top doesn't match
            if (st.empty() || !isMatchingPair(st.top(), ch)) {
                return false; // Unbalanced
            }
            st.pop(); // Pop the matching opening bracket
        }
        // Ignore non-bracket characters (if any)
    }

    // If the stack is empty, the expression is balanced
    return st.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    // if (isBalanced(expression)) {
    //     cout << "The expression is balanced." << endl;
    // } else {
    //     cout << "The expression is not balanced." << endl;
    // }

    // alternative approach using ternary/short-hand operator
    (isBalanced(expression)) ? cout << "The expression is balanced." << endl:cout << "The expression is not balanced." << endl; 
    

    return 0;
}
