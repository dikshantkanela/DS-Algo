#include <bits/stdc++.h>
using namespace std;

// Approach:
// Use a deque to store indices of negative elements in the current window.
// For each window of size k:
// 1. Push indices of negative numbers in the deque.
// 2. The front of the deque will give the first negative number.
// 3. Remove elements from front if they are out of the current window.

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = arr.size();

        // Process the first window of size k
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                dq.push_back(i);
            }
        }
        if (!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0);
        }

        // Process the remaining windows
        for (int i = k; i < n; i++) {
            // Remove indices that are out of this window
            while (!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }
            // Add current element if it is negative
            if (arr[i] < 0) {
                dq.push_back(i);
            }
            // Append result for current window
            if (!dq.empty()) {
                ans.push_back(arr[dq.front()]); 
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> result = sol.firstNegInt(arr, k);

    cout << "First negative integer in every window of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
