#include<bits/stdc++.h>
using namespace std;
int secondMax(int arr[], int size){
    int max = INT_MIN;
    int nextMax;
    for(int i = 0 ;i < size; i++){
        if(arr[i] > max){
            nextMax = max;
            max = arr[i];
            
        }
        else if(arr[i] < max && arr[i] > nextMax){
            nextMax = arr[i];
        }
    }
    return nextMax;
}

int main(){
    int arr[7] = {22,13,14,21,43,54,21};
    int size = 7;
    cout<<secondMax(arr,size);
    return 0;
}