// Approach:
// 1. Iterate through the string character by character.
// 2. If two adjacent characters are the same, remove them using erase().
// 3. Continue checking from the current position to ensure all duplicates are removed.
// 4. Return the modified string after processing.

#include <bits/stdc++.h>
using namespace std;

// Function to remove adjacent duplicate characters
string removeDuplicates(string s) {
    int n = s.length();
    int i = 0;
    while (i < n) {
        if (s[i] == s[i + 1] && (i + 1) < n) { // i+1<n FOR ENSURING END ELEMENT DOESNT COMPARE WITH THE NEXT WHICH DOESNT EXIST!
            s.erase(i, 2);
            n = s.length(); // MUST UPDATE THE SIZE OF STR AFTER ERASING
            // LOGIC TO MOVE BACK AFTER REMOVING :
            i = max(i - 1, 0); // WILL HANDLE THE CASE WHEN i = 0 AND WE CANNOT i-1
        } else { // MOVE FORWARD IF NO ADJ DUP FOUND!
            i++;
        }
    }
    return s;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Modified string: " << removeDuplicates(s) << endl;
    return 0;
}
