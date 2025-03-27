#include<bits/stdc++.h>
using namespace std;

void sayDIgits(int n,string arr[]){
    // base case
    if(n==0){
        return;
    }

    // processing
    int digit = n%10;
    n = n/10;
    

    // recursive call 
    sayDIgits(n,arr);
    cout<<arr[digit]<< " ";

    
}

int main(){
    int n;
    string numbersInWords[] = {
        "Zero", "One", "Two", "Three", "Four", 
        "Five", "Six", "Seven", "Eight", "Nine"
    };
    cout<<"Enter a number to be said : ";
    cin>>n;
    sayDIgits(n,numbersInWords);

    return 0;
}