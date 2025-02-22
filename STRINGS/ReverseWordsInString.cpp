// Approach:
// 1. Reverse the entire string.
// 2. Iterate through the reversed string and extract words.
// 3. Reverse each extracted word and append it to the result.
// 4. Trim the leading space before returning the final string.

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    reverse(s.begin(), s.end());
    string ans = "";
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        string word = "";
        while (s[i] != ' ' && i < n) {
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if (word.length() > 0) {
            ans += " " + word;
        }
    }
    return ans.substr(1);
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Reversed words: " << reverseWords(s) << endl;
    return 0;
}
