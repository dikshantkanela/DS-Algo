#include<bits/stdc++.h>
using namespace std;
int findUnique(int *arr, int size)
{
    
    for(int i = 0; i<size;i++){
        int extraCount = 0;
        for(int j = 0; j<size;j++){
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
int main(){
    int arr[5] = {2,2,2,3,4};
    cout<<findUnique(arr,5);
    return 0;
}