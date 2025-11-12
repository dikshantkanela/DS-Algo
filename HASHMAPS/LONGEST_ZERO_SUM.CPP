#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    unordered_map<int,int> mp;
    int n = arr.size();
    int maxLen = 0;
    int currSum = 0;

    for(int i=0;i<n;i++){
       currSum+=arr[i];

       if(mp.find(currSum) == mp.end()){
         mp[currSum] = i;
       }


       if(currSum == 0){
         maxLen = max(maxLen,i+1);
       }

       int remove = currSum - 0;

       if(mp.find(remove)!=mp.end()){
         maxLen = max(maxLen,i-mp[remove]);
       }
        
       
        
    }
    return maxLen;

}