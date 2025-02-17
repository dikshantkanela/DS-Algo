#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& arr, int m)
{
    // WRITE YOUR CODE HERE.
    int start = 0;
    int n = arr.size();
    int end = n-1;
    int mid = start + (end - start) / 2;
    int ans = n;
    while (start <= end) {
        if (arr[mid] > m) { 
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] == m) { // JUST AN EXTRA CASE IF THE ELEMENT WE ARE SEARCHING ALREADY EXISTS!
            return mid; // IMPROVES EFFICIENCY
        }
        else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 3, 5, 6};
    int m = 5;

    int result = searchInsert(arr, m);
    cout << "Index: " << result << endl; // Index: 2

    m = 2;
    result = searchInsert(arr, m);
    cout << "Index: " << result << endl; // Index: 1

    m = 7;
    result = searchInsert(arr, m);
    cout << "Index: " << result << endl; // Index: 4

    m = 0;
    result = searchInsert(arr, m);
    cout << "Index: " << result << endl; // Index: 0

    return 0;
}
