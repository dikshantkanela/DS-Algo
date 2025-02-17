#include <bits/stdc++.h>
using namespace std;
// UPPER BOUND MEANS FIND the lowest index i such that arr[i] > x
int upperBound(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    int ans = n;

    while (low <= high) {
        if (arr[mid] > x) {
            ans = mid; // THIS MAY OR MAY NOT BE THE ANSWER SO JUST STORE IT!
            high = mid - 1;
        } 
        else {  // FOR arr[mid] <= x;
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return ans;
}

int main() {
    // vector<int> arr = {1, 3, 5, 6, 8, 10};
    // int n = arr.size();
    // int x;
    
    // cout << "Enter the value of x: ";
    // cin >> x;

    // int result = upperBound(arr, n, x);
    // cout << "Upper bound index: " << result << endl;

    // using STL+VECTOR : 
    vector <int> nums = {10,20,30,40,50};
    auto it1 = upper_bound(nums.begin(),nums.end(),30); // ITERATOR/POINTER
    int ub1 = it1 - nums.begin(); // 3
    cout << ub1 << endl;

    auto it2 = upper_bound(nums.begin()+1, nums.end()-1, 30); // FIND UB IN A RANGE
    int ub2 = it2 - nums.begin(); // 3
    cout << ub2 << endl;

    // USING STL+ARRAY : 
    int arr[7] = {10, 20, 30, 30, 40, 40, 50};
    int n = sizeof(arr) / sizeof(int);
    
    auto it3 = upper_bound(arr, arr + n, 30);
    int ub3 = it3 - arr;
    cout << ub3;  // 4

    return 0;
}
