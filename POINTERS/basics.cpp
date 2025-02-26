#include<bits/stdc++.h>
using namespace std;
int main(){
    int num = 5;

    cout<<num<<endl;
    // ADDRESS OF num : 
    cout<< "Address of num is : "<< &num <<endl; //0x61ff0c

    // POINTERS STORE THE ADDRESS OF A VARIABLE
    int *ptr = &num; // ptr stores the address of num
    cout<< "Address of num is : "<< ptr <<endl; //0x61ff08
    cout<< "Value of num is : "<< *ptr<<endl; // DEREFERNCE OPERATOR GIVES YOU VALUE OF THE LOCATION POINTER IS POINTING TO
    // double (datatype) pointer
    double marks = 92.6;
    double *p = &marks;
    cout<< "Address of marks is : "<< p <<endl;
    cout<< "Value of marks is : "<< *p <<endl;
  
    return 0;
}