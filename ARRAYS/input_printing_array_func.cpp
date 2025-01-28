#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int size){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

void inputArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}

int main(){
    int numbers[5] = {10,20,30,40,50};
    int size = sizeof(numbers)/sizeof(int); // 20/4 = 5
    printArray(numbers,size);
    // DIFF TYPES OF ARRAY : 
    char charArray[5] = {'a','b','c','d','e'};
    float floatArray[3] = {3.3,2,1.0};
    int arr[5];
    inputArray(arr,5);
    printArray(arr,5);
    return 0;
}