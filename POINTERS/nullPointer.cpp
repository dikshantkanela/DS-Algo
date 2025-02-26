#include<bits/stdc++.h>
using namespace std;
int main(){
      // null pointer : a pointer that is not initialised, it does not point to any location!
      int cars = 5;
      int *np = 0; // declaring a pointer (declaring means null pointer, since pointers are always initialised :) )
      // cout<<*np; // segmentation fault
      np = &cars; // very imp************ initialise a pointer
      
    return 0;
}