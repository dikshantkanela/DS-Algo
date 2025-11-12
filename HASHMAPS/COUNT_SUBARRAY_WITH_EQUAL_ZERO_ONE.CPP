#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

class Solution {
public:
    int countEqualSubarrays(vector<int>& nums) {
        // mp: {prefix_sum: frequency_of_that_sum}
        unordered_map<int, int> mp;
        
        int count = 0;
        int currSum = 0;

        for(int num : nums){ // Using range-based for loop for clarity
            
            // Step 1: Update the current prefix sum (0 -> -1, 1 -> +1)
            currSum += (num == 0) ? -1 : 1;

            // Step 2 & 3: Count subarrays
            // If currSum is 0, the subarray from index 0 is valid.
            if(currSum == 0){
                count++;
            }

            // If currSum has been seen before, add the previous occurrences to the count.
            if(mp.count(currSum)){
                count += mp[currSum];
            }

            // Step 4: Update the frequency of the current prefix sum
            // This prepares it for future subarrays.
            mp[currSum]++;
        }
        return count; 
    }
};