#include<bits/stdc++.h>
using namespace std;

/**
 * Function to check if a string of brackets is valid.
 * Valid brackets must be closed in the correct order:
 * - '(' must be closed by ')'
 * - '[' must be closed by ']'
 * - '{' must be closed by '}'
 * 
 * @param s String containing parentheses characters
 * @return true if the string is valid, false otherwise
 */

    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }

            else if (ch == ')' || ch == ']' || ch == '}') {
                if (!st.empty()) {
                    int top = st.top();
                    if ((top == '(' && ch == ')' || top == '{' && ch == '}' ||
                         top == '[' && ch == ']')) {
                        st.pop();

                    } else {
                        return false;
                    }

                } else {
                    return false;
                }
            }
        }
        if (st.size() > 0) {
            return false;
        } else {

            return true;
        }
    }

int main() {
    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";
    string test6 = ""; // Empty string
    string test7 = "(("; // Unclosed brackets
    
    cout << "Test 1 '" << test1 << "': " << (isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2 '" << test2 << "': " << (isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3 '" << test3 << "': " << (isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test 4 '" << test4 << "': " << (isValid(test4) ? "Valid" : "Invalid") << endl;
    cout << "Test 5 '" << test5 << "': " << (isValid(test5) ? "Valid" : "Invalid") << endl;
    cout << "Test 6 '" << test6 << "': " << (isValid(test6) ? "Valid" : "Invalid") << endl;
    cout << "Test 7 '" << test7 << "': " << (isValid(test7) ? "Valid" : "Invalid") << endl;
    
    // Interactive testing
    string input;
    cout << "\nEnter a string of brackets to test (or 'exit' to quit): ";
    while (getline(cin, input) && input != "exit") {
        cout << "'" << input << "' is " << (isValid(input) ? "Valid" : "Invalid") << endl;
        cout << "Enter another string (or 'exit' to quit): ";
    }
    
    return 0;
}