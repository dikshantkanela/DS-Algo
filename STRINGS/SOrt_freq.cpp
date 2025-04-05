#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// ✅ Approach:
// 1. Count the frequency of each character using a hashmap.
// 2. Copy the hashmap into a vector of pairs to sort it (since maps can't be directly sorted).
// 3. Sort the vector by frequency in descending order using a lambda.
// 4. Construct the final string by repeating each character according to its frequency.

class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        for(char ch:s){ // prepares the hashmap
            mp[ch]++;
        }

        vector<pair<char,int>> vec(mp.begin(),mp.end()); // copying the hasmap into vector of pair since directly sorting hashmap is not possible
        sort(vec.begin(),vec.end(),[](auto &a, auto &b){ // lambda func
            return a.second > b.second; // in desc
        });

        string ans = "";
        
        for(int i=0;i<vec.size();i++){
            ans += string(vec[i].second, vec[i].first); // builds string of size and a character
        }

        return ans;   
    }
};

int main() {
    Solution sol;
    string input;
    
    cout << "Enter a string: ";
    cin >> input;

    string result = sol.frequencySort(input);
    cout << "Sorted by frequency: " << result << endl;

    return 0;
}
