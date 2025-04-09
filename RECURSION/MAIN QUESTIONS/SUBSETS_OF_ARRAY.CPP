#include <iostream>
#include <vector>
using namespace std;

// ✅ Approach:
// - This function generates all subsets (the power set) of a given array.
// - It uses a recursive "Include-Exclude" strategy:
//   → For each element, you either include it or exclude it in the current subset.
// - When the index reaches the end of the array, the current subset is added to the result.
// - Time Complexity: O(2^n) - since each element has 2 choices (include/exclude)
// - Space Complexity: O(2^n * n) - to store all subsets

class Solution {
public:
    // 🔁 Recursive function to explore all subsets
    void solve(vector<int>& nums, vector<int> output, vector<vector<int>>& ans, int index) {
        // 🛑 Base Case: If we've processed all elements
        if (index >= nums.size()) {
            ans.push_back(output);  // Add the current subset to the answer
            return;
        }

        // 🔴 Exclude the current element and move to the next
        solve(nums, output, ans, index + 1);

        // 🟢 Include the current element
        output.push_back(nums[index]);
        solve(nums, output, ans, index + 1);
    }

    // 📦 Main function that returns all subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;   // Stores all subsets
        vector<int> output;        // Temporarily stores current subset
        int index = 0;             // Start from index 0
        solve(nums, output, ans, index);
        return ans;
    }
};

int main() {
    // 🧾 Input vector
    vector<int> nums = {1, 2, 3};

    // 🎯 Create object of Solution class
    Solution sol;

    // 🧠 Generate all subsets
    vector<vector<int>> result = sol.subsets(nums);

    // 📤 Print all subsets
    cout << "All subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
