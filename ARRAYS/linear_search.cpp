#include<bits/stdc++.h>
using namespace std;
bool searchElement(int arr[], int size, int key){
    for(int i = 0 ; i<size; i++){
        if(arr[i]==key){
            return true; 
        } 
    }
    return false;
}
int main(){
    int arr[7] ={3,23,21,32,43,45,65};
    int size = 7;
    int target;
    cout<<"Enter element to search for : ";
    cin>>target;
    cout<< searchElement(arr,size,target);
    

    return 0;
}