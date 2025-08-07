#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n) {
        // code here
        for(int i=0;i<n;i++){
            int j = i;
            while(j>0 && arr[j-1]>arr[j]){
             
                    swap(arr[j],arr[j-1]);
            
                j--;
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