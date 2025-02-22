// Approach:
// 1. Create an array of size 26 (for each letter of the English alphabet) initialized to zero.
//    - This array will store the frequency of each character in the given string.
//
// 2. Iterate through the string:
//    - If the character is a lowercase letter (between 'a' and 'z'), find its index by subtracting 'a'.
//    - If the character is an uppercase letter (between 'A' and 'Z'), find its index by subtracting 'A'.
//    - Increment the count of that character in the frequency array.
//
// 3. Traverse the frequency array to find the character with the highest occurrence:
//    - Maintain variables `maxi` (to track the highest frequency) and `ans` (to store the index of the most frequent character).
//    - If a character's frequency is greater than `maxi`, update `ans` and `maxi`.
//
// 4. Convert the most frequently occurring character's index back to a character by adding 'a' (since indexes are stored as 0-25 for 'a'-'z').
//
// 5. Return the most frequently occurring character.

#include <bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(string s) {
    int arr[26] = {0}; // Frequency array for 26 lowercase letters
    int len = 26;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        int index = 0;
        if (s[i] >= 'a' && s[i] <= 'z') {
            index = s[i] - 'a'; // Get index for lowercase letter
        } else {
            index = s[i] - 'A'; // Get index for uppercase letter
        }
        arr[index]++; // Increment frequency
    }
    
    int maxi = -1;
    int ans = -1;
    for (int i = 0; i < len; i++) {
        if (arr[i] > maxi) { // Find the character with the maximum frequency
            ans = i;
            maxi = arr[i];
        }
    }
    return ans + 'a';  // Convert index back to character
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Maximum occurring character: " << getMaxOccuringChar(s) << endl;
    return 0;
}
