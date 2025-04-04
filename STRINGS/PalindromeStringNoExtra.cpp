#include <bits/stdc++.h>
using namespace std;


// Function to check palindrome using no extra space
bool checkPalindrome(string s, int n) {
    int start = 0;
    int end = n-1;

    while(start<=end){
        if(s[start] == s[end]){
            start++;
            end--; // check further
        }

        else{
            return false; // if at any pt the codn fails answer is false
        }
    }
    return true;
}

int main() {
    // Test Cases
    string test1 = "racecar";
    int n = test1.size();
    cout << "Is " << test1 << " palindrome? " << (checkPalindrome(test1,n)?"Yes":"No");
    
    
    return 0;
}