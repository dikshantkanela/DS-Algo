#include <bits/stdc++.h>
using namespace std;

char getLowerCase(char ch){
    if(ch>='a' && ch <='z'){ // NO NEED TO CHANGE IF IT IS LOWERCASE
        return ch;
    }

    else{ //CONVERSION OF UPPER TO LOWER : 
        return ch-'A'+'a';
    }
}
// Function to check palindrome using extra space
bool checkPalindrome(string s, int n){
    int start = 0;
    int end = n-1;

    while(start<=end){
        if(getLowerCase(s[start]) == getLowerCase(s[end])){
            start++;
            end--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main() {
    // Test Cases
    string test1 = "racecaR";
    int n = test1.size();
    cout << "Is " << test1 << " palindrome? " << (checkPalindrome(test1,n)?"Yes":"No");
    
    
    return 0;
}