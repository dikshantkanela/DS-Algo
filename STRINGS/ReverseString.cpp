#include<bits/stdc++.h>
using namespace std;
void getReverse(char name[], int n){
    int start = 0;
    int end = n-1;
    while(start<end){
        int temp = name[start];
        name[start] = name[end];
        name[end] = temp;
        start++;
        end--;
    }
}
int main(){
    char name[20] = "Dikshant";
    cout<<"Reverse of "<<name<<" "<<"is ";
    getReverse(name,8);
    cout<<name;
    return 0;
}