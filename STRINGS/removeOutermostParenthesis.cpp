/*
Approach:
We need to remove the outermost parentheses of every primitive substring in the input string.
- We keep a counter to track the depth of the parentheses.
- When we see '(', we increment the counter; when we see ')', we decrement it.
- We only add characters to the result string if the current depth (after or before updating) is greater than 0.
  This way, we skip the outermost opening and closing brackets of each primitive.

Time Complexity: O(n)
Space Complexity: O(n) for storing the result
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int count = 0;
        int i = 0;
        string ans = "";
        while (i < n) {
            if (s[i] == ')') { //count = 0 means either begin ( of outermost paranthesis or end ) of outer paranthesis
                count--;
            }

            if (count > 0) {
                ans.push_back(s[i]);
            }

            if (s[i] == '(') {
                count++;
            }

            i++;
        }
        return ans;
    }
};
