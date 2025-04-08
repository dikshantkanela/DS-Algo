#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                    right++;
            }
        }

        while (left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high){
            temp.push_back(nums[right]);
            right++;
        } 

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void mS(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        mS(nums, low, mid);
        mS(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mS(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 9, 1, 5, 6};
    vector<int> sortedNums = sol.sortArray(nums);
    
    cout << "Sorted array: ";
    for (int num : sortedNums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
