#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size()) return false;
        
        unordered_map<char,int> mp;

        for(char ch:s){
           if(mp[ch]){
            mp[ch]++;

           }
           else{
            mp[ch] = 1;
           }
        }

        for(char ch:t){
            if(mp.find(ch)!=mp.end()){
                mp[ch]--;
            }

            if(mp.find(ch) == mp.end()){
                return false;
            }

            if(mp[ch]<0){
                return false;
            }

        }
       return true;
    }
};