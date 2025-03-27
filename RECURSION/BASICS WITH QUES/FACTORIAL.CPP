#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    // base case
    if(n == 0){
        return 1;
    }
    // int smallerProblem = factorial(n-1); // calling+result storing
    // int biggerProblem = n*smallerProblem;
    // return biggerProblem;
    return n * factorial(n-1);

}

int main(){
    int n;
    cin>>n;
    int res = factorial(n);
    cout<<res;
    return 0;
}