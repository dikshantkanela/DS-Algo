#include<bits/stdc++.h>
using namespace std;

void sayDIgits(int n,unordered_map<int, string> digitMap){
    // base case

    if(n == 0){
        return;
    }
    int rem = n%10;
    n = n/10;
    sayDIgits(n,digitMap);
    cout<<digitMap[rem]<<" ";

    
}

int main(){
    int n;
    cout<<"Enter a number to be said : ";
    cin>>n;
     unordered_map<int, string> digitMap;

    digitMap[0] = "zero";
    digitMap[1] = "one";
    digitMap[2] = "two";
    digitMap[3] = "three";
    digitMap[4] = "four";
    digitMap[5] = "five";
    digitMap[6] = "six";
    digitMap[7] = "seven";
    digitMap[8] = "eight";
    digitMap[9] = "nine";
    sayDIgits(n,digitMap);
   

    return 0;
}