#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    // 0 1 1 2 3 5 8
    cout<<"Enter the value of N : " ;
    cin>>n;
    int first = 0;
    int second = 1;
    int next;
    for(int i = 2; i<n; i++){ //first two are reserved!
        next = first + second; // 1+0
        first = second; 
        second = next;
    }
    cout<<next;
    return 0;
}