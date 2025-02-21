#include <bits/stdc++.h>
using namespace std;

bool isValid(char ch){
    if( (ch>='a' && ch<='z') || (ch>='0' && ch<='9') || (ch>='A' && ch<='Z')){
        return true;
    }
    return false;
}

char getLowerCase(char ch){
     if(ch>='a' && ch <='z'){ 
        return ch;
    }
    else{  
        return ch-'A'+'a';
    }
}

bool isPalindrome(string ch) {
    int n = ch.size();
    int start = 0;
    int end = n-1;

    while(start<=end){
        if(!isValid(ch[start])){
            start++;
            continue;
        }

        if(!isValid(ch[end])){
            end--;
            continue;
        }
        
        if(getLowerCase(ch[start]) == getLowerCase(ch[end])){
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
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (isPalindrome(s)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}
