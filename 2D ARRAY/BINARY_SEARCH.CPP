#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5] = {10,20,30,40,50};
    int n = 5;
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;
    int key;
    cout<<"Enter key to search : ";
    cin>>key;
    int flag = -1;

    while(start<=end){
        
        if(key == arr[mid]){
            cout<<"Element found at index : "<<mid;
            flag = 1;
            break;
        }           
        if(key>arr[mid]){
            start = mid+1;
        }
        else{
            end = mid;
        }
        mid = start+(end-start)/2;
    }
    cout<<endl; 
    cout<<(flag == 1?"Element was found":"Element was not found!");
    return 0;
}