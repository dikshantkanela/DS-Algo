#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to check if the array contains any duplicates
bool containsDuplicate(vector<int>& arr) {
    unordered_set<int> seen; // Set to store unique elements

    for (int num : arr) {
        // If the number already exists in the set, it's a duplicate
        if (seen.count(num)) {
            return true;
        }
        // Otherwise, insert it into the set
        seen.insert(num);
    }

    // If no duplicates were found
    return false;
}

// Main function to test the code
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};  // Try changing this to {1, 2, 3, 1}
    
    // Call the function and print the result
    if (containsDuplicate(nums)) {
        cout << "Duplicate exists in the array." << endl;
    } else {
        cout << "All elements are unique." << endl;
    }

    return 0;
}
