#include<bits/stdc++.h>
using namespace std;

int powerOf2(int n){
    if(n == 0){ // base case : return 1 when we are having 0
        return 1;
    }
    
  /* int smallerProblem = powerOf2(n-1);
    int biggerProblem = 2*smallerProblem;
    return biggerProblem; */ 
    return 2*powerOf2(n-1); // recursive relation
};

int main(){
    int n;
    cin>>n;
    int res = powerOf2(n);
    cout<< res;
    return 0;
}