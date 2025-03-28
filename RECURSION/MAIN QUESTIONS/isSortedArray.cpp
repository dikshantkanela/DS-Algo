#include<bits/stdc++.h>
using namespace std;
// LAST TO FIRST SEARCHING 
bool checkSorted(int arr[], int n){

    if(n == 0 || n == 1){ // if we have reached here means our condition below has failed and all elements are sorted 
        return true;
    }
    if(arr[n-1]<arr[n-2]){ // n-1 because we cant have arr[n]
        return false; // if the codition passes means the array is not sorted!
    }
    bool ans = checkSorted(arr, n-1);
    return ans;
}

int main(){
    int arr[5] = {-1,1,2,3,4};
    int size = 5;
    cout<<(checkSorted(arr,size)?"Sorted":"Not sorted");
    return 0;
}