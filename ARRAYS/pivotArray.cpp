#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result(nums.size());
        int lesserCount = 0;
        int greaterCount = 0;

        // Count elements less than and greater than the pivot
        for (int num : nums) {
            if (num > pivot) {
                greaterCount++;
            } else if (num < pivot) {
                lesserCount++;
            }
        }

        // Calculate counts and pointers
        int equalCount = nums.size() - lesserCount - greaterCount;
        int lesserPointer = 0;
        int equalPointer = lesserCount;
        int greaterPointer = lesserCount + equalCount;

        // Fill result array
        for (int num : nums) {
            if (num < pivot) {
                result[lesserPointer] = num;
                lesserPointer++;
            } else if (num == pivot) {
                result[equalPointer] = num;
                equalPointer++;
            } else {
                result[greaterPointer] = num;
                greaterPointer++;
            }
        }

        return result;
    }
};

// Main function to test the pivotArray function
int main() {
    Solution sol;
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> result = sol.pivotArray(nums, pivot);

    cout << "Rearranged array around pivot " << pivot << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
