#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Method 1: Using Sum Formula
    int missingNumberSum(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n + 1)) / 2; // Sum of first n natural numbers
        int arrSum = 0;

        for (int num : nums) {
            arrSum += num;
        }

        return sum - arrSum;
    }

    // Method 2: Using XOR
    int missingNumberXOR(vector<int>& nums) {
        int res = 0, n = nums.size();

        // XOR all elements in the array
        for (int num : nums) {
            res ^= num;
        }

        // XOR with numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            res ^= i;
        }

        return res;
    }
};

// Driver Code
int main() {
    vector<int> nums = {3, 0, 1}; // Example input, missing number is 2
    Solution sol;

    cout << "Missing number (Sum method): " << sol.missingNumberSum(nums) << endl;
    cout << "Missing number (XOR method): " << sol.missingNumberXOR(nums) << endl;

    return 0;
}
