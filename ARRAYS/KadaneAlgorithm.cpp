
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

int KadaneAlgo(int arr[], int n){
    int maximum = INT_MIN;
    int currSum = 0;
     
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        maximum = max(currSum,maximum);
        if(currSum<0){
            currSum = 0;
        }
        
        
    }
  return maximum;
}

vector<int> startEndOfMaxSubarray(int arr[],int n){
    int maximum = INT_MIN;
    int currSum = 0;
    int s = -1;
    int e = -1;
    
    for(int i=0;i<n;i++){

        if(currSum==0){ //JUST ADD THIS CONDN INITIALLY!
            s = i;
        }
        
        currSum+=arr[i]; // UPDATE CURRENT SUM

        
        if(currSum>maximum){
            maximum = currSum;  //COMPARING WITH MAXIMUM SUM
            e = i;
        }
        if(currSum<0){
            currSum = 0;  //RESET CURRENT SUM IF EQUAL TO 0
        }
    }

    vector<int> res = {s,e};

    return res;
}
int main(){
    int arr[8] = {-2,-3,4,-1,-2,1,5,-3};
    int size = 8;
    cout<<"Through brute force : " << bruteForce(arr,size)<<endl;
    cout<<"Through better approach : "<< betterApproach(arr,size)<<endl;
    cout<<"Through Kadane's Algo : "<< KadaneAlgo(arr,size)<<endl;
    vector<int> startEnd = startEndOfMaxSubarray(arr,size);
    for(int i = 0; i<startEnd.size();i++){
        cout<<startEnd[i]<<" ";
    }

    return 0;
}