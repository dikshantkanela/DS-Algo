#include <iostream>
#include <vector>
using namespace std;
// LOGIC IS TO FIND THE PIVOT (LOWEST ELEMENT) AND THEN PERFORM BINARY SEARCH ON LEFT AND RIGHT SIDES OF ARRAY
int findPivot(vector<int>& arr, int n) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    // JAB ARRAY MAI DUPLICATES NA HO TO PIVOT NIKAALNA EASY HAI
    while (start < end) {
        if (arr[mid] >= arr[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;  // Pivot index (you cam return both start or end ans will be same)
}

int binarySearch(vector<int>& arr, int start, int end, int k) {
    int mid = start + (end - start) / 2;
    
    while (start <= end) {
        if (arr[mid] == k) {
            return mid;  // Element found   
        } else if (k > arr[mid]) {
            start = mid + 1;  // Search in the right part
        } else {
            end = mid - 1;  // Search in the left part
        }
        mid = start + (end - start) / 2;
    }
    return -1;  // Element not found
}

int search(vector<int>& arr, int n, int k) {
    // Find the pivot index (smallest element)
    int pivotElementIndex = findPivot(arr, n);

    // If the element is in the right part of the rotated array 
    if (k >= arr[pivotElementIndex] && k <= arr[n - 1]) {
        return binarySearch(arr, pivotElementIndex, n - 1, k);
    }
    // If the element is in the left part of the rotated array
    else {
        return binarySearch(arr, 0, pivotElementIndex , k);
    }
}

int main() {
    vector<int> arr = {10, 12, 15, 2, 1, 5, 6};
    int k = 5;

    int result = search(arr, arr.size(), k); //MAIN IS THIS
    
    if (result != -1) {
        cout << "Element " << k << " is found at index: " << result << endl;
    } else {
        cout << "Element " << k << " is not found in the array." << endl;
    }

    return 0;
}
