#include <iostream>
#include <vector>
using namespace std;

// ✅ Recursive function to generate all subsequences of a string
void solve(string &str, string output, vector<string> &ans, int index) {
    // 🛑 Base Case: Reached the end of the string
    if (index > str.length() - 1) {
        if (output != "") {         // ✂️ Skip empty string
            ans.push_back(output);  // ✅ Add non-empty subsequence
        }
        return;
    }

    // 🔴 Exclude the current character
    solve(str, output, ans, index + 1);

    // 🟢 Include the current character
    char element = str[index];
    output.push_back(element);  // or use output += element;
    solve(str, output, ans, index + 1);
}

// 🔁 Function to generate all non-empty subsequences of a string
vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, ans, index);
    return ans;
}

// 🧪 Main function to test the above logic
int main() {
    string input = "abc";
    vector<string> result = subsequences(input);

    // 🖨️ Output the result
    cout << "All non-empty subsequences of \"" << input << "\":" << endl;
    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
