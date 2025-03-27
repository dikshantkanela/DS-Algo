#include<bits/stdc++.h>
using namespace std;

void printCounting(int n){
    if(n == 0){
        return ;
    }
    
    printCounting(n-1);
    cout<<n;
    

}
void reversePrintCounting(int n){
    if(n == 0){
        return ;
    }
    
    cout<<n;
    reversePrintCounting(n-1);
    

}

int main(){

    int n;
    cin>>n;
    printCounting(n);
    cout<<endl;
    reversePrintCounting(n);
    return 0;
}