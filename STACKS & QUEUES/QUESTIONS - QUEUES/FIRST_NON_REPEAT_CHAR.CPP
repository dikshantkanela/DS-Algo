// Approach:
// 1. We use a queue to store characters as they appear for the first time.
// 2. A hashmap keeps track of character frequencies.
// 3. For each character in the stream:
//    - If it's the first time, add it to the queue.
//    - If it repeats, check the front of the queue and pop the front that now have count > 1. to ensure that if another character has repeated ater the first popped front it does not be the answer
// 4. If queue is empty, append '#' to the result. Otherwise, append the front character.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        string ans = "";
        queue<char> q;
        unordered_map<char,int> mp;

        for(char ch:s){
            if(mp[ch]){
                mp[ch]++;
                while(!q.empty() && mp[q.front()]>1){
                    q.pop();
                }
            }
            else{
                mp[ch] = 1;
                q.push(ch); // push only 1 occurenece ones' till now
            }

            if(q.empty()){
                ans.push_back('#');
            }
            else{
                ans.push_back(q.front());
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "aabcbd";
    string result = sol.FirstNonRepeating(s);
    cout << "Result: " << result << endl;  // Expected output: "a#bbdd"
    return 0;
}
