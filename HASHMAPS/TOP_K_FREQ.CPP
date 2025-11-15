#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int>> ans(mp.begin(),mp.end());
        sort(ans.begin(),ans.end(),[](auto &a, auto& b){
            return a.second>b.second; // sorts the no of occ. in desc order!
        });

        vector<int> res;
        
        int count = 0;
        for(auto p:ans){
            res.push_back(p.first);
            count++;
            if(count == k){
                break;
            }
           
        }
        return res;
    }
};