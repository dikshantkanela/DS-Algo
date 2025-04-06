#include <iostream>
#include <string>
#include <climits>  // For INT_MIN and INT_MAX
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Handle optional '+' or '-' sign
        int sign = 1;
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < n && s[i] == '+') {
            sign = 1;
            i++;
        }

        // Step 3: Convert digits and stop at non-digit characters
        long int result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            result = result * 10 + digit;

            // Step 4: Check for overflow
            if (result * sign < INT_MIN) return INT_MIN;
            if (result * sign > INT_MAX) return INT_MAX;

            i++;
        }

        // Step 5: Return result with sign
        return result * sign;
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);  // Read full line including spaces

    int result = sol.myAtoi(input);
    cout << "Converted integer: " << result << endl;

    return 0;
}
