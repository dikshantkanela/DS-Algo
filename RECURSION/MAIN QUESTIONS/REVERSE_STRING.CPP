#include<bits/stdc++.h>
using namespace std;

void getReverse(string &s1, int start, int end){

    // base case : 
    if(start>end){
         return; // stop where start exceeds stop
    }   
    // processing
    swap(s1[start],s1[end]);
    return getReverse(s1,start+1,end-1);
    // start++;
    // end--;
    // recursive call
    
    
}

int main(){
    string s1 = "Dikshant";
    getReverse(s1,0,s1.size()-1);
    cout<<s1;
    return 0;
}