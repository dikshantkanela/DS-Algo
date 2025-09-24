#include<bits/stdc++.h>
using namespace std;

int power(int a , int b){
    // base cases
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
   
    // recursive call
    int ans = power(a,b/2);
    
    // solving small case
    if(b%2 == 0){
        return ans*ans;
    }

    else{
        return a*ans*ans;
    }
}



int main(){
    int a;
    cin>>a;
    int b;
    cin>>b;
    int pow = power(a,b);
    cout<<pow;

    return 0;
}