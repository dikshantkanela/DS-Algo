#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char ch:s){
            mp[ch]++;
        }

        vector<pair<char,int>> freq(mp.begin(),mp.end()); // copy the map to vector
        
        sort(freq.begin(),freq.end(),[](auto &a, auto &b){
            return a.second>b.second; // sorts characters in desc order;
        });

        string ans = "";

        for(int i=0;i<freq.size();i++){
            ans+=string(freq[i].second,freq[i].first);
        }
        return ans;
    }
};