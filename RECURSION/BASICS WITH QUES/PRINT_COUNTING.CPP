#include<bits/stdc++.h>
using namespace std;

void printCounting(int n){
    if(n == 0){
        return ;
    }
    printCounting(n-1);
    cout<<endl;
    cout<<n; // since this line(s) will only start executing for every value of n ONLY AFTER n reaches 0 so 1 will be printed first!!
}

void reverseCounting(int n){
    if(n == 0){
        return;
    }

    cout<<n;
    cout<<endl;
    reverseCounting(n-1);
}


int main(){

    int n;
    cout<< "Enter a number : "; 
    cin>>n;
    printCounting(n);
    reverseCounting(n);
    
    return 0;
}