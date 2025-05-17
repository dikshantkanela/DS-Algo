#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // ----------------------------------------------------
    // Approach 1: Counting Sort
    // ----------------------------------------------------
    // Count the number of 0s, 1s, and 2s.
    // Then overwrite the array based on those counts.
    // Time: O(n), Space: O(1)
    void sortColorsCount(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                zero++;
            }
            else if(nums[i] == 1) {
                one++;
            }
            else {
                two++;
            }
        }

        int i = 0;
        while(zero != 0) {
            nums[i] = 0;
            zero--;
            i++;
        }
        while(one != 0) {
            nums[i] = 1;
            one--;
            i++;
        }
        while(two != 0) {
            nums[i] = 2;
            two--;
            i++;
        }
    }

    // ----------------------------------------------------
    // Approach 2: Dutch National Flag Algorithm
    // ----------------------------------------------------
    // Maintain three pointers: low, mid, high.
    // Swap elements based on the value at mid.
    // Time: O(n), Space: O(1)
    void sortColorsDNF(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Helper function to print a vector
void printVector(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    vector<int> nums2 = nums1; // duplicate input for second function

    cout << "Original array: ";
    printVector(nums1);

    sol.sortColorsCount(nums1);
    cout << "After Counting Sort: ";
    printVector(nums1);

    sol.sortColorsDNF(nums2);
    cout << "After Dutch National Flag Sort: ";
    printVector(nums2);

    return 0;
}
