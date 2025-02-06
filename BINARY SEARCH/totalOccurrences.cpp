#include<bits/stdc++.h>
using namespace std;
int first(int arr[], int size, int key){
    int start=0;
    int end = size-1;
    int mid = start+(end-start)/2;
    int ans = -1;
    while (start<=end){
        if(key==arr[mid]){
           ans = mid;
           end = mid-1; //left bhi dekhna h 
        }
        else if(key>arr[mid]){
           start = mid+1;
        }
        else{
           end = mid-1;
        }
     mid = start + (end-start)/2;
    }
    return ans;
}
int last(int arr[], int size, int key){
    int start=0;
    int end = size-1;
    int mid = start+(end-start)/2;
    int ans = -1;
    while (start<=end){
        if(key==arr[mid]){
           ans = mid;
           start = mid+1; //right bhi dekhna hai
        }
        else if(key>arr[mid]){
           start = mid+1;
        }
        else{
           end = mid-1;
        }
     mid = start + (end-start)/2;
    }
    return ans;
}
int countOccurences(int arr[],int size,int key){
     int res1 = first(arr,size,key);
     int res2 = last(arr,size,key);
     int occurences = res2-res1+1;
     return occurences;
}
int main(){
    int even[6] = {1,1,1,3,4,4}; //sorted array
    int size = 6;
    int key;
    cout<<"Enter the key : ";
    cin>>key;
    cout<<"Number of occurences of "<<key<<" are "<<countOccurences(even,size,key);
    return 0;
}