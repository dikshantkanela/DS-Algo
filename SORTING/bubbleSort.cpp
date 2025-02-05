#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n){
    for(int i = n-1; i>=1; i--){ // start from the last element and end till the 1 index element (right se kaatni hai array), 0 already hoga
        bool swapped = false;
        for(int j = 0; j<=i-1; j++){ //compare from 0 index will the i-1 th element (not ith because it will then compare i+1 which will be out of array)
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true; 
            }
        }
        if(!swapped){
           break; // IF NO SWAPPING HAPPENS THAT MEANS THE ARRAY IS ALREADY SORTED!
        }
    }
}
int main(){
    int nums[7];
    int size = 7;
    for(int i=0;i<size;i++){
        cin>>nums[i];
    }
    bubbleSort(nums,size);
    for(int i=0;i<size;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}