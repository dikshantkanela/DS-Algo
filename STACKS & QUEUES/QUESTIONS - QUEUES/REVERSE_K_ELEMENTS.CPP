// Reverse first K elements of a queue
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to reverse first k elements of queue
    queue<int> reverseFirstK(queue<int> q, int k) {
        // Edge case: if k > size of queue, return original queue
        if (k > q.size()) {
            return q;
        }

        int n = q.size();
        stack<int> st;

        // Step 1: Push first k elements into a stack
        for (int i = 0; i < k; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Push stack elements back into the queue (they are reversed)
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move the remaining elements (n-k) to the back of the queue
        for (int i = 0; i < n - k; i++) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};

int main() {
    Solution sol;
    queue<int> q;

    // Input queue elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 3;

    // Reverse first k elements of queue
    queue<int> result = sol.reverseFirstK(q, k);

    // Output the modified queue
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}