/* 
Approach:
1. Binary Search between 1 and max element
2. For each mid value, calculate sum of ceiling divisions
3. If sum > threshold: need larger divisor, move right
4. If sum <= threshold: store potential answer, try smaller divisor
5. Return smallest valid divisor found

Time: O(n * log(max)) where n = array length, max = maximum element
Space: O(1) - constant extra space
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate sum of ceiling divisions
int getSum(vector<int>& nums, int n, int mid) {
    int ansSum = 0;
    for(double i = 0; i < n; i++) {
        ansSum += ceil((double)(nums[i]/(double)(mid)));
    }
    return ansSum;
}

// Function to find smallest divisor
int smallestDivisor(vector<int>& nums, int threshold) {
    int start = 1;
    int max = -1;
    int n = nums.size();
    
    // Find maximum element
    for(int i = 0; i < n; i++) {
        if(nums[i] > max) {
            max = nums[i];
        }
    }
    
    int end = max;
    int mid = start + (end-start)/2;
    int ans = -1;
    
    // Binary search
    while(start <= end) {
        int sum = getSum(nums, n, mid);
        if(sum > threshold) {
            start = mid + 1;
        }
        else if(sum <= threshold) {
            ans = mid;
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main() {
    // Test Case 1
    vector<int> nums1 = {1, 2, 5, 9};
    int threshold1 = 6;
    cout << "Test Case 1:" << endl;
    cout << "Array: [1, 2, 5, 9]" << endl;
    cout << "Threshold: " << threshold1 << endl;
    cout << "Smallest Divisor: " << smallestDivisor(nums1, threshold1) << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {44, 22, 33, 11, 1};
    int threshold2 = 5;
    cout << "Test Case 2:" << endl;
    cout << "Array: [44, 22, 33, 11, 1]" << endl;
    cout << "Threshold: " << threshold2 << endl;
    cout << "Smallest Divisor: " << smallestDivisor(nums2, threshold2) << endl << endl;
    
    // Custom input test
    int n, threshold;
    cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> customNums(n);
    cout << "Enter " << n << " numbers: ";
    for(int i = 0; i < n; i++) {
        cin >> customNums[i];
    }
    
    cout << "Enter threshold value: ";
    cin >> threshold;
    
    cout << "\nCustom Test Case:" << endl;
    cout << "Smallest Divisor: " << smallestDivisor(customNums, threshold) << endl;
    
    return 0;
}
