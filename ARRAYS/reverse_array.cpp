#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[],int size){
    int start = 0;
    int stop = size-1;
    while(start<stop){ // TWO POINTER APPROACH
       int temp = arr[start];
       arr[start] = arr[stop];
       arr[stop] = temp;
       start++;
       stop--;
    }

}

void printArray(int arr[],int size){
    for(int i = 0 ;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int nums[5] = {1,2,3,4,5};
    int grades[6] = {76,34,90,98,65,87};
    reverse(nums,5);
    printArray(nums,5);
    cout<<endl;
    reverse(grades,6);
    printArray(grades,6);
    return 0;
}