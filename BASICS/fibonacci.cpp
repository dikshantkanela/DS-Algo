#include<bits/stdc++.h>
using namespace std;
int main(){
    //FIBONACCI : 0 1 1 2 3 5
    int n;
    cout <<"Enter the value of n: ";
    cin>>n;
    int first = 0;
    int second = 1;
    int next;
    for(int i=0;i<n;i++){
       next = first+second;
       first = second;
       second = next;
       cout<<next<<" "; 
    }
    return 0;
}