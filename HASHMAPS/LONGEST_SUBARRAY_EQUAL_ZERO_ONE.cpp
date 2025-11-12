#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         unordered_map<int,int> mp;
         int n = nums.size();
         int currSum = 0;
         int maxLen = 0;

         for(int i=0;i<n;i++){
             if(nums[i] == 1){
                currSum++;
             }
             else if(nums[i] == 0){
                currSum--;
             }

             if(currSum == 0){
                maxLen = max(maxLen,i+1);
             }

             if(mp.find(currSum)!=mp.end()){
                maxLen = max(maxLen,i-mp[currSum]);
             }

             if(mp.find(currSum) == mp.end()){
                mp[currSum] = i;
             }


         }
         return maxLen;
    }
};