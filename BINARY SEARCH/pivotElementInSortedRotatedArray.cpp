#include<bits/stdc++.h>
using namespace std;
int pivotElement(int arr[], int size){
     int start = 0;
     int end = size-1;
     int mid = start+(end-start)/2;
        while(start<end){
            if(arr[mid]>=arr[0]){ //MEANS WE ARE ON THE FIRST LINE
                start = mid+1;
            }

            else{
                end = mid;  //MEANS WE ARE ON THE FIRST LINE
            }
        mid = start+(end-start)/2;
        }
    return min(arr[start],arr[0]); // INCASE OF NO PIVOT ELE [11,13,15,17]
}


int main(){
    int size = 5;
    int rotated[5] = {7,9,1,2,3};
    int pivot = pivotElement(rotated,size);
    cout<<"The pivot element of array is : "<<pivot;
    return 0;
}