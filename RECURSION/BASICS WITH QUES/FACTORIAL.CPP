#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n*factorial(n-1);
}


int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int fact = factorial(n);
    cout<<"Factorial of " << n << " is " << fact;

    
    return 0;
}