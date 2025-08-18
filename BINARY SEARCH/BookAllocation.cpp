#include <bits/stdc++.h>
using namespace std;

/*
Approach:
We want to allocate n books to m students such that the maximum number of pages 
assigned to a student is minimized.

Steps:
1. Define search space:
   - Lowest possible = 0
   - Highest possible = sum of all book pages
2. Use Binary Search on this range to find the minimum feasible max pages.
3. Feasibility check is done by isAllocationPossible().
*/

bool isAllocationPossible(vector<int>& arr, int n, int m, int mid){
    int pageSum = 0;        // pages allocated to current student
    int studentCount = 1;   // start with first student

    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){   
            // give this book to current student
            pageSum += arr[i];
        }
        else{
            // allocate book to next student
            studentCount++;

            // if we need more students than available OR one book > mid, fail
            if(studentCount > m || arr[i] > mid){
                return false;
            }

            pageSum = arr[i];  // new student starts with this book
        }
    }
    return true; // allocation possible
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n){ // more students than books
        return -1;
    }

    int start = 0;
    int end = 0; // maximum possible = sum of all pages
    int ans = -1;

    for(int i=0; i<n; i++){
        end += arr[i];
    }

    // binary search
    while(start <= end){
        int mid = start + (end-start)/2;

        if(isAllocationPossible(arr,n,m,mid)){
            // valid allocation → try smaller max
            ans = mid;
            end = mid - 1;
        }
        else{
            // invalid allocation → increase limit
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {12, 34, 67, 90}; // Example book pages
    int n = arr.size();
    int m = 2; // Number of students

    cout << "Minimum pages a student has to read: " 
         << findPages(arr, n, m) << endl;

    // EXPECTED OUTPUT = 113
    // Explanation: 
    // Student 1 → {12, 34, 67} = 113
    // Student 2 → {90} = 90
    // Minimum possible maximum pages = 113
    return 0;
}
