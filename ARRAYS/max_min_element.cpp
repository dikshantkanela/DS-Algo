#include<bits/stdc++.h>
using namespace std;
int getMin(int arr[],int size){
    int min = arr[0];
    for(int i = 1;i<size;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}
int getMax(int arr[], int size){
    int max = arr[0];
    for(int i =1 ;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int names[100];
    int size;
    cout<<"Enter array size : ";
    cin>>size;
    //INPUT
    for(int i = 0; i<size; i++ ){
        cin>>names[i];
    }
    // Output maximum and minimum values
    cout << "Maximum: " << getMax(names, size) << endl;
    cout << "Minimum: " << getMin(names, size) << endl;
    return 0; 
}