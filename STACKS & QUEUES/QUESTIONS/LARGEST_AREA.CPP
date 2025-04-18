#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // 🔽 Find index of next smaller element to the right for each bar
    vector<int> nextSmallest(vector<int> heights, int n){
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if(!st.empty() && heights[st.top()] < heights[i]) {
                ans[i] = st.top();
                st.push(i);
            }
            else if(st.empty()) {
                ans[i] = -1;
                st.push(i);
            }
        }

        return ans;
    }

    // 🔼 Find index of previous smaller element to the left for each bar
    vector<int> prevSmallest(vector<int> heights, int n){
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if(!st.empty() && heights[st.top()] < heights[i]) {
                ans[i] = st.top();
                st.push(i);
            }
            else if(st.empty()) {
                ans[i] = -1;
                st.push(i);
            }
        }

        return ans;
    }

    // 📐 Calculate the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;

        vector<int> next = nextSmallest(heights, n);
        vector<int> prev = prevSmallest(heights, n);

        for(int i = 0; i < n; i++) {
            // If no smaller element to the right, treat boundary as 'n'
            if(next[i] == -1) {
                next[i] = n;
            }

            int l = heights[i];                  // Height of the current bar
            int b = next[i] - prev[i] - 1;       // Width of rectangle
            int area = l * b;                    // Area = height * width
            maxi = max(maxi, area);              // Keep track of maximum area
        }

        return maxi;
    }
};

int main() {
    // 🧪 Sample test input
    vector<int> histogram = {2, 1, 5, 6, 2, 3};

    // Create object of the Solution class
    Solution sol;

    // Call the function and store result
    int maxArea = sol.largestRectangleArea(histogram);

    // 📤 Output the result
    cout << "Largest Rectangle Area: " << maxArea << endl;

    return 0;
}
