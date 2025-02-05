#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n){
    for(int i=0;i<n;i++){
       for(int j=i ; j>0&&arr[j]<arr[j-1] ; j--){ // WHILE STANDING AT ZERO WE COMPARE THE LEFT ELEMENT THATS WHY WE DONT DO >=0
          swap(arr[j],arr[j-1]);
       }
    }
}
int main(){
    int nums[7];
    int size = 7;
    for(int i=0;i<size;i++){
        cin>>nums[i];
    }
    insertionSort(nums,size);
    for(int i=0;i<size;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}