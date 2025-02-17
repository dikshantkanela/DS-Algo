#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    int start = 0, end = x;
    int ans = -1; 
    long long mid = start + (end - start) / 2; // Avoid overflow
    while (start <= end) {
        
        long long sq = mid * mid;

        if (sq > x) {
            end = mid - 1;
        } 
        else if (sq < x) { // Mid is a potential answer
            ans = mid;
            start = mid + 1;
        } 
        else {
            return mid; // Perfect square found
        }
        mid = start+(end-start)/2;    
    }
    return ans; 
}

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Square root (integer part): " << mySqrt(x) << endl;
    return 0;
}
