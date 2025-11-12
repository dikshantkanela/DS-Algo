
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    
    unordered_map<int,int> mp;
    
    int n = a.size();
    int maxLen = 0;
    int currSum = 0;

    for(int i=0;i<n;i++){
        currSum+=a[i];

        if(mp.find(currSum) == mp.end()){ // so that we get the longest array if the prefix sum repeats
            mp[currSum] = i;
        }

        if(currSum == k){
            maxLen = max(maxLen,i); // anyways it would be i
        }

        

        int remove = currSum - k;

        if(mp.find(remove)!=mp.end()){
            maxLen = max(maxLen,i-mp[remove]);
        }

       


    }
    return maxLen;
    
}


int twoPointers(vector<int> arr, long long k) {
    // Write your code here
    
    int right = 0;
    int left = 0;
    int n = arr.size();
    int currSum = 0;
    int maxLen = 0;

    while(right<n){
        currSum+=arr[right];

        while(left<=right && currSum>k){
            currSum-= arr[left];
        }


        if(currSum == k){
            maxLen = max(maxLen,right-left+1);
        }

        
        right++;
    }

    return maxLen;
    
}