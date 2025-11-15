#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for(int i=0;i<strs.size();i++){
            string current = strs[i]; 

            sort(current.begin(),current.end());           
            mp[current].push_back(strs[i]);
            
        }

        vector<vector<string>> ans;
        for(auto &p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};