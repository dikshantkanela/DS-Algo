#include<bits/stdc++.h>
using namespace std;
int getLength(char name[]){
    int len = 0;
    for(int i=0;name[i]!='\0'; i++){
        len++;  
    }
    return len;
}

int main(){
    // DECLARE : 
    char name[20] = "Dikshant Kanela"; //THIS WILL PARSE INTO {'D', 'i', 'k', 's', 'h', 'a', 'n', 't', '\0'}
    cout<< name<< endl;
    cout<<"Your name length is : "<< strlen(name)<<endl;
    // TAKE INPUT : 
    char city[20];
    cout<<"Enter City : ";
    cin>>city; // New Delhi
    // cin.getline(city,20); // New Delhi
    cout<<"You live in "<< city; //You live in New (If SPACE/TAB is encountered by cin it will add the \0 character and the string will stop there!)
    return 0;
}