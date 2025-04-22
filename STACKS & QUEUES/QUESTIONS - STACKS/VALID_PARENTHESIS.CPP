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

    for(int i = 0; i < s.length(); i++) {
        // If we encounter an opening bracket, push it onto the stack
        if(s[i] == '[' || s[i] == '(' || s[i] == '{') {
            st.push(s[i]);
        }
        // If we encounter a closing bracket
        else if(s[i] == ']' || s[i] == '}' || s[i] == ')') {
            // Check if stack is empty (no matching opening bracket)
            if(st.empty()) {
                return false;
            }
            
            char top = st.top();
            
            // Check if the brackets match
            if((s[i] == ']' && top != '[') || 
               (s[i] == '}' && top != '{') || 
               (s[i] == ')' && top != '(')) {
                return false;
            }
            else {
                // If brackets match, remove the opening bracket
                st.pop();
            }
        }
    }
    
    // If stack is empty, all brackets were properly closed
    return st.empty();
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