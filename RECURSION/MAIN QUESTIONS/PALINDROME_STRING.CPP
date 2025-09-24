#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string &s1,int start, int end){
    //base case
    if(start>end){
        return true;
    }
    
    //processing (solving one small case of comparing start and end elements)
    if(s1[start]!=s1[end]){
        return false;
    }


    else{
        start++;
        end--;
        // recursive call
        checkPalindrome(s1,start,end);
    }
}

int main(){
    string s1 = "Nitin";
    cout<<checkPalindrome(s1,0,s1.size()-1);
    return 0;
}