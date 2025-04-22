#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of reversals to balance the expression
int findMinimumCost(string str) {
    // If length is odd, it's impossible to balance
    if (str.length() % 2 != 0) {
        return -1;
    }

    stack<char> st;

    // Process each character in the string
    for (char ch : str) {
        if (ch == '{') {
            st.push(ch);
        }
        else {
            if (!st.empty() && st.top() == '{') {
                st.pop(); // valid pair found
            } else {
                st.push(ch); // unmatched closing brace
            }
        }
    }

    // Count the number of unmatched opening and closing braces
    int a = 0, b = 0;
    while (!st.empty()) {
        if (st.top() == '{') {
            a++;
        } else {
            b++;
        }
        st.pop();
    }

    // Minimum reversals needed = ceil(a/2) + ceil(b/2)
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main() {
    string s;
    cout << "Enter the brace string: ";
    cin >> s;

    int result = findMinimumCost(s);
    if (result == -1) {
        cout << "Impossible to balance the braces ❌" << endl;
    } else {
        cout << "Minimum reversals required: " << result << " ✅" << endl;
    }

    return 0;
}
