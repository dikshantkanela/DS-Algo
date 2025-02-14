
#include<bits/stdc++.h>
using namespace std;

int bruteForce(int arr[], int n){
    int maximum = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<j;k++){
                sum+=arr[k];
                maximum = max(sum,maximum); // YAHI PAR HAR SUBARRAY KA SUM COMPARISON HOKE MAXIMUM UPDATE HO RHA HAI
            }
        }
    }
    return maximum;
}

int betterApproach(int arr[], int n){
    int maximum = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){ //INSTEAD OF CREATING EACH SUBARRAY AND THEN TAKING THE SUM, JUST KEEP ON SUMMING THE ELEMENTS AND THEN COMPARE SUM WITH THE CURRENT MAXIMUM SUM! 
          sum+=arr[j];
          maximum = max(sum,maximum);
        }
    }
  return maximum;
}
int main(){
    int arr[8] = {-2,-3,4,-1,-2,1,5,-3};
    int size = 8;
    cout<<"Through brute force : " << bruteForce(arr,size)<<endl;
    cout<<"Through better approach : "<< betterApproach(arr,size)<<endl;
    return 0;
}