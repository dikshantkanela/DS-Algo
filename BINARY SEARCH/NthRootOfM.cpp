#include <bits/stdc++.h>
using namespace std;

// Function to check if mid^n is equal, greater, or less than m
class Solution {
  public:
    int nthRoot(int n, int m) {
    
        int start = 0;
        int end = m;
        long int mid = start+(end-start)/2;
        
        while(start<=end){
            long int sq = pow(mid,n);
            if(sq>m){
                end = mid-1;
            }
            else if(sq<m){
                start = mid+1;
            }
            
            else{
                return mid;
            }
             mid = start+(end-start)/2;
        }
    return -1;    // return -1 if the root is not integer
    }
};
