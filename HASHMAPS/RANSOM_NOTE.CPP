#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(int i=0;i<ransomNote.length();i++){
            mp[ransomNote[i]]++;
        }

        for(int i=0;i<magazine.length();i++){
            if(mp[magazine[i]]>0){
                mp[magazine[i]]--;
            }
        }

        for(auto p:mp){
            if(p.second !=0){
                return false;

            }
        }
        return true;
    }
};