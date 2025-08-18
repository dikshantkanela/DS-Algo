#include<bits/stdc++.h>
using namespace std;
int tempRoot(int n){
    int start = 0;
    int end = n; //not n-1 what if n = 0;
    long long int mid = start+(end-start)/2;
    int ans = -1;
    while(start<=end){
        long long int sq = mid*mid;

        if(sq>n){
           end = mid-1;
        }

        else if(sq<n){
            ans = mid; // COULD BE THE ROOT
            start = mid+1;
        }

        else{
            return mid;
        }
        mid = start+(end-start)/2;
    }
    return ans;

}

double precisionRoot(int n, int precision, int tempRoot){
    long double ans = tempRoot;
    double factor = 1;
    
    
    for(int i=0;i<precision;i++){
        long double sq = ans*ans;
       
        for(int i=0;i<precision;i++){
             factor = factor/10;
             while((ans+factor)*(ans+factor)<=n){
                 ans+=factor; 
             }
        }
    }
   
    return ans;

    
}


int main(){
    int n;
    int precision;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"Enter the precision : ";
    cin>>precision;
    int temp = tempRoot(n);
    cout<<"Integer part of root is : "<<tempRoot(n)<<endl;
    cout<<"Precision root is : "<<precisionRoot(n,precision,temp)<<endl;

    return 0;
}