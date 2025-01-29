#include<bits/stdc++.h>
using namespace std;
bool searchElement(int arr[], int size, int key){
    for(int i = 0; i<size; i++){
        if(arr[i]==key){
            return true; // will be parsed as 1
        };
    }
    return false; // parsed as 0    
}
int main(){
    int size = 7;
    int nums[7] = {21,23,54,-21,30,12,34};
    int key;
    cout<<"Enter element to search : ";
    cin>>key;
    cout<<searchElement(nums,size,key);

    return 0;
}