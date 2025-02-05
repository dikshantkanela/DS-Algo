#include<bits/stdc++.h>
using namespace std;

int main(){
    int nums[10] ={21,32,43,54,67,22,65,63,22,23}; 
    int start = 3;
    int end = 7;
    int target;
    cout<<"Enter element to search : ";
    cin>>target;
    bool found = false;
    int foundIndex = -1;
    for(int i = start ;i<=end ;i++){
       if(nums[i] == target){
          foundIndex = i;
          found = true;
       }
       
    }
    if(found){
        cout<<"Element found at index : "<<foundIndex;
    }
    else{
        cout<<"Element not found!";
    }
    return 0;
}