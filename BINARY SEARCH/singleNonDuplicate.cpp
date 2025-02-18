#include <iostream>
#include <vector>

using namespace std;

/*
APPROACH:
- USE **BINARY SEARCH** TO FIND THE SINGLE NON-DUPLICATE ELEMENT.
- IF `MID` IS EVEN & `NUMS[MID] == NUMS[MID+1]`, SEARCH RIGHT, till now single has not disrupted the array.
- IF `MID` IS ODD & `NUMS[MID] == NUMS[MID-1]`, SEARCH RIGHT, till now single has not disrupted the array.
- ELSE, SEARCH LEFT.
- TIME COMPLEXITY: **O(LOG N)** (BINARY SEARCH).
- SPACE COMPLEXITY: **O(1)** (CONSTANT EXTRA SPACE).
*/

int singleNonDuplicate(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    
    while (start < end) {
        // CHECK PAIRING PATTERN
        if (mid % 2 == 0 && nums[mid] == nums[mid + 1]) 
            start = mid + 1;
        else if (mid % 2 != 0 && nums[mid] == nums[mid - 1]) 
            start = mid + 1;
        else 
            end = mid;

        mid = start + (end - start) / 2;
    }
    return nums[start]; // RETURN THE SINGLE ELEMENT
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5}; // EXAMPLE INPUT
    cout << "SINGLE NON-DUPLICATE ELEMENT: " << singleNonDuplicate(nums) << endl;
    return 0;
}
