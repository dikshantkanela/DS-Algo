#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int size){
     for(int i=0;i<size-1;i++){ //sirf last element ke liye nahi chala rahe! vo already sort hoga
       int minimum = i;
       for(int j=i;j<size;j++){
          if(arr[j]<arr[minimum]){
            minimum = j;
           
          }
       }
        swap(arr[i],arr[minimum]);
      
     }
}
int main(){
    int nums[7];
    int size = 7;
    for(int i=0;i<size;i++){
        cin>>nums[i];
    }
    selectionSort(nums,size);
    for(int i=0;i<size;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}