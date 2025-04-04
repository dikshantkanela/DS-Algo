/*
Approach:
- We initialize `prefix` with the first string in the array.
- We iterate through the remaining strings.
- If `prefix` is not a prefix of the current string, we keep reducing it from the end.
- If `prefix` becomes empty, there is no common prefix.

Time Complexity: O(N * M) 
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        if(strs.size() == 1){
            return strs[0];
        }

        string prefix = strs[0];
        int n = strs.size();

        for(int i = 1; i < n; i++){
            while(strs[i].find(prefix) != 0){
                prefix = prefix.substr(0, prefix.size() - 1); // reduce the prefix until it matches the current element of the array
                if(prefix.empty()){ // prefix becomes empty means elements don't have a Common Prefix
                    return "";
                }
            }
        }
        return prefix;
    }
};

// ✅ Example Usage
int main() {
    Solution sol;
    vector<string> words = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(words) << endl;
    return 0;
}
