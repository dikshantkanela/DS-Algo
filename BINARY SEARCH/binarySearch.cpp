#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int size, int key){
     int start = 0;
     int end = size-1;
     int mid = start + (end-start)/2; //becomes (start+end)/2
     while(start<=end){
        if(key == arr[mid]){
            return mid; //return the index where the key matches with the mid
        }
        if(key>arr[mid]){
            start = mid+1; //for splitting and searching in the right subarray

        }
        else{   
            end = mid-1;  //for splitting and searching in the left subarray
        }
        mid = start + (end-start)/2;
     }
    return -1; //if key not found in array
}
int main(){
    int odd[7] = {12,23,26,30,45,50,67};
    int even[6] = {2,10,15,22,31,67};
    int key;
    cin>>key;
    //search in odd array
    int oddRes = binarySearch(odd,7,key);
    cout<< key << " found at index : "<<oddRes<<endl; 
    //search in even array
    int evenRes = binarySearch(even,6,key);
    cout<< key << " found at index : "<<evenRes; 
    return 0;
}