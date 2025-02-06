#include<bits/stdc++.h>
using namespace std;
int peakMountain(int arr[], int size){
    int start = 0;
    int end = size-1;
    int mid = start+(end-start)/2;
   
    while(start<=end){ //jab start = end hua to baar baar repeat ho jayega process isliye only start<end
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            return mid;
        }
        else if(arr[mid]>arr[mid-1]){ //we are in process of climbing the top
            start = mid+1;
        }

        else{ // we are below the top 
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
   return mid;
}


int main(){
    int mountain[5] = {1,3,4,5,1};
    int size = 5;
    int peakElement = peakMountain(mountain,size);
    cout<<mountain[peakElement];
    return 0;
}