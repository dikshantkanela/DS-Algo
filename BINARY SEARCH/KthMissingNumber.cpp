#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach - O(N)
int findKthPositiveBruteForce(vector<int>& arr, int k) {
    for (int i = 0; i < arr.size(); i++) {
        if (k >= arr[i]) {
            k++; // Shift k forward if it exists in arr
        } else {
            break; // Found the missing number position
        }
    }
    return k;
}

// Binary Search Approach - O(log N)
int findKthPositiveBinarySearch(vector<int>& arr, int k) {
    int start = 0, end = arr.size() - 1;
    int mid;
    
    while (start <= end) {
        mid = start + (end - start) / 2;
        int numberOfCurrentMissingNumbers = arr[mid] - (mid + 1); // finds Missing numbers till arr[mid]

        if (numberOfCurrentMissingNumbers < k) {
            start = mid + 1; // Move right if the current missing numbers are lesser than the kth given that we need to have!
        } else {
            end = mid - 1; // Move left
        }
    }
    return start + k; // When start exceeds end, return k-th missing number
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11}; 
    int k = 5;

    cout << "Brute Force Result: " << findKthPositiveBruteForce(arr, k) << endl;
    cout << "Binary Search Result: " << findKthPositiveBinarySearch(arr, k) << endl;

    return 0;
}
