#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*-------------------------------------------------------
    Brute-force approach: Time Complexity O(n^2)
    
    ➤ For every index i (start of subarray), check all 
      subarrays starting from i to j (j ≥ i)
    ➤ Keep a running sum of elements from i to j
    ➤ If running sum == k, increase count

    Simple but slow for large arrays
--------------------------------------------------------*/
int bruteCountSubarraysWithSumK(const vector<int>& nums, int k) {
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        int sum = 0; // running sum from index i to j
        for (int j = i; j < n; ++j) {
            sum += nums[j];
            if (sum == k) {
                count++;
            }
        }
    }

    return count;
}

/*-------------------------------------------------------
    Optimized approach: Prefix Sum + Hash Map
    Time Complexity: O(n)
    Space Complexity: O(n)
    
    ➤ Maintain a prefix sum (sum of elements from 0 to i)
    ➤ Store how many times each prefix sum has occurred
    ➤ If at index i, prefixSum = current total sum so far
    ➤ We want to find how many times (prefixSum - k) 
      has appeared before
        → This means a subarray with sum = k ends at i
    ➤ Example: if prefixSum = 12 and k = 5, we need to know
      how many times prefixSum 7 has occurred before

    ➤ Initialize map with {0:1} to handle subarrays 
      starting from index 0
--------------------------------------------------------*/
int prefixCountSubarraysWithSumK(const vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumFreq;
    prefixSumFreq[0] = 1; // to count subarrays starting at index 0

    int count = 0;
    int prefixSum = 0;

    for (int num : nums) {
        prefixSum += num;

        // check if there is a previous prefixSum that gives sum = k
        if (prefixSumFreq.find(prefixSum - k) != prefixSumFreq.end()) {
            count += prefixSumFreq[prefixSum - k];
        }

        // store/update the current prefix sum in the map
        prefixSumFreq[prefixSum]++;
    }

    return count;
}

/*-------------------------------------------------------
    Main function to test both approaches
--------------------------------------------------------*/
int main() {
    vector<int> nums = {1, 2, 3, -2, 5, -3, 1, 2}; 
    int k = 5;

    cout << "Array: ";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << "\nTarget Sum (k): " << k << "\n\n";

    // Brute-force method
    int bruteResult = bruteCountSubarraysWithSumK(nums, k);
    cout << "Brute-force Count    : " << bruteResult << "\n";

    // Optimized prefix-sum method
    int optimizedResult = prefixCountSubarraysWithSumK(nums, k);
    cout << "Prefix Sum Count     : " << optimizedResult << "\n";

    return 0;
}
