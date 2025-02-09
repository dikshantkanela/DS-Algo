#include <bits/stdc++.h>
using namespace std;

bool checkSortedRotated(vector<int>& nums) {
    int count = 0; 
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i-1] > nums[i]) {
            count++;
        }
    }
    if(nums[0] < nums[nums.size()-1]) {
        count++;
    }
    return count <= 1; // only 1 pair where arr[i-1]>arr[i] is possible in a sorted/sorted+rotated array    
}

// Main function for testing
int main() {
    vector<int> nums1 = {3, 4, 5, 1, 2}; // ✅ Sorted & Rotated
    vector<int> nums2 = {1, 2, 3, 4, 5}; // ✅ Sorted 
    vector<int> nums3 = {2, 1, 3, 4, 5}; // ❌ Not Sorted & Rotated
    vector<int> nums4 = {5, 1, 2, 3, 4}; // ✅ Sorted & Rotated

    cout << (checkSortedRotated(nums1) ? "Yes" : "No") << endl; // Output: Yes
    cout << (checkSortedRotated(nums2) ? "Yes" : "No") << endl; // Output: No
    cout << (checkSortedRotated(nums3) ? "Yes" : "No") << endl; // Output: No
    cout << (checkSortedRotated(nums4) ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}
