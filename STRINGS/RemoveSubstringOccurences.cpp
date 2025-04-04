

#include <bits/stdc++.h>
using namespace std;

// Function to remove all occurrences of "part" from "s"
string removeOccurrences(string s, string part) {
    while (s.find(part) != string::npos) {
        s.erase(s.find(part), part.length());// IF THE PART IS NOT FOUND THEN THE LOOP WILL BREAK SINCE ALL THE SUBSTR PARTS ARE ALREADY REMOVED!
    }   
    return s;
}

int main() {
    string s, part;
    cout << "Enter the main string: ";
    cin >> s;
    cout << "Enter the part to remove: ";
    cin >> part;
    cout << "Modified string: " << removeOccurrences(s, part) << endl;
    return 0;
}
