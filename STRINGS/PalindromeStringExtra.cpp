#include <bits/stdc++.h>
using namespace std;

// Function to reverse the string by swapping characters
void reverse(string &str, int n) { //MODIFYING THE STRING USING PASS BY REF IN FUNC
    int start = 0;
    int end = n - 1;
    while(start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

// Function to check palindrome using extra space
bool checkPalindrome(string s) {
    // Make a copy of original string
    string cpy = s; // STORES A COPY, NOT REFERENCE!!
    int n = s.size();
    
    // Reverse the original string
    reverse(s, n);
    
    // Compare copy with reversed string
    return (cpy == s);
}

int main() {
    // Test Cases
    string test1 = "racecar";
    string test2 = "hello";
    string test3 = "madam";
    string test4 = "a";
    string test5 = "noon";
    
    cout << "Is " << test1 << " palindrome? " << (checkPalindrome(test1) ? "Yes" : "No") << endl;
    cout << "Is " << test2 << " palindrome? " << (checkPalindrome(test2) ? "Yes" : "No") << endl;
    cout << "Is " << test3 << " palindrome? " << (checkPalindrome(test3) ? "Yes" : "No") << endl;
    cout << "Is " << test4 << " palindrome? " << (checkPalindrome(test4) ? "Yes" : "No") << endl;
    cout << "Is " << test5 << " palindrome? " << (checkPalindrome(test5) ? "Yes" : "No") << endl;
    
    return 0;
}