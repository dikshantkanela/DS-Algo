#include<bits/stdc++.h>
using namespace std;
// LAST TO FIRST SEARCHING 
int getSum(int arr[], int n){
    // base case : if no elements left that means sum is 0 
    if(n == 0){
        return 0;
    }
    // Recursive relaton : last element + sum of all previous element 
    int ans = arr[n-1]+getSum(arr,n-1);
    return ans;

}


int main(){
    int arr[5] = {1,2,3,4,5};
    int n = 5;
    cout<< getSum(arr,n);
    return 0;
}