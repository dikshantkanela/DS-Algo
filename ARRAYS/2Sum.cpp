#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>> ans;
    
    int i = 0;
    while(i<arr.size()){
       int j = i+1;
       while(j<arr.size()){
          if(arr[i]+arr[j] == s){
             vector<int> temp;
             temp.push_back(min(arr[i],arr[j])); // ensure we are pushing in asc order in the pair
             temp.push_back(max(arr[i],arr[j]));
             ans.push_back(temp);
          }
          j++;
       }
       i++;
    }
    
   sort(ans.begin(),ans.end()); // give answer pairs in sorted order [1,4],[2,3]....
   return ans;
}
int main(){
    vector<int> arr = {1, 3, 2, 5, 4, 6};
    int s = 5;
    
    vector<vector<int>> result = pairSum(arr, s);
    
    for (auto pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "]\n";
    }
    return 0;
}