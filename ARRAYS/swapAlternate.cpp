#include<bits/stdc++.h>
using namespace std;
void swapAlternate(int arr[], int size){
    for(int i=0;i<size;i=i+2){
       if((i+1)<size){ //ENSURE THE NEXT NUMBER IS IN THE ARRAY OR NOT! // A case for not going out of index for odd elements
       int temp = arr[i]; // SWAP LOGIC
       arr[i] = arr[i+1];  // WILL FAIL FOR LAST INDEX IN CASE OF ODD
       arr[i+1] = temp;
    }
    //0 1 2 3 4 [len = 5 --> i=4==>ele=4, i+1=5==> ele = (nothing!), therefore i+1<size]
    }
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<' ';
    }
}

int main(){
    int even[6] = {21,23,34,44,55,66};
    int odd[5] = {21,23,34,44,55};
    swapAlternate(even,6);
    swapAlternate(odd,5);
    printArray(even,6);
    cout<<endl;
    printArray(odd,5);
    return 0;
}