#include<bits/stdc++.h>
using namespace std;


// ya to start stop bhej de ya size!
int binarySearch(int* arr, int start, int end, int key){
    if(start>end){
        return -1; // means element index not found
    }

    int mid = start+(end-start)/2;
    if(arr[mid] == key){
        return mid;
    }

    if(arr[mid]<key){
        return binarySearch(arr,mid+1,end,key);
    }

    else{
       return binarySearch(arr,0,mid-1,key);
    }


   
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int start = 0;
    int end = size-1;
    cout<<binarySearch(arr,start,end,6);
    return 0;
}