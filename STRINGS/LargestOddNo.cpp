// Approach:
// 1. Iterate the string from the last character to the first.
// 2. Check if the current character is an odd digit.
// 3. If an odd digit is found, return the substring from the start to that index.
// 4. If no odd digit is found, return an empty string.

#include <bits/stdc++.h>
using namespace std;

// Function to find the largest odd number in a string
string largestOddNumber(string num) {
    int n = num.size();
    for (int i=n-1; i>=0; i--) {
        if (num[i]%2!=0) { // Check if the digit is odd
            return num.substr(0,i+1);
        }
    }
    return ""; // Return empty string if no odd digit is found
}

int main() {
    string num;
    cout << "Enter a numeric string: ";
    cin >> num;
    cout << "Largest odd number: " << largestOddNumber(num) << endl;
    return 0;
}
