#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> rotatedArray(n);
    
    for (int i = 0; i < n; i++) {
        rotatedArray[(i + k) % n] = nums[i];
    }

    nums = rotatedArray;
}

// Main function for testing
int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3; // Number of rotations

    cout << "Original Array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    rotateArray(nums, k);

    cout << "Rotated Array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
