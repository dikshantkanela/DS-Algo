#include<bits/stdc++.h>
using namespace std;
int first(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(key == arr[mid]){
          ans = mid; //for 1st occurrence 
          end = mid-1; //kya pata uske left me ho aur same elements //for 1st occurrence 
          
        }
        else if(key>arr[mid]){ //right mein jao
            start = mid+1;
        }
        else{  //left mein jao 
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}
int last(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(key == arr[mid]){
          ans = mid; //for last occurrence 
          start = mid+1; //kya pata uske right me ho aur same elements //for last occurrence 
          
        }
        else if(key>arr[mid]){ //right mein jao
            start = mid+1;
        }
        else{  //left mein jao 
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}
int main(){
    int odd[5] = {2,2,2,2,5};
    cout<<"First occurence of 2 is : "<< first(odd,5,2)<<endl;
    cout<<"Last occurence of 2 is : "<< last(odd,5,2);
    return 0;
}