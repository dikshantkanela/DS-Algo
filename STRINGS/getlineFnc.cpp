#include <bits/stdc++.h>
using namespace std;

int main() {
    // FOR char arrays!
    char sentence[50];
    cout << "Enter a sentence: ";
    // WITHOUT DELIMITER - DEFAULT = '\n'
    cin.getline(sentence, 50);  // WILL NOT READ THE STRING AFTER '\n'
    cout << sentence << endl;

    char message[20];
    // WITH DELIMITER:
    cout << "Enter a message: ";
    cin.getline(message, 20, '.');  // WILL NOT READ THE STRING AFTER '.'
    cout << message << endl;
    
    // FOR strings!
    string strs;
    cout << "Enter string: ";
    getline(cin, strs);  // Reads the full line
    cout << strs << endl;

    return 0;
}
