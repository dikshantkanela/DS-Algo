#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Brute-force approach (O(n^2))
    int maxProfitBruteForce(vector<int>& arr) {
        int maximum = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                maximum = max(arr[j] - arr[i], maximum);
            }
        }

        return maximum;
    }

    // Optimized approach (O(n)) - kadane
    int maxProfitOptimized(vector<int>& arr) {
        int minSoFar = arr[0];
        int maxProfit = 0;

        for (int i = 1; i < arr.size(); i++) {
            maxProfit = max(maxProfit, arr[i] - minSoFar);
            minSoFar = min(minSoFar, arr[i]);
        }

        return maxProfit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;

    cout << "Prices: ";
    for (int price : prices) cout << price << " ";
    cout << endl;

    cout << "Maximum Profit (Brute Force): " << sol.maxProfitBruteForce(prices) << endl;
    cout << "Maximum Profit (Optimized): " << sol.maxProfitOptimized(prices) << endl;

    return 0;
}
