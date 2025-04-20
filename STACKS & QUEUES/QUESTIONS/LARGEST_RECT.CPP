// Approach:
// - The function maxArea() computes the largest rectangle containing only 1s in a binary matrix.
// - It uses the Largest Rectangle in Histogram technique row-wise, treating each row as a histogram.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmallest(vector<int> heights, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if (!st.empty() && heights[st.top()] < heights[i]) {
                ans[i] = st.top();
                st.push(i);
            }
            else if (st.empty()) {
                ans[i] = -1;
                st.push(i);
            }
        }

        return ans;
    }

    vector<int> prevSmallest(vector<int> heights, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if (!st.empty() && heights[st.top()] < heights[i]) {
                ans[i] = st.top();
                st.push(i);
            }
            else if (st.empty()) {
                ans[i] = -1;
                st.push(i);
            }
        }

        return ans;
    }

    int largestRectangleArea(vector<int> heights) {
        int n = heights.size();
        int maxi = 0;

        vector<int> next = nextSmallest(heights, n);
        vector<int> prev = prevSmallest(heights, n);

        for (int i = 0; i < n; i++) {
            if (next[i] == -1) {
                next[i] = n;
            }

            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int area = l * b;
            maxi = max(maxi, area);
        }

        return maxi;
    }

public:
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int area = largestRectangleArea(mat[0]);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] != 0) {
                    mat[i][j] = mat[i][j] + mat[i - 1][j];
                } else {
                    mat[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(mat[i]));
        }

        return area;
    }
};

int main() {
    Solution sol;

    // Example matrix (binary input)
    vector<vector<int>> matrix = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    int result = sol.maxArea(matrix);

    cout << "Maximum area of rectangle containing only 1s: " << result << endl;

    return 0;
}
