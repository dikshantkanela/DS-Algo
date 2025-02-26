#include<bits/stdc++.h>
using namespace std;
int main(){
    int num = 10;
    cout<<num<<endl;
    int a = num; // a IS A COPY NOT A REFERENCE TO num
    a++;
    cout<<num<<endl;

    int* ptr = &num;
    int test = *ptr + 3; // IT SAYS TAKE THE VALUE OF NUM AND ADD 3 TO IT

    cout<<test<<endl;
    cout<<num<<endl; // WILL NOT CHANGE

    test = (*ptr)++; // or ++*ptr this will update the value of num!
    cout<<num<<endl;
    // *ptr++ will not work! it will increment the pointer by 1 and then give garbage value in next cout line lol !
    // ++*ptr will work it will first give value then increment the value 
    int lol = 69;
    int *rofl = &lol;
    cout<<*rofl++<<endl; //69
    cout<<*rofl; // garbage value since the position of the pointer has increased by 4 bytes and now it points to some other location!

    return 0;
}