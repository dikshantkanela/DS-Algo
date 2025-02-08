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
    double factor = 1;
    double ans = tempRoot;
    for(double i=0;i<precision;i++){
        factor = factor/10; // 0.1 0.01 0.001

        double j = ans;
        while(j*j<n){
            ans = j; //could be the root
            j=j+factor;
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