#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 🟦 Your original hashmap-based solution
    int majorityElementHashmap(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        // Count frequency of each number
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int maxCount = 0;
        int maxEle = 0;

        // Find the element with the maximum frequency
        for (const auto& pair : mp) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                maxEle = pair.first;
            }
        }

        return maxEle;
    }

    // 🟩 Boyer-Moore Voting Algorithm (O(1) space)
    int majorityElementBoyerMoore(vector<int>& nums) {
        int candidate = nums[0];  // Initial candidate
        int count = 0;            // Vote counter

        for (int num : nums) {
            // If no current candidate, choose the current number
            if (count == 0) {
                candidate = num;
            }

            // Increment or decrement the count based on match
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    // Test original hashmap approach
    int resultHashmap = sol.majorityElementHashmap(nums);
    cout << "Majority Element (Hashmap): " << resultHashmap << endl;

    // Test Boyer-Moore approach
    int resultBM = sol.majorityElementBoyerMoore(nums);
    cout << "Majority Element (Boyer-Moore): " << resultBM << endl;

    return 0;
}
