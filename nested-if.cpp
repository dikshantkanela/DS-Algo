#include<bits/stdc++.h>
using namespace std;
int main(){
    int age;
    cout<<"Enter your age:";
    cin>>age;
    if(age<18){
        cout<<"Not eligible for job";
    }

    else if(age<=57){
        if(age<=54){   //EXTRA CHECK IN THE SAME RANGE (18-54)
          cout<<"Eligible for job";
        }
        else{  // (55-57)
          cout<<"Eligible for job, but retirement soon";
        }  
    }

    else{
        cout<<"Retirement please!";
    }
    return 0;
}