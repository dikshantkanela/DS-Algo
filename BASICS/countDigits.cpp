#include<bits/stdc++.h>
using namespace std;
int main(){
    int number;
    cout<<"Enter the number : ";
    cin>>number;
    int count = 0;
    int rem;
    while(number>0){
        // rem = number%10;
        number = number/10;
        count++;
    }
    cout<<count;
    return 0;
}