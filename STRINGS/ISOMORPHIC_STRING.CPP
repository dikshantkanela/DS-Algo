/*
Approach:
To check if two strings `s` and `t` are **isomorphic**, we must ensure:
1. Every character in `s` maps to a unique character in `t`.
2. The mapping is consistent and one-to-one.

To achieve this:
- We use two hashmaps:
  🔸 `mp1`: maps characters from `s` to `t`.
  🔸 `mp2`: maps characters from `t` to `s`.

Why two maps?
- To prevent **two characters in `s` from mapping to the same character in `t`** and vice versa.
- Ensures **bijective mapping** (one-to-one and onto).

Conditions to return false:
1. If characters at the same index in `s` and `t` are already mapped but the mapping doesn't match → means inconsistency → return `false`.
2. If the length of both strings isn't equal → directly return `false`.

Time Complexity: O(n), where n is the length of the strings.
Space Complexity: O(1), since max size is limited to character set (256 at most).
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> mp1; // s -> t
        unordered_map<char, char> mp2; // t -> s
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if (mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) {
                return false; // inconsistent mapping from s to t
            } 
            else if (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1) {
                return false; // inconsistent mapping from t to s
            }

            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};

// ✅ Example Usage
int main() {
    Solution sol;
    string s = "egg";
    string t = "add";

    cout << (sol.isIsomorphic(s, t) ? "Isomorphic" : "Not Isomorphic") << endl;
    return 0;
}
