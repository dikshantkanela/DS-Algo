#include<bits/stdc++.h>
using namespace std;
int getSum(int arr[], int size){
    int sum = 0;
    for(int i = 0 ; i<size;i++){
        sum+= arr[i];
    }
    return sum;
}
int main (){
    int numbers[100];
    int n;
    cout<<"Enter array size : ";
    cin>>n;
 
    cout<<"Enter array Elements : ";
    for(int i = 0; i<n ; i++){
        cin>>numbers[i];
    }
    int sum = getSum(numbers,n);
    cout<<sum;
    return 0;
}