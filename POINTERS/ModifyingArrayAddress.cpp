#include<bits/stdc++.h>
using namespace std;
int main(){
    int cars[10] = {21,32,43,54};
    int *ptr = cars;
    cout<< cars+1 <<endl ;
    ptr = ptr + 1;
    cout<<ptr<<endl;

    // cars = cars+1; // address reassigning not possible*
    // cout<<cars;
    return 0;
}