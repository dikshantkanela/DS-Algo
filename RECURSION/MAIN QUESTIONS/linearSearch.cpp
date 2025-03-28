#include<bits/stdc++.h>
using namespace std;

// =====================================================
// Recursive Linear Search Implementation
// 
// Approach for First to Last Search (linearSearch2):
// 1. Core Strategy: Search by moving forward through the array
// 2. Mechanism:
//    - Start from the first element of the current array
//    - Check if first element matches the target
//    - If not, recursively search the remaining array
// 3. Recursive Call Mechanism:
//    - Move array pointer forward (arr+1)
//    - Reduce array size by 1 in each recursive call
//    - Continues until target is found or array is empty
// 4. Base Cases:
//    - Empty array: return false
//    - Target found at first element: return true
// =====================================================
bool linearSearch2(int arr[], int n, int target){
    // Base case: Empty array means target not found
    if(n == 0){
        return false;
    }

    // Check if first element is the target
    if(arr[0] == target){
        return true;
    }

    // Recursive call: Search in remaining array
    // Move forward by incrementing array pointer and reducing size
    return linearSearch2(arr+1, n-1, target);
}

// =====================================================
// Alternate Recursive Linear Search Implementation
// 
// Approach for Last to First Search (linearSearch):
// 1. Core Strategy: Search by reducing array size from the end
// 2. Mechanism:
//    - Start from the last element of the current array
//    - Check if last element matches the target
//    - If not, recursively search the array with reduced size
// 3. Recursive Call Mechanism:
//    - Reduce array size by 1 in each recursive call
//    - Checks elements from right to left
// 4. Base Cases:
//    - Empty array: return false
//    - Target found at last element: return true
// =====================================================
bool linearSearch(int arr[], int n, int target){
    // Base case: Empty array means target not found
    if(n == 0){
        return false;
    }
    
    // Check if last element is the target
    if(arr[n-1] == target){
        return true;
    }

    // Recursive call: Search in array with reduced size
    // Remove last element in each recursive call
    return linearSearch(arr, n-1, target);
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    
    // Demonstrate both search methods
    bool ans1 = linearSearch(arr, size, 3);     // Last to First Search
    bool ans2 = linearSearch2(arr, size, 3);    // First to Last Search
    
    cout << "Last to First Search Result: " << ans1 << endl;
    cout << "First to Last Search Result: " << ans2 << endl;
    
    return 0;
}