#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int n, int k, int mid) {
    int cowCount = 1; // First cow is placed at the first stall
    int prevPosition = stalls[0];

    for (int i = 0; i < n; i++) {
        if (stalls[i] - prevPosition >= mid) { 
            cowCount++; // Place next cow
            if (cowCount == k) { 
                return true; // Successfully placed all cows
            }
            prevPosition = stalls[i]; // Update last placed cow's position
        }
    }
    return false; // Couldn't place all cows with given min distance
}

int aggressiveCows(vector<int> &stalls, int k) {
    // Sort stall positions to ensure a logical placement order
    sort(stalls.begin(), stalls.end());
    
    int n = stalls.size();
    int start = 0;
    
    // Find the maximum stall position
    int maxi = -1;
    for (int i = 0; i < n; i++) {
        if (stalls[i] > maxi) {
            maxi = stalls[i];
        }
    }
    int end = maxi; // Maximum possible distance
    int mid = start + (end - start) / 2;
    int ans = -1;

    // Binary search to find the largest minimum distance
    while (start <= end) {
        if (isPossible(stalls, n, k, mid)) {
            ans = mid; // Store possible answer
            start = mid + 1; // Try for a larger min distance
        } else {
            end = mid - 1; // Reduce search space
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
