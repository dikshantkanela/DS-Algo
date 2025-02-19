#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. Use Binary Search to find the minimum maximum number of pages a student has to read.
2. Initialise the search space: 
   - Start from 0 
   - End as the sum of all pages.
3. Use isPossible() to check if the mid value can be a valid allocation.
4. Adjust search space based on whether allocation is possible or not.
*/

bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int pageSum = 0;
    int studentCount = 1;

    for(int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
         else {
            studentCount++;
            if (studentCount > m || arr[i] > mid) {
                return false; // ALLOCATION NOT POSS CUZ OF EITHER THE studentCount exceeded or any element of array exceeds the mid
            }
            pageSum = arr[i];
        }
    }
    return true; // Allocation possible
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1; // More students than books, not possible

    int start = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int end = sum;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end) {
        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1; // Try for a smaller max allocation
        } else {
            start = mid + 1; // Increase max allocation limit
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main() {
    vector<int> arr = {12, 34, 67, 90}; // Example book pages
    int n = arr.size();
    int m = 2; // Number of students
    cout << "Minimum pages a student has to read: " << findPages(arr, n, m) << endl;
    return 0;
}
