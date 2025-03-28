#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string &s1,int start, int end){
    if(start>end){
        return true;
    }
    
    if(s1[start] != s1[end]){
        return false;
    }
    else{
        return checkPalindrome(s1,start+1,end-1); // no need for start++ end--
    }
  

}

int main(){
    string s1 = "";
    cout<<checkPalindrome(s1,0,s1.size()-1);
    return 0;
}