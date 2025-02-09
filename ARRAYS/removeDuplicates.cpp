#include <bits/stdc++.h>
using namespace std;

// Optimized Approach (Two Pointer Method) - O(N)
int removeDuplicates(int arr[], int n) {
    int i = 0; // i stores the position of unique elements
    for (int j = 1; j < n; j++) { // j traverses the whole array
        if (arr[j] != arr[i]) {
            arr[i + 1] = arr[j];  
            i++;
        }
    }
    return i + 1; // New size of array with unique elements
}

// Brute Force Approach (Using Set) - O(N log N)
int removeBrute(int arr[], int n) {
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]); // Insert elements into the set
    }

    int arrayIndex = 0;
    for (auto it : st) {
        arr[arrayIndex] = it; // Copy unique elements back to the array
        arrayIndex++;
    }
    
    return arrayIndex; // Return the new size of the array
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5, 6, 6}; // Sorted array with duplicates
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Using Optimized Method:\n";
    int newSize1 = removeDuplicates(arr, n);
    for (int i = 0; i < newSize1; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reset array for brute force test
    int arr2[] = {1, 1, 2, 2, 3, 4, 4, 5, 6, 6}; 
    int newSize2 = removeBrute(arr2, n);

    cout << "Using Brute Force (Set) Method:\n";
    for (int i = 0; i < newSize2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
