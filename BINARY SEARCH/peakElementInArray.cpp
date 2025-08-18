    #include <iostream>
    #include <vector>

    using namespace std;

    /*
    APPROACH:
    - FIND A **PEAK ELEMENT** (ELEMENT GREATER THAN NEIGHBORS) USING **BINARY SEARCH**.
    - IF `NUMS[MID] < NUMS[MID+1]`, PEAK IS ON RIGHT. AAGE WALA AGAR BADA HAI TO RIGHT SIDE HI PEAK HAI!
    - ELSE, PEAK IS ON LEFT OR AT `MID`. AGAR AAGE WALA BADA NAHI HAI TO LEFT SIDE HOGA PEAK
    - CONTINUE UNTIL `START == END`, WHICH WILL BE THE PEAK.
    - TIME: **O(LOG N)** (BINARY SEARCH).
    - SPACE: **O(1)** (NO EXTRA MEMORY USED).
    */

    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        
        while (start < end) {
             int mid = start + (end - start) / 2;

            // MOVE TOWARDS THE PEAK
            if (nums[mid] < nums[mid + 1]) 
                start = mid + 1; // PEAK ON RIGHT
            else 
                end = mid; // PEAK ON LEFT OR AT MID
        }
        return start; // RETURN PEAK INDEX
    }

    int main() {
        vector<int> nums = {1, 2, 3, 1}; // EXAMPLE INPUT
        cout << "PEAK ELEMENT INDEX: " << findPeakElement(nums) << endl;
        return 0;
    }
