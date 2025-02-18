#include <iostream>
#include <vector>

using namespace std;

int findPivot(vector<int>& nums, int n) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    
    while (start < end) {
        // Skip duplicates after calculating mid
        int origStart = start;
        int origEnd = end;
        while (start < end && nums[start] == nums[start + 1]) start++;
        while (start < end && nums[end] == nums[end - 1]) end--;

        // If bounds changed significantly, recalculate mid
        if (start != origStart || end != origEnd) {
            mid = start + (end - start) / 2;
        }

        if (nums[mid] >= nums[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

bool binarySearch(vector<int>& nums, int start, int end, int target) {
    int mid = start + (end - start) / 2;
    while (start <= end) {
        if (nums[mid] == target) {
            return true;
        }
        if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}

bool searchInRotatedArray(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return false;

    int pivot = findPivot(nums, n);
    if (binarySearch(nums, 0, pivot - 1, target)) {
        return true;
    }
    return binarySearch(nums, pivot, n - 1, target);
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 2}; // Example rotated sorted array with duplicates
    int target = 0;

    if (searchInRotatedArray(nums, target)) {
        cout << "Element " << target << " found in the array.\n";
    } else {
        cout << "Element " << target << " not found in the array.\n";
    }

    return 0;
}
