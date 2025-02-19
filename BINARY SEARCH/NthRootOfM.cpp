#include <bits/stdc++.h>
using namespace std;

// Function to check if mid^n is equal, greater, or less than m
int checkPower(int mid, int n, int m) {
    long long ans = 1;
    
    for (int i = 0; i < n; i++) {
        ans *= mid;
        if (ans > m) return 2; // mid^n exceeds m
    }
    
    if (ans == m) return 1; // mid^n equals m
    return 0; // mid^n is less than m
}

int NthRoot(int n, int m) {
    int start = 1, end = m;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int result = checkPower(mid, n, m);

        if (result == 1) return mid;  // Found the exact Nth root
        else if (result == 2) end = mid - 1;  // Reduce search space
        else start = mid + 1;  // Increase search space
    }
    return -1; // No integer Nth root found
}

int main() {
    int n = 5, m = 32768;
    cout << "The " << n << "th root of " << m << " is: " << NthRoot(n, m) << endl;
    return 0;
}
