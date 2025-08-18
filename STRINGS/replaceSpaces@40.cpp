// Approach:
// 1. Iterate through the given string character by character.
// 2. If a space (' ') is encountered, replace it with "@40".
// 3. Otherwise, append the character to the result string.
// 4. Return the modified string after processing.

#include <bits/stdc++.h>
using namespace std;

// Function to replace spaces with "@40"
string replaceSpaces(string &str) {
    int n = str.length();
    string word = "";

    for (int i = 0; i < n; i++) {
        while (str[i] != ' ' && i < n) { // Process normal characters and get a word
            word += str[i];
            i++;
        }
        if (str[i] == ' ') { // Replace space with "@40" this condn is needed varna last me bhi krdega!
            word += "@40";  
        }
    }
    return word;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Modified string: " << replaceSpaces(str) << endl;
    return 0;
}
