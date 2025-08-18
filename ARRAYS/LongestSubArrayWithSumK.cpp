#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& nums, int k) {
    // PREFIX SUM + HASHMAP METHOD WHEN THERE ARE BOTH - & + NUMBERS!
    map<int, int> preSumMap;
    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == k) {
            maxLen = max(maxLen, i+1);
        }

            int rem = sum-k;

        if (preSumMap.find(rem) != preSumMap.end()) { // IF THE REM EXISTS IN THE ARRAY, USING ITS INDEX FIND THE LENGTH OF THE ARRAY
            int len = i-preSumMap[rem];
            maxLen = max(len, maxLen);
        }

        if (preSumMap.find(sum) == preSumMap.end()) { // STORE THE SUM IN HASHMAP ONLY IF IT PREVIOUSLY DOES NOT EXIST (TO AVOID SHORTER LENGTH ARRAYS WITH THE SAME SUM)
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}


int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 1, 1, -1, 3, 4}; // Example array
    int k = 5; // Target sum

    cout << "Longest subarray length with sum " << k << " is: " << getLongestSubarray(nums, k) << endl;
    
    return 0;
}
