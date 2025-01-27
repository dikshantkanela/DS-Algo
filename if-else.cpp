#include<bits/stdc++.h>
using namespace std;
int main(){
    int marks;
    cout<<"Enter marks : ";
    cin>>marks;
    // if(marks<25){
    //     cout<<"F";
    // }
    // else if(marks >= 25 && marks<=44){
    //     cout<<"E";
    // }

    // else if(marks>=45 && marks<=49){
    //      cout<<"D";
    // }
    // else if(marks>=50 && marks<=59){
    //      cout<<"C";
    // }
    
    // else if(marks>=60 && marks<=79){
    //      cout<<"B";
    // }
    // else if(marks>=80 && marks<=100){
    //      cout<<"A";
    // }
    //BETTER APPROACH : 
     if(marks<25){
        cout<<"F";
    }
    else if(marks<=44){
        cout<<"E";
    }

    else if(marks<=49){
         cout<<"D";
    }
    else if(marks<=59){
         cout<<"C";
    }
    
    else if(marks<=79){
         cout<<"B";
    }
    else if(marks<=100){
         cout<<"A";
    }
    
    return 0;
}