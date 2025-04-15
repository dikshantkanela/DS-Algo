#include <bits/stdc++.h>
using namespace std;

// Function to check for redundant brackets in a valid expression
bool findRedundantBrackets(string &s)
{
    stack<char> st;
   
    for(char ch : s){
        if(ch != ')'){
            st.push(ch); // Push everything except closing brackets
        }
        else{
            bool redundant = true; // Ensures it resets to true for every other ')'
            
            // Pop until matching '('
            while(!st.empty() && st.top() != '('){
                char poppedElement = st.top();
                if(poppedElement == '+' || poppedElement == '-' || poppedElement == '*' || poppedElement == '/'){
                    redundant = false; // Found an operator inside → not redundant
                }
                st.pop();
            }

            // Pop the opening bracket '('
            st.pop();

            if(redundant == true){
                return true; // Redundant brackets found
            }
        }
    }
    return false; // No redundant brackets found
}

int main() {
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    if(findRedundantBrackets(expression)) {
        cout << "Redundant brackets found ✅" << endl;
    } else {
        cout << "No redundant brackets 🚫" << endl;
    }

    return 0;
}
