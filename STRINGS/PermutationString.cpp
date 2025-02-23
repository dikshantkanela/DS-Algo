// Approach:
// 1. Count the frequency of each character in s1.
// 2. Create a sliding window in s2 of the same size as s1.
// 3. Compare the frequency of characters in the current window with s1.
// 4. Slide the window one character at a time, updating the frequency count.
// 5. If at any step, the frequency matches s1, return true; otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

// Function to compare character frequency arrays
bool compare(int count1[], int count2[]) {
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}

// Function to check if s1's permutation is a substring of s2
bool checkInclusion(string s1, string s2) {
    int count1[26] = {0}; // stores count of char of s1
    int windowSize = s1.size();
    for (int i = 0; i < windowSize; i++) {
        int index = s1[i] - 'a';
        count1[index]++;
    }
    
    int count2[26] = {0};
    int i = 0;
    // for first window
    while (i < windowSize && i < s2.size()) { // i < s2.size() to ensure if the s1>s2 eg: "ab","a"
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    if (compare(count1, count2)) {
        return true;
    }
    
    while (i < s2.size() && s2.size() >= windowSize) {
        char newChar = s2[i];
        int index = newChar - 'a'; // add new character to the window
        count2[index]++;

        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--; // remove old character from the window
        
        if (compare(count1, count2)) {
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    string s1, s2;
    cout << "Enter first string (pattern): ";
    cin >> s1;
    cout << "Enter second string (main string): ";
    cin >> s2;
    
    if (checkInclusion(s1, s2)) {
        cout << "Yes, a permutation of s1 exists in s2." << endl;
    } else {
        cout << "No, a permutation of s1 does not exist in s2." << endl;
    }
    return 0;
}
