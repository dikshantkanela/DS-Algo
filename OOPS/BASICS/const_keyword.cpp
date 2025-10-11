#include<bits/stdc++.h>
using namespace std;
int main(){
    // basic const usage with variables 
     
    int* const a = new int; // you can change the content of pointer but not the address
    *a = 10; // allowed
    // int dummy = 100;
    // a = &dummy; // not allowed!!

    const int *b = new int;  // you can change the address but not the inner content
    // int const* b = new int; // same as above
  
    // *b = 100;
    
    
    
    cout<<*b;
    
    
    return 0;
}