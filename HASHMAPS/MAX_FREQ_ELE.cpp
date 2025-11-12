#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

int maximumFrequency(vector<int> &arr, int n)
{
    // if any two elements have same freq, return the one that comes first in the array!
    unordered_map<int,int> mp;
    int maxFreq = 0;
    
    for(int num : arr){
        mp[num]++; // hashmap is ready
        maxFreq = max(maxFreq,mp[num]);
    }

    int maxEle = -1;

    for(int i=0;i<arr.size();i++){
        if(maxFreq == mp[arr[i]]){
            maxEle = arr[i];
            break;
        }
    }

    return maxEle;


    
    
}
