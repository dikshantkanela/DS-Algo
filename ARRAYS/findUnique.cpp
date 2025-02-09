#include<bits/stdc++.h>
using namespace std;

int findUniqueBruteForce(int *arr, int size)
{
    
    for(int i = 0; i<size;i++){
        int extraCount = 0;
        for(int j = 0; j<size;j++){ // cannot do j = i+1 because agar piche hua same element toh?
           if(i!=j && arr[i]==arr[j]){
               extraCount++;
               break;
           }
        }
        if(extraCount == 0){
            return arr[i];
        }
    }
    return -1;
}

int findUniqueOptimise(int arr[], int size){ // can be optimised by takig xor, only the unique element will be left,rest all the elements will get cancelled due to xor operation
     int res = 0;
     for(int i=0;i<size;i++){
        res = res ^ arr[i]; 
     }
    return res;
}

int main(){
    int arr[7] = {2, 3, 1, 6, 3, 6, 2}; 
    cout<<findUniqueBruteForce(arr,7);
    cout<<endl;
    cout<<findUniqueOptimise(arr,7);

    return 0;
}