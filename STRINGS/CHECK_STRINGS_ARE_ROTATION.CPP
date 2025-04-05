/*
Approach:
To check if one string is a rotation of another, we:
1. Iterate through all possible rotations (0 to n-1).
2. For each rotation count `i`, we:
   - Create a new string `rotated` of same length.
   - Rotate the string by shifting characters using `(j + i) % n`.
3. After each rotation, we compare the rotated string with the `goal`.
4. If any rotation matches, return true. If none match, return false.

Time Complexity: O(n^2) → For n rotations, each taking O(n)
Space Complexity: O(n) → For the `rotated` string
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();

        for (int i = 0; i < n; i++) { // i represents the number of times to rotate
            string rotated(n, ' ');
            for (int j = 0; j < n; j++) { // this loop is rotating the array by i times
                rotated[(j + i) % n] = s[j];
            }
            if (rotated == goal) {
                return true;
            }
        }
        return false;
    }
};

// ✅ Example usage
int main() {
    Solution sol;
    string s = "abcde";
    string goal = "cdeab";
    cout << (sol.rotateString(s, goal) ? "True" : "False") << endl;
    return 0;
}
