// Approach:
// Traverse the Roman numeral string. For each character, compare it with the next character:
// - If current character has a smaller value than the next one, subtract it from result.
// - Otherwise, add it to the result.

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && mp[s[i]] < mp[s[i + 1]]) {
                ans -= mp[s[i]];
            } else {
                ans += mp[s[i]];
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string roman = "MCMXCIV";
    cout << "Roman: " << roman << endl;
    cout << "Integer: " << sol.romanToInt(roman) << endl;
    return 0;
}
