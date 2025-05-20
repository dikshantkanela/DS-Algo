#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// ----------- Brute Force Method ------------ //
bool existenceCheck(vector<int>& ans, int val) {
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == val) {
            return true;
        }
    }
    return false;
}

vector<int> bruteForceSuperiorElements(vector<int>& a) {
    vector<int> ans;
    int n = a.size();
    
    for (int i = 0; i < n; i++) {
        bool superior = true;
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                superior = false;
                break;
            }
        }

        if (superior && !existenceCheck(ans, a[i])) {
            ans.push_back(a[i]);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

// ----------- Optimized Method ------------ //
vector<int> optimizedSuperiorElements(vector<int>& a) {
    vector<int> ans;
    int n = a.size();
    int maxi = INT_MIN;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > maxi) {
            ans.push_back(a[i]);
            maxi = a[i];
        }
    }

    reverse(ans.begin(), ans.end()); // Optional: to maintain left-to-right order
    return ans;
}

// ----------- Main Function ------------ //
int main() {
    vector<int> a = {1, 2, 3, 2, 1, 0};

    // Brute force version
    vector<int> bruteResult = bruteForceSuperiorElements(a);
    cout << "Brute Force - Superior elements: ";
    for (int val : bruteResult) {
        cout << val << " ";
    }
    cout << endl;

    // Optimized version
    vector<int> optResult = optimizedSuperiorElements(a);
    cout << "Optimized - Superior elements: ";
    for (int val : optResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
