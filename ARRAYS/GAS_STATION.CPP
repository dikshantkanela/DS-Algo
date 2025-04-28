#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;   // Current fuel balance
        int deficit = 0;   // Total fuel shortage encountered so far
        int start = 0;     // Starting gas station index

        for (int i = 0; i < gas.size(); i++) {
            balance += gas[i] - cost[i]; // Update balance after visiting station i

            // If balance goes negative, we cannot reach station i+1 from current start
            if (balance < 0) {
                deficit += balance;     // Add current negative balance to deficit
                balance = 0;             // Reset balance
                start = i + 1;           // Set new start point
            }
        }

        // If total gas >= total cost, trip is possible
        if (balance + deficit >= 0) {
            return start;
        } else {
            return -1; // Otherwise, no solution
        }
    }
};

int main() {
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};        // Example gas at each station
    vector<int> cost = {3, 4, 5, 1, 2};       // Example cost to next station

    int result = sol.canCompleteCircuit(gas, cost);
    
    if (result != -1) {
        cout << "Start at gas station index: " << result << endl;
    } else {
        cout << "It is not possible to complete the circuit." << endl;
    }

    return 0;
}
