#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Create prefix sum arrays for left and right
        vector<int> left(n);
        vector<int> right(n);
        
        int leftEle = 0;  // Sum of elements to the left of current index
        int rightEle = 0; // Sum of elements to the right of current index

        // Fill left prefix sum array
        for(int i = 0; i < n; i++) {
            left[i] = leftEle;
            leftEle += nums[i];
        }

        // Fill right prefix sum array (in reverse)
        for(int i = n - 1; i >= 0; i--) {
            right[i] = rightEle;
            rightEle += nums[i];
        }

        // Compare left and right sums for pivot index
        for(int i = 0; i < n; i++) {
            if(right[i] == left[i]) {
                return i; // Found the pivot index
            }
        }

        return -1; // No pivot index found
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 6, 5, 6};  // Try {2,1,-1} or {1,2,3} too

    int result = sol.pivotIndex(nums);

    if (result != -1) {
        cout << "Pivot index is: " << result << endl;
    } else {
        cout << "No pivot index found." << endl;
    }

    return 0;
}

