#include <iostream>
#include <vector>
using namespace std;

// ---------------- Approach 1: Left + Right Arrays ----------------
vector<int> productExceptSelf_LeftRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n), left(n), right(n);

    left[0] = 1;
    right[n-1] = 1;

    // Fill right array
    for (int i = n-2; i >= 0; i--) {
        right[i] = right[i+1] * nums[i+1];
    }

    // Fill left array
    for (int i = 1; i < n; i++) {
        left[i] = left[i-1] * nums[i-1];
    }

    // Final result: multiply left and right
    for (int i = 0; i < n; i++) {
        ans[i] = left[i] * right[i];
    }

    return ans;
}

// ---------------- Approach 2: Optimized with Right Product ----------------
vector<int> productExceptSelf_Optimized(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = 1; // just to fit the logic of  ans[i] = ans[i-1]*nums[i-1]; for i=1

    // First pass: build left product directly in ans[]
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i-1] * nums[i-1];
    }

    // Second pass: multiply with right product
    int rightProduct = 1;
    for (int i = n-1; i >= 0; i--) {
        ans[i] = ans[i] * rightProduct;
        rightProduct *= nums[i];
    }

    return ans;
}

// ---------------- Main Function ----------------
int main() {
    vector<int> nums = {1, 2, 3, 4};

    // Approach 1: Left+Right Arrays
    vector<int> result1 = productExceptSelf_LeftRight(nums);
    cout << "Approach 1 (Left+Right): ";
    for (int x : result1) cout << x << " ";
    cout << endl;

    // Approach 2: Optimized
    vector<int> result2 = productExceptSelf_Optimized(nums);
    cout << "Approach 2 (Optimized): ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    return 0;
}
