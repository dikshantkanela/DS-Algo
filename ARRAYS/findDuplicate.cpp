#include <bits/stdc++.h>
using namespace std;

int findDuplicateBrute(int arr[], int size) 
{
    for(int i = 0; i <size; i++){
        int count = 0;
        for(int j = 0; j < size; j++){
            if(i != j && arr[i] == arr[j]){
                count++;
                return arr[j];
            }
        }
    }
    return -1;
}

int findDuplicateOptimise(int arr[], int size){
    int res = 0;
    for(int i = 0; i<size;i++){
       res = res^arr[i];
    }
    for(int i = 1; i<size;i++){  //IF ARRAY SIZE IS 5, THEN IT WILL XOR WITH ELEMENTS 1,2,3,4, THE ONE THAT DOES NOT CANCEL OUT WILL BE THE DUPLICATE ONE!
        res = res^i;
    }     
    return res;
}

int main() {
    
    int arr[5];
    cout << "Enter the array elements: ";
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int duplicateBrute = findDuplicateBrute(arr,5);
    cout<<duplicateBrute<<endl;
    int duplicateOptimise = findDuplicateOptimise(arr,5);
    cout<<duplicateOptimise;
    return 0;
}
