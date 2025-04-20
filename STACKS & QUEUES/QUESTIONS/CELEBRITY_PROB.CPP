#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute-force Approach: O(n^2)
    int celebrityBruteForce(vector<vector<int>>& mat) {
        int ans = -1;

        for (int i = 0; i < mat.size(); i++) {
            bool everyoneKnowsi = true;
            bool iKnowsNone = true;

            for (int j = 0; j < mat.size(); j++) {
                if (i != j && mat[i][j] == 1) {
                    iKnowsNone = false;
                    break;
                }
            }

            for (int j = 0; j < mat.size(); j++) {
                if (i != j && mat[j][i] == 0) {
                    everyoneKnowsi = false;
                    break;
                }
            }

            if (iKnowsNone && everyoneKnowsi) {
                return i;
            }
        }
        return ans;
    }

    // Stack-based Optimized Approach: O(n)
    int celebrityStack(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> st;

        // Push all candidates
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Eliminate non-celebrities
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if (mat[a][b] == 1) {
                // a knows b => a can't be celeb
                st.push(b);
            } else {
                // a doesn't know b => b can't be celeb
                st.push(a);
            }
        }

        if (st.empty()) return -1;
        int candidate = st.top();

        // Validate candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
                    return -1;
            }
        }

        return candidate;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int celebBrute = sol.celebrityBruteForce(mat);
    int celebStack = sol.celebrityStack(mat);

    cout << "Brute-force Approach: ";
    if (celebBrute != -1)
        cout << "Celebrity is at index " << celebBrute << endl;
    else
        cout << "No celebrity found." << endl;

    cout << "Stack-based Approach: ";
    if (celebStack != -1)
        cout << "Celebrity is at index " << celebStack << endl;
    else
        cout << "No celebrity found." << endl;

    return 0;
}
