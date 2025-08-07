#include<bits/stdc++.h>
using namespace std;
 void bubbleSort(int arr[], int n) {
        // code here
        for(int i=0;i<n-1;i++){
            bool swapped = false;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swapped = true;
                }
            }
            if(!swapped){
                break;
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