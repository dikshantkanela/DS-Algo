#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
     
    void solve(string &digits, vector<string> &ans, string output, int index, unordered_map<char, string> &mp) {
        if (index > digits.length() - 1) { // base case :
            ans.push_back(output);
            return;
        }   

        char mappedDigit = digits[index]; // get the first,second...nth element of str and extract the key of the hashmap
        string mappedLetters = mp[mappedDigit]; // get value (the strings we have to use to make pairs) from that key

        for (int i = 0; i < mappedLetters.length(); i++) {
            output.push_back(mappedLetters[i]); // extract character from strings one by one and for each character make pairs with the next digit of the i/p no.
            solve(digits, ans, output, index + 1, mp); // to make pairs with next digits of the input number
            output.pop_back(); // this is necessary else the output will include the element which was previously paired as well 
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string output = "";     
        int index = 0;
        solve(digits, ans, output, index, mp);
        return ans;
    }    
};

int main() {
    Solution s;
    string input = "2";
    vector<string> result = s.letterCombinations(input);

    cout << "Combinations for \"" << input << "\":" << endl;
    for (string &str : result) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
