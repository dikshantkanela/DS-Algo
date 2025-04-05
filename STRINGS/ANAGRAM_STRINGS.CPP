#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int k = t.length();
        if(n!=k){
            return false;
        }

        unordered_map<char,int> mp;

        for(int i=0;i<n;i++){ // inserted the hashmap using s and stores count of each alphabet
            mp[s[i]]++;
        }

        for(int i=0;i<k;i++){
            if(mp.find(t[i]) != mp.end()){
                mp[t[i]]--; // if already exists in map reduce count by 1
                if(mp[t[i]]<0){ // if counts gets lesser than zero that means it is not anagram since the other string has more no of that particular character
                    return false;
                }
            }

            else if(mp.find(t[i]) == mp.end()){ // if character doesnt exist in the map then it is not an anagram!
                return false;
            }
        }

        return true;
    }

    // ✅ Approach (Sorting based):
    // 1. If the lengths differ, return false.
    // 2. Sort both strings.
    // 3. If sorted strings are equal, return true — they are anagrams.
    bool isAnagramSorted(string s, string t) {
        if (s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

int main() {
    Solution sol;

    string s1 = "listen";
    string s2 = "silent";

    cout << "Using Hashmap: ";
    if (sol.isAnagram(s1, s2)) {
        cout << s1 << " and " << s2 << " are anagrams." << endl;
    } else {
        cout << s1 << " and " << s2 << " are NOT anagrams." << endl;
    }

    cout << "Using Sorting: ";
    if (sol.isAnagramSorted(s1, s2)) {
        cout << s1 << " and " << s2 << " are anagrams." << endl;
    } else {
        cout << s1 << " and " << s2 << " are NOT anagrams." << endl;
    }

    return 0;
}
